/*
Program: This program encrypts and decrypts messages using baconian, Simple Substitution and Morse code
         ciphers.
Author: George Youssef Roger
*/

#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<cctype>
#include<unordered_map>
using namespace std;
void main_menu();
void menu_encryption();
void menu_decryption();

// Function for Morse code encryption
void morse_encryption(string text) {
    map<char, string> morsecode;  // Map to store Morse code representations
    // Populate the map with letters and symbols and their Morse code
    morsecode['A'] = ".-";
    morsecode['B'] = "-...";
    morsecode['C'] = "-.-.";
    morsecode['D'] = "-..";
    morsecode['E'] = ".";
    morsecode['F'] = "..-.";
    morsecode['G'] = "--.";
    morsecode['H'] = "....";
    morsecode['I'] = "..";
    morsecode['J'] = ".---";
    morsecode['K'] = "-.-";
    morsecode['L'] = ".-..";
    morsecode['M'] = "--";
    morsecode['N'] = "-.";
    morsecode['O'] = "---";
    morsecode['P'] = ".--.";
    morsecode['Q'] = "--.-";
    morsecode['R'] = ".-.";
    morsecode['S'] = "...";
    morsecode['T'] = "-";
    morsecode['U'] = "..-";
    morsecode['V'] = "...-";
    morsecode['W'] = ".--";
    morsecode['X'] = "-..-";
    morsecode['Y'] = "-.--";
    morsecode['Z'] = "--..";
    morsecode['0'] = "-----";
    morsecode['1'] = ".----";
    morsecode['2'] = "..---";
    morsecode['3'] = "...--";
    morsecode['4'] = "....-";
    morsecode['5'] = ".....";
    morsecode['6'] = "-....";
    morsecode['7'] = "--...";
    morsecode['8'] = "---..";
    morsecode['9'] = "----.";
    morsecode['.'] = ".-.-.-";
    morsecode[','] = "--..--";
    morsecode['?'] = "..--..";
    morsecode['\''] = ".----.";
    morsecode['!'] = "-.-.--";
    morsecode['/'] = "-..-.";
    morsecode['('] = "-.--.";
    morsecode[')'] = "-.--.-";
    morsecode['&'] = ".-...";
    morsecode[':'] = "---...";
    morsecode[';'] = "-.-.-.";
    morsecode['='] = "-...-";
    morsecode['+'] = ".-.-.";
    morsecode['-'] = "-....-";
    morsecode['_'] = "..--.-";
    morsecode['"'] = ".-..-.";
    morsecode['$'] = "...-..-";
    morsecode['@'] = ".--.-.";
    string encryp_morse = "";
    for (int n = 0; n < text.length(); n++) {
        if (isspace(text[n])) {  // Check if the current character is a space
            encryp_morse += "   ";
        }
        else {  // If not a space, convert the character to uppercase and find its Morse code equivalent
            encryp_morse += morsecode[toupper(text[n])] + " ";
        }
    }
    encryp_morse += " ";
    cout << "Encrypted message: " << encryp_morse << endl;
    main_menu();
}


