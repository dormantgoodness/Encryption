# Encryption and Decryption Program

## Overview
This C++ program allows users to encrypt and decrypt messages using a shift cipher. It provides multiple functionalities, including encryption, decryption, displaying all possible decryption options, and attempting to automatically break the encryption using common words.

## Features
- **Encrypt a Message**: The program takes a message, a shift value, and a direction to encrypt the text.
- **Decrypt a Message**: Users can input a shift value and a direction to decrypt an encrypted message.
- **Show Decryption Possibilities**: Displays all 26 possible shift variations in both forward and backward directions.
- **Break Code**: Attempts to automatically decrypt a message by analyzing common English words.

## How It Works
1. **Encryption**:
   - Converts the message to uppercase.
   - Shifts letters based on the given shift value.
   - Can encrypt in both forward ('f') and backward ('b') directions.

2. **Decryption**:
   - Takes an encrypted message and reverses the shift operation.
   - If the message was encrypted backward, it first reverses the string.

3. **Decryption Possibilities**:
   - Generates 26 variations of the decrypted message for both directions.

4. **Breaking the Code**:
   - Decrypts the message using all shift values.
   - Compares the results with common English words to determine the most likely original text.

## Usage
Compile the program using a C++ compiler, such as g++:
```sh
 g++ -o cipher cipher.cpp
```
Run the program:
```sh
 ./cipher
```
Follow the on-screen menu to select an option and input messages.

## Example
```
1. Encrypt message
2. Decrypt message
3. Show decrypted possibilities
4. Break code
Enter choice: 1
Enter shift (1-26): 3
Enter direction (f or b): f
Enter message: hello world
Encrypted message: KHOOR ZRUOG
```

## Requirements
- A C++ compiler (GCC, Clang, MSVC, etc.)
- Basic understanding of compiling and running C++ programs

## Future Enhancements
- Add support for punctuation and special characters
- Improve the automatic code-breaking algorithm
- Implement a graphical user interface (GUI)

