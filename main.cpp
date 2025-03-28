/*
Author - Dominic Aidoo
Date - March 06, 2024
A program that either encrypts, decrypts, shows 26 different possibilities a message could
be decrypted or outputs the message with the most common words
*/

#include <iostream>
#include<string>
#include<vector>

using namespace std;
/*
A function that takes no arguments and encrypts a message. It encrypts the message based on
the shift and direction given by the user and outputs the message in all uppercase letters
*/
void encrypt(){
    int shift;
    char direction;
    string message;  //message that will be encrypted
    string encryptedMessage = "";
    
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    cout << "Enter shift (1-26): " << endl;
    cin >> shift;
    cout << "Enter direction (f or b): " << endl;
    cin >> direction;
    cout << "Enter message: " << endl;
    cin.ignore();
    getline(cin,message);

    // loop that makes every letter in the message to be encrypted uppercase 
    for (int i = 0; i < message.length(); ++i) {
        message[i] = toupper(message.at(i));
    }
    int currentShift = shift;
    // loop that checks to see if there is a special character which just outputs it out
    for (int i = 0; i < message.size(); ++i) {
        int curIndex = letters.find(message.at(i));
        if (!isalpha(message[i]) && (!isspace(message[i]))) {
                encryptedMessage += message[i];
                continue;
        }
        encryptedMessage += letters[(curIndex + currentShift) % 27];
        currentShift = (currentShift + curIndex + shift) % 27;
        
    }
    /*
    if-else statement to check the direction inputted by the user and if the direction
    is forward, it outputs the message normally but if the direction is backwards, it
    outputs the message backwards
    */
    if (direction == 'f'){
        cout << "Encrypted message: " << encryptedMessage;
    }
    else if (direction == 'b') {
        string reverse;
        for (int i = encryptedMessage.size() - 1; i >= 0; --i) {
            reverse += encryptedMessage[i];
        }
        cout << "Encrypted message: " << reverse;
    }
}

/*
A function that calculates the shift of the decryption of a message. It takes the shift
passed by reference and a letter. 
*/
char shiftCharacter(int &shift,char letter){
    int value = 0;
    /*
    if-else statement that makes space value 26 or else it subtracts 'A' from the letter
    to get the value. 
    */
    if (letter == ' ') {
        value = 26;
    }
    else {
        value = letter - 'A';
    }

    // calculates the shift for the decryption
    int changedShift = (value - shift + 27) % 27;
    shift = (changedShift + shift) % 27;
    if (changedShift == 26) {
        return ' ';
    }
    else {
        return changedShift + 'A';
    }
}

/*
A function that decrypts the message given by the user. It takes in the shift, message and
direction as arguments. 
*/
string decrypt(int shift,string message,char direction) {
    string decryptedMessage = "";

    // if statement that reverses the message if the direction is backwards
    if (direction == 'b') {
        string reverse;
        for (int i = message.size() - 1; i >= 0; --i) {
            reverse += message[i];
        }
        message = reverse;
    }

    // capitalizes every letter in the message
    for (int i = 0; i < message.size(); ++i) {
        message[i] = toupper(message[i]);
    }

    int currentShift = shift;

    /*
    Loop that either outputs a special character if there is one in the message or 
    decrypts every letter in the message
    */
    for(int i = 0; i < message.size(); ++i) {
        if (!isalpha(message[i]) && !isspace(message[i])) {
            decryptedMessage += message[i];
            //continue;
        }
        else {
            decryptedMessage += shiftCharacter(currentShift, message[i]);
            currentShift = (shift + currentShift) % 27;
        }
    }
    return decryptedMessage;
}

//Takes in a message and outputs 26 different decryption possiblities forwards and backwards
void decryptedPossibilities(string message){
    for (int i = 1; i < 27; ++i){
        cout << i << "f: " << decrypt(i, message, 'f') << endl;
        cout << i << "b: " << decrypt(i, message, 'b') << endl;
    }
}

/*
A function that checks all 52 possibilites for the decrypted message with the most common 
words and outputs that message
*/
void breakCode(string message){
    // loop that makes every letter uppercase
    for (int i = 0; i < message.length(); ++i) {
        message[i] = toupper(message.at(i));
    }
    int shift = 1;
    int backCount = 0;
    int maxIndex = 0;
    int maxCount = 0;
    int count = 0;
    vector<string>sentences;
    vector<int>highCount;
    vector<string>commonWords = {" THE ", " BE ", " TO ", " OF ", " AND ", " A ", " IN ",
     " THAT ", " HAVE ", " I "};
     /*
    loop that decrypts the message with all 52 possibilities and gets the count of the 
    sentence with most common words
     */
    for (int w = 0; w < 26; ++ w){
       string decryptedText = decrypt(shift, message, 'f');
       sentences.push_back(decryptedText);
       //loop that looks for every common word in the forward decrypted message
        for (int t = 0; t < commonWords.size(); ++t) {
            if (decryptedText.find(commonWords[t]) < 100) {
                count ++;
            }
        }
        highCount.push_back(count);
        count = 0;
        string decryptedBack = decrypt(shift, message, 'b');
        sentences.push_back(decryptedBack);
        // loop that looks for every common word in the backward decrypted message
        for (int r = 0; r < commonWords.size(); ++r) {
            if (decryptedBack.find(commonWords[r]) < 100) {
                backCount ++;
            }
        }
        highCount.push_back(backCount); 
        count = 0;
        // loop that gets the highest count of common words in the decrypted sentence
        for(int y = 0;  y < highCount.size(); ++y) {
            if (highCount[y] > maxCount) {
                maxCount = highCount[y];
                maxIndex = y;
            }
        }
        shift ++;
    }
    /*
    if-else statement that checks for the sentence with the same index as the maximum count 
    and outputs that sentence or outputs it was not able to find a decrypted message if 
    there were no sentences with common words
    */
     
    if (maxCount > 0) {
        cout << "Decrypted message is: " << sentences[maxIndex];
    }
    else {
        cout << "Unable to find a decrypted message." << endl;
    }
}

int main() 
{
    int choice;
    // Main message:
	cout << "1. Encrypt message" << endl;
	cout << "2. Decrypt message" << endl;
	cout << "3. Show decrypted possibilities" << endl;
	cout << "4. Break code" << endl;
	cout << "Enter choice: ";
    cin >> choice;
    /*
    if-else statements where if user chooses 1, the message encrypts. If 2, it decrypts.
    If 3, it outputs all the decrypted possiblities. If 4, it outputs the message with most
    common words.
    */    
    if (choice == 1){
        encrypt();
    }
    else if (choice == 2) {
        int shift;
        char direction;
        string message;
        string decryptMessage;
        cout << "Enter shift (1-26): " << endl;
        cin >> shift;
        cout << "Enter direction (f or b): " << endl;
        cin >> direction;
        cout << "Enter message: " << endl;
        cin.ignore();
        getline(cin,message);
        decryptMessage = decrypt(shift, message, direction);
        cout << " Decrypted message: " << decryptMessage << endl;

    }
    else if(choice == 3) {
        string message;
        cout << "Enter message: ";
        cin.ignore();
        getline(cin, message);
        decryptedPossibilities(message);
    }
    else if (choice == 4){
        string message;
        cout << "Enter message: ";
        cin.ignore();
        getline(cin, message);
        breakCode(message);
    }
}