// Function for Morse code decryption
void morse_decryption(string morse) {
    map<string, char> morsecode;  // Map to store Morse code representations
    // Populate the map with Morse code and its letters and symbols
    morsecode[".-"] = 'A';
    morsecode["-..."] = 'B';
    morsecode["-.-."] = 'C';
    morsecode["-.."] = 'D';
    morsecode["."] = 'E';
    morsecode["..-."] = 'F';
    morsecode["--."] = 'G';
    morsecode["...."] = 'H';
    morsecode[".."] = 'I';
    morsecode[".---"] = 'J';
    morsecode["-.-"] = 'K';
    morsecode[".-.."] = 'L';
    morsecode["--"] = 'M';
    morsecode["-."] = 'N';
    morsecode["---"] = 'O';
    morsecode[".--."] = 'P';
    morsecode["--.-"] = 'Q';
    morsecode[".-."] = 'R';
    morsecode["..."] = 'S';
    morsecode["-"] = 'T';
    morsecode["..-"] = 'U';
    morsecode["...-"] = 'V';
    morsecode[".--"] = 'W';
    morsecode["-..-"] = 'X';
    morsecode["-.--"] = 'Y';
    morsecode["--.."] = 'Z';
    morsecode["-----"] = '0';
    morsecode[".----"] = '1';
    morsecode["..---"] = '2';
    morsecode["...--"] = '3';
    morsecode["....-"] = '4';
    morsecode["....."] = '5';
    morsecode["-...."] = '6';
    morsecode["--..."] = '7';
    morsecode["---.."] = '8';
    morsecode["----."] = '9';
    morsecode[".-.-.-"] = '.';
    morsecode["--..--"] = ',';
    morsecode["..--.."] = '?';
    morsecode["-.-.--"] = '!';
    morsecode["-....-"] = '-';
    morsecode["-..-."] = '/';
    morsecode[".----."] = '\'';
    morsecode["-..-.-"] = '=';
    morsecode["-.--."] = '(';
    morsecode["-.--.-"] = ')';
    morsecode[".-..."] = '&';
    morsecode ["---..."] = ':';
    morsecode [".-.-."] = '+';
    morsecode ["..--.-"] = '_';
    morsecode [".-..-."] = '"';
    morsecode ["...-..-"] = '$';
    morsecode [".--.-."] = '@';
    string letter = "";
    string decryp_morse = "";
    for (int i = 0; i <= morse.length(); i++) {
        if (!isspace(morse[i]) && i < morse.length()) {  // Check if the current character is a space
            letter += morse[i];
        }
        else if (!letter.empty()) {
            decryp_morse += morsecode[letter];
            letter = "";
        }
        else {
            decryp_morse += ' ';
        }
    }
    cout << "Decrypted message: " << decryp_morse << "\n";
    main_menu();
}


// Function to convert a character to its Baconian code
string char_to_baconian(char c) {
    string baconian_code = "";
    c = tolower(c);
    int index = c - 'a';
    for (int i = 0; i < 5; i++) {
        baconian_code += (index & (1 << (4 - i))) ? 'B' : 'A';
    }
    return baconian_code;
}


// Function to convert a Baconian code to its character
char baconian_to_char(const string& baconian_code) {
    if (baconian_code.length() != 5) {
        return ' '; // Invalid code length
    }
    int index = 0;
    for (int i = 0; i < 5; i++) {
        if (baconian_code[i] == 'B') {
            index += (1 << (4 - i));
        }
    }
    return index + 'a';
}


// Function for Baconian encryption
void baconian_encryption(const string& text) {
    string encryp_baconian = "";
    for (char c : text) {
        if (isalpha(c)) {
            string baconian_code = char_to_baconian(tolower(c));
            encryp_baconian += baconian_code + " ";
        }
        else if (isdigit(c)) {
            encryp_baconian += c; // Include numbers as they are
        }
        else {
            encryp_baconian += " "; // Handle non-alphabetic characters
        }
    }
    cout << "Encrypted text in Baconian: " << encryp_baconian << endl;
    main_menu();
}


// Function for Baconian decryption
void baconian_decryption(const string& baconian) {
    string decryp_baconian = "";
    string baconian_code = "";
    for (char c : baconian) {
        if (c == ' ') {
            if (!baconian_code.empty()) {
                decryp_baconian += baconian_to_char(baconian_code);
                baconian_code = "";
            }
            else {
                decryp_baconian += " "; // Add space for each space in the input
            }
        }
        else if (isdigit(c)) {
            decryp_baconian += c; // Include numbers as they are
        }
        else {
            baconian_code += c;
        }
    }
    if (!baconian_code.empty()) {
        decryp_baconian += baconian_to_char(baconian_code);
    }
    cout << "Decrypted text in Baconian: " << decryp_baconian << endl;
    main_menu();
}


// Function to cipher alphabet based on the key
string Substitution(string key) {
    unordered_map<char, bool> key_alpha;
    string en_alpha = key;
    for (char i : key) {
        key_alpha[i] = true;
    }
    // Add the rest of the characters to the ciphered alphabet
    for (char i = 'a'; i <= 'z'; i++) {
        if (!key_alpha[i]) {
            en_alpha.push_back(i);
        }
    }
    return en_alpha;
}


// Function for Simple Substitution encryption
void simple_encryption(string text, string en_alpha) {
    string encryp_simple = "";
    for (char c : text) {
        if (isalpha(c)) {
            char replace = tolower(en_alpha[tolower(c) - 'a']);
            encryp_simple += replace;
        }
        else {
            encryp_simple += c; // Keep non-alphabetic characters unchanged
        }
    }
    cout << "Encrypted text in Simple Substitution: " << encryp_simple << endl;
    main_menu();
}


// Function for Simple Substitution decryption
void simple_decryption(string simple, string en_alpha) {
    string decryp_simple = "";
    // Inverse mapping to decrypt the simple
    unordered_map<char, char> de_alpha;
    for (int i = 0; i < 26; i++) {
        de_alpha[en_alpha[i]] = 'a' + i;
        de_alpha[toupper(en_alpha[i])] = 'A' + i;
    }
    // Decrypt the simple
    for (char c : simple) {
        if (isalpha(c)) {
            decryp_simple += de_alpha[c];
        }
        else {
            decryp_simple += c; // Keep non-alphabetic characters unchanged
        }
    }
    cout << "Decrypted text in Simple Substitution: " << decryp_simple << endl;
    main_menu();
}


// Menu of decryption method
void menu_decryption() {
    string decryp_text;
    cout << "Enter your message:";
    cin.ignore();
    getline(cin,decryp_text);
    string choice;
    cout << "===== Choose the Cipher =====\n1) Baconian\n2) Simple Substitution\n3) Morse Code\n";
    cout << "Enter your choice ==>";
    cin >> choice;
    if (choice == "1") {
        baconian_decryption(decryp_text);
    }
    else if (choice == "2") {
        string key;
        cout << "Enter the key for Simple Substitution decryption:";
        cin >> key;
        while (key.length() != 5) {
            cout << "Error! Key must be exactly 5 unique letters.\nEnter the key:";
            cin >> key;
        }
        string en_alpha = Substitution(key);
        simple_decryption(decryp_text, en_alpha);
    }
    else if (choice == "3") {
        morse_decryption(decryp_text);
    }
    else {
        cout << "\nError! Enter a valid choice\n";
        return menu_decryption();
    }
}


// Menu of encryption method
void menu_encryption() {
    string encryp_text;
    cout << "Enter your message:";
    cin.ignore();
    getline(cin,encryp_text);
    string choice;
    cout << "===== Choose the Cipher =====\n1) Baconian\n2) Simple Substitution\n3) Morse Code\n";
    cout << "Enter your choice ==>";
    cin >> choice;
    if (choice == "1") {
        baconian_encryption(encryp_text);
    }
    else if (choice == "2") {
        string key;
        cout << "Enter the key for Simple Substitution encryption:";
        cin >> key;
        while (key.length() != 5) {
            cout << "Error! Key must be exactly 5 unique letters.\nEnter the key:";
            cin >> key;
        }
        string en_alpha = Substitution(key);
        simple_encryption(encryp_text, en_alpha);
    }
    else if (choice == "3") {
        morse_encryption(encryp_text);
    }
    else {
        cout << "\nError! Enter a valid choice\n";
        menu_encryption();
    }
}


// Main Menu
void main_menu(){
    string choice;
    cout << "\n===== Main Menu =====\n1) Encryption\n2) Decryption\n3) Exit\n";
    cout << "Enter your choice ==>";
    cin >> choice;
    if (choice == "1") {
        menu_encryption();
    }
    else if (choice == "2") {
        menu_decryption();
    }
    else if (choice == "3") {
        exit(0);
    }
    else {
        cout << "\nError! Enter a valid choice\n";
        main_menu();
    }
}

int main() {
    cout << "Welcome to the Cryptography Program!";
    main_menu();
    return 0;
}