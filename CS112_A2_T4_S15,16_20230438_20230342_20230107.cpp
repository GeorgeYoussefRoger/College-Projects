// File: CS112_A2_T4_S15,16_20230438_20230342_20230107
// Purpose: This program can encrypt and decrypt messages using ten types of ciphers (Affine, Route, Atbash, Vigenere,
//          Baconian, Simple Substitution, Polybuis, Morse, XOR, Rail-fence)
// Authors: Mina Maher Tawfik (20230438) made ciphers no. (7, 9, 10)
//          Mohamed Adel Kamal (20230342) made ciphers no. (1, 2, 3, 4)
//          George Youssef Roger (20230107) made ciphers no. (5, 6, 8)
//
// Section NO.: 15,16
// Emails: George Youssef => georgeroger35@gmail.com
//         Mina Maher => mina005smart@gmail.com
//         Mohamed Adel => ma8346999@gmail.com


#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<map>
#include<cctype>
#include<regex>
#include<algorithm>
#include<unordered_map>
using namespace std;
void main_menu();
void menu_encryption();
void menu_decryption();

// Function to check if the input consists only of alphabetic characters and spaces
bool affine_checker(const string & input) {
    for (char c : input) {
        if (!isalpha(c) && c != ' ') {
            return false; // Return false if any character is not alphabetic or a space
        }
    }
    return true; // Return true if all characters are alphabetic or spaces
}


// Function for Affine encryption
void affine_encryption(string & str, int a, int b, int c) {
    int strLength = str.length();
    for (int i = 0; i < strLength; i++) {
        if (str[i] != ' ') {
            if ((a * c) % 26 == 1) {
                str[i] = ((a * toupper(str[i]) + b - 'A') % 26) + 'A'; // Encrypt uppercase letters
            }
        }
    }
    cout << "Encrypted text in Affine: " << str << endl;
    main_menu();
}


// Function for Affine decryption
void affine_decryption(string & str, int a, int b, int c) {
    int strLength = str.length();
    for (int i = 0; i < strLength; i++) {
        if (str[i] != ' ') {
            if ((a * c) % 26 == 1) {
                int decrypted = ((c * (toupper(str[i]) - 'A' - b)) % 26 + 26) % 26;
                str[i] = decrypted + 'A'; // Decrypt uppercase letters
            }
        }
    }
    cout << "Decrypted text in Affine: " << str << endl;
    main_menu();
}


string removeNonAlphaNum(string str) {
    str.erase(remove_if(str.begin(),str.end(),[](char c){return !isalpha(c);}),str.end());
    return str;
}


// Function for Route encryption
void route_encryption(string message) {
    message = removeNonAlphaNum(message);
    transform(message.begin(), message.end(), message.begin(), ::toupper);

    string part1, part2, part3;
    int x = 0, y = 1, z = 2;

    while (message.length() != 0) {
        part1 += message[x];
        part2 += message[y];
        part3 += message[z];
        message.erase(x, 3);
    }

    char lastLetter = part2.back();
    part3 += lastLetter;
    part2.pop_back();

    string repart1 = part1;
    reverse(repart1.begin(), repart1.end());

    cout << "Encrypted text in route: " << part3 + repart1 + part2 << endl;
    main_menu();
}


// Function for Route decryption
void route_decryption(string message) {
    message = removeNonAlphaNum(message);
    transform(message.begin(), message.end(), message.begin(), ::toupper);

    string part1, part2, part3;
    int length = message.length();

    if (length == 5) {
        part3 = message.substr(0, 1);
        part1 = message.substr(1, 1);
        part2 = message.substr(2, 1);
    }
    else {
        int parts = length / 3;
        int z = length % 3;

        if (z == 0) {
            part2 = message.substr(length - parts, parts);
            message.erase(length - parts, parts);
            part3 = message.substr(0, parts);
            message.erase(0, parts);
        }
        else {
            int ceilZ = (length + 2) / 3;
            int floorZ = length / 3;
            int closerZ = (abs(length - ceilZ * 3) < abs(length - floorZ * 3)) ? ceilZ : floorZ;

            part3 = message.substr(0, closerZ);
            message.erase(0, closerZ);
            part2 = message.substr(message.length() - closerZ, closerZ);
            message.erase(message.length() - closerZ, closerZ);
        }

        reverse(message.begin(), message.end());
        part1 = message;
    }

    swap(part1.front(), part1.back());
    swap(part2.front(), part2.back());

    cout << "Decrypted text in route: " << part1 + part2 + part3 << endl;
    main_menu();
}


// Encryption of alphabetical divided into two halves
string atbashCipher(string text) {
    // Repeat until valid string input is provided
    while (true) {
        bool isValid = true;
        for (char c : text) {
            if (!isalpha(c)) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            break; // Exit the loop if the input is valid
        }
        else {
            cout << "Error! The input must contain only alphabetic characters." << endl;
            cout << "Enter your message:";
            cin.ignore();
            getline(cin, text);
        }
    }
    string plainAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cipherAlphabetFirstHalf = "MLKJIHGFEDCBA";
    string cipherAlphabetSecondHalf = "ZYXWVUTSRQPON";
    // Add a space between the two halves
    string reversedAlphabet = cipherAlphabetFirstHalf + " " + cipherAlphabetSecondHalf;
    for (char &c : text) {
        if (isupper(c)) {
            size_t index;
            if ((index = plainAlphabet.find(c)) != string::npos) {
                if (index <= 12) {
                    c = cipherAlphabetFirstHalf[index];
                }
                else {
                    c = cipherAlphabetSecondHalf[index - 13];
                }
            }
        }
    }
    return text;
}


// Decryption of alphabetical divided into two halves
string atbashDeCipher(string text) {
    // Repeat until valid string input is provided
    while (true) {
        bool isValid = true;
        for (char c : text) {
            if (!isalpha(c)) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            break; // Exit the loop if the input is valid
        }
        else {
            cout << "Error! The input must contain only alphabetic characters." << endl;
            cout << "Enter your message:";
            cin >> text;
        }
    }
    string plainAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cipherAlphabetFirstHalf = "MLKJIHGFEDCBA";
    string cipherAlphabetSecondHalf = "ZYXWVUTSRQPON";
    for (char & c : text) {
        if (isupper(c)) {
            size_t index;
            if ((index = cipherAlphabetFirstHalf.find(c)) != string::npos) {
                c = plainAlphabet[index];
            }
            else if ((index = cipherAlphabetSecondHalf.find(c)) != string::npos) {
                c = plainAlphabet[index + 13];
            }
        }
    }
    return text;
}


// Function for Atbash encryption
void atbash_encryption(string message) {
    // Repeat until valid string input is provided
    while (true) {
        // Check if the input contains only alphabetical characters or spaces
        bool isValid = true;
        for (char c : message) {
            if (!isalpha(c) && c != ' ') {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            break; // Exit the loop if the input is valid
        }
        else {
            cout << "Error! The input must contain only alphabetic characters or spaces." << endl;
            cout << "Enter your message:";
            cin.ignore();
            getline(cin, message);
            cout << endl;
        }
    }
    // Message to upper case
    for (int i = 0; i < message.length(); i++ ) {
        message[i] = toupper(message[i]);
    }
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string reversealpha = "";
    for (int i = alpha.length()-1; i > -1; i--) {
        reversealpha += alpha[i];
    }
    string EncryText = "";
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == ' ') {
            EncryText += " ";
        }
        else {
            for (int j = 0; j < alpha.length(); j++) {
                if (message[i] == alpha[j]) {
                    EncryText += reversealpha[j];
                    break;
                }
            }
        }
    }
    cout << "Encrypted text in Atbash: " << EncryText << endl;
    main_menu();
}


// Function for Atbash decryption
void atbash_decryption(string message) {
    cout << "Enter your message: ";
    // Repeat until valid string input is provided
    while (true) {
        // Check if the input contains only alphabetical characters or spaces
        bool isValid = true;
        for (char c : message) {
            if (!isalpha(c) && c != ' ') {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            break; // Exit the loop if the input is valid
        } else {
            cout << "Error! The input must contain only alphabetic characters or spaces." << endl;
            cout << "Enter your message:";
            cin.ignore();
            getline(cin, message);
        }
    }
    // Message to upper case
    for (int i = 0; i < message.length(); i++ ) {
        message[i] = toupper(message[i]);
    }
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string reversealpha = "";
    for (int i = alpha.length()-1; i > -1; i--) {
        reversealpha += alpha[i];
    }
    string dencryText = "";
    for(int i = 0; i < message.length(); i++){
        if(message[i] == ' '){
            dencryText += " ";
        } else {
            for (int j = 0; j < alpha.length(); j++) {
                if (message[i] == alpha[j]) {
                    dencryText += reversealpha[j];
                    break;
                }
            }
        }
    }
    cout << "Decrypted text in Atbash: " << dencryText << endl;
    main_menu();
}


//Checks if the string only contain alphabets
bool vigenere_checker(string text) {
    for (int i=0; i<text.length(); i++) {
        if (!isalpha(text[i])) {
            return false;
        }
    }
    return true;
}


// Returns the index of where the letter is from the original alphabet
int findShift(char c) {
    const string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (islower(c)) {
        c = toupper(c);
    }
    for (int i=0; i < Alphabet.length(); i++) {
        if (c == Alphabet[i]){
            return i;
        }
    }
    return 0;
}


// Encrypts a letter according to shift
char encrypt(char inputWord, int shift){
    if (!isalpha(inputWord)){
        return inputWord;
    }
    char c;
    if (isupper(inputWord)) {
        c = inputWord + shift;
        if (c > 'Z') {
            c -= 26;
        }
    }
    else {
        c = inputWord + shift;
        if (c > 'z'){
            c -= 26;
        }
    }
    return c;
}


// Decrypts a letter according to shift
char decrypt(char inputWord, int shift){
    if (!isalpha(inputWord)){
        return inputWord;
    }
    char c;
    if (isupper(inputWord)){
        c = inputWord - shift;
        if (c < 'A'){
            c += 26;
        }
    }
    else {
        c = inputWord - shift;
        if (c < 'a'){
            c += 26;
        }
    }
    return c;
}


// Function for Vigenere encryption
string vigenere_encryption(string key, string inputWord) {
    string res;
    int k = 0;
    for (int i=0;i<inputWord.length();i++){
        char currentChar = inputWord[i];
        int shift = findShift(key[k]);
        res += encrypt(currentChar, shift);
        k = (k + 1) % key.length();
    }
    cout << "Encrypted text in Vigenere: " << res << endl;
    main_menu();
}


// Function for Vigenere decryption
string vigenere_decryption(string key, string inputWord) {
    string res;
    int k = 0;
    for (int i=0;i<inputWord.length();i++){
        char currentChar = inputWord[i];
        int shift = findShift(key[k]);
        res += decrypt(currentChar,shift);
        k = (k + 1) % key.length();
    }
    cout << "Decrypted text in Vigenere: " << res << endl;
    main_menu();
}


// Function to convert a character to its Baconian code
string char_to_baconian(char c) {
    c = tolower(c);
    if (!isalpha(c)) {
        return "";
    }
    int index = c - 'a';
    string code = "";
    for (int i = 0; i < 5; i++) {
        code += (index & (1 << (4 - i))) ? 'B' : 'A';
    }
    return code;
}


// Function to convert a Baconian code to its character
char baconian_to_char(const string& code) {
    if (code.length() != 5) {
        return ' '; // Invalid code length
    }
    int index = 0;
    for (int i = 0; i < 5; i++) {
        if (code[i] == 'B') {
            index += (1 << (4 - i));
        }
    }
    return index + 'a';
}


// Function for Baconian encryption
string baconian_encryption(const string& message) {
    string encryptedMessage = "";
    for (char c : message) {
        string baconianCode = char_to_baconian(c);
        if (!baconianCode.empty()) {
            encryptedMessage += baconianCode + " ";
        }
    }
    cout << "Encrypted text in Baconian: " << encryptedMessage << endl;
    main_menu();
}


// Function for Baconian decryption
string baconian_decryption(const string& encryptedMessage) {
    string decryptedMessage = "";
    string code = "";
    for (char c : encryptedMessage) {
        if (c == ' ') {
            if (!code.empty()) {
                decryptedMessage += baconian_to_char(code);
                code = "";
            }
        } else {
            code += c;
        }
    }
    if (!code.empty()) {
        decryptedMessage += baconian_to_char(code);
    }
    cout << "Decrypted text in Baconian: " << decryptedMessage << endl;
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
string simple_encryption(string message, string en_alpha) {
    string result = "";
    for (char c : message) {
        if (isalpha(c)) {
            char replace = tolower(en_alpha[tolower(c) - 'a']);
            result += replace;
        }
        else {
            result += c; // Keep non-alphabetic characters unchanged
        }
    }
    cout << "Encrypted text in Simple Substitution: " << result << endl;
    main_menu();
}


// Function for Simple Substitution decryption
string simple_decryption(string message, string en_alpha) {
    string result = "";
    // Inverse mapping to decrypt the message
    unordered_map<char, char> de_alpha;
    for (int i = 0; i < 26; i++) {
        de_alpha[en_alpha[i]] = 'a' + i;
        de_alpha[toupper(en_alpha[i])] = 'A' + i;
    }
    // Decrypt the message
    for (char c : message) {
        if (isalpha(c)) {
            result += de_alpha[c];
        }
        else {
            result += c; // Keep non-alphabetic characters unchanged
        }
    }
    cout << "Decrypted text in Simple Substitution: " << result << endl;
    main_menu();
}


// Function to convert plain text to hexadecimal
string string_to_hex(const string & input) {
    stringstream output;
    output << hex << setfill('0');
    for (auto & c : input) {
       output << setw(2) << (int)(unsigned char)c;
    }
    return output.str();
}


// Function to convert hexadecimal to plain text
string hex_to_string(string encrythexa) {
    string encrypt_plain_text = "";
    for (size_t i = 0; i < encrythexa.length(); i += 2) {
        string part = encrythexa.substr(i, 2);  // Extract two characters from hexadecimal string
        char ch = stoul(part, nullptr, 16);  // Change it into base 16 and typecast as a character
        encrypt_plain_text += ch;  // Add this character to the final plain text
        }
        return encrypt_plain_text;
}


// Function for XOR encryption
void xor_encryption(string text,string keye_nxryption) {
    int i;
    int n = text.length();
    string encryp_text = "";
    string texthex = "";
    for (int j = 0; j < n; j++) {
        char tes = keye_nxryption[i];
        int i = j % (keye_nxryption.length());
        int ascii = text[j];
        int xoroper = ascii ^ (int(tes));
        char CH = char(xoroper);
        encryp_text += char(xoroper);
        encryp_text += " ";
        texthex += string_to_hex(string(&CH, 1)) + " ";
    }
    cout << "Encrypted text in XOR: " << encryp_text << "\n";
    cout << "The Hexadecimal representation of the Encrypted Code is: " << texthex << "\n";
    main_menu();
}


// Function for XOR decryption
void xor_decryption(string input, string keydecrpt){
    int i;
    string choice;
    string decrypttext;
    string ctext;
    cout << "What type of input will you enter ?\n1) Hexainput\n2) Plain text\n";
    cin >> choice;
    if (choice == "1") {
        for (int i=0; i < input.length(); i++) {
            if (isspace(input[i])) {
                input.erase(i--, 1);
            }
            if ((input[i] >= 'A' && input[i] <= 'F') || (input[i] >= 'a' && input[i] <= 'f') || isdigit(input[i])) {
                continue;
            }
            else {
                cout << "Error! Please enter a valid input\n";
                xor_decryption(input,keydecrpt);
            }
        }
       decrypttext = hex_to_string(input);
    }
    else if (choice == "2") {
        decrypttext = input;
    }
    else {
        cout << "Error! Please enter a valid choice\n";
        xor_decryption(input,keydecrpt);
    }
    for (int j = 0; j < decrypttext.length(); j++) {
        char tes = keydecrpt[i];
        int i = j%(keydecrpt.length());
        int ascii = decrypttext[j];
        int xoroper = ascii^(int(tes));
        char CH = char(xoroper);
        ctext += char(xoroper);
        ctext += " ";
    }
    cout << "Decrypted text in XOR: " << ctext << "\n";
    main_menu();
}


// Function for Morse code encryption
void morse_encryption(string x) {
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
    string morsetext = "";
    for (int n = 0; n < x.length(); n++) {
        if (isspace(x[n])) {  // Check if the current character is a space
        morsetext += "   ";
        }
        else {  // If not a space, convert the character to uppercase and find its Morse code equivalent
        morsetext = morsetext + morsecode[toupper(x[n])] + " ";
        }
    }
    morsetext+=" ";
    cout << "Encrypted text in Morse: " << morsetext << "\n";
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
    string decryp = "";
    for (int i = 0; i <= morse.length(); i++) {
        if (!isspace(morse[i]) && i < morse.length()) {  // Check if the current character is a space
            letter += morse[i];
        }
        else if (!letter.empty()) {
            decryp += morsecode[letter];
            letter = "";
        }
        else {
            decryp += ' ';
        }
    }
    cout << "Decrypted text in Morse: " << decryp << "\n";

    main_menu();
}


// Function for Polybuis decryption
void polybuis_decryption(string decrypt_text) {
    string string_to_int;
    string original_text;
    decrypt_text.erase(remove(decrypt_text.begin(),decrypt_text.end(),' '),decrypt_text.end());
    if (decrypt_text.empty()) {
        cout << "Error! The ciphered text is empty." << endl;
        return;
    }

    regex pattern("^[0-9]+$");
    if (!regex_match(decrypt_text, pattern)) {
        cout << "Error! The ciphered text contains non-digit characters." << endl;
        menu_decryption();
    }

    string key;
    cout << "Enter a 5-digit key: ";
    cin >> key;
    key.erase(remove(key.begin(), key.end(), ' '), key.end());

    regex pattern_2("^[0-9]{1,5}$");
    if (!regex_match(key, pattern_2)) {
        cout << "Error! The input should be a 5-digit number or less." << endl;
        polybuis_decryption(decrypt_text);
    }
    char z[5][5] = { {'A', 'B', 'C', 'D', 'E'},
                     {'F', 'G', 'H', 'J', 'K'},
                     {'L', 'M', 'N', 'O', 'P'},
                     {'Q', 'R', 'S', 'T', 'U'},
                     {'V', 'W', 'X', 'Y', 'Z'} };
    for (int i = 0; i < decrypt_text.length(); i++) {
        if (decrypt_text[i] == key[0]) {
            string_to_int += '1';
        }
        if (decrypt_text[i] == key[1]) {
            string_to_int += '2';
        }
        if (decrypt_text[i] == key[2]) {
            string_to_int+= '3';
        }
        if (decrypt_text[i] == key[3]) {
            string_to_int += '4';
        }
        if (decrypt_text[i] == key[4]) {
            string_to_int += '5';
        }
    }
    for (int i = 0; i < string_to_int.length() - 1;) {
        int x = string_to_int[i] - '0';
        int y = string_to_int[i + 1] - '0';
        original_text += z[x - 1][y - 1];
        i += 2;
    }
    cout << original_text << endl;
    main_menu();
}


// Function for Polybuis encryption
void polybuis_encryption (string x) {
    string filling_sentence = "";
    string decrypted = "";
    x.erase(remove(x.begin(), x.end(), ' '), x.end());
    regex pattern1("^[a-zA-Z]+$");
    smatch match;
    if (regex_match(x, match, pattern1)) {
        for (int i=0;i<x.length();i++) {
            x[i] = toupper(x[i]);
            if(x[i]=='I'){
                x[i]='J';
            }
        }
    }
    else {
        cout << "Error! Enter a valid input";
        menu_encryption();
    }
    cout << "\nEnter the key:";
    string key;
    getline(cin,key);
    key.erase(remove(key.begin(), key.end(), ' '), key.end());
    regex pattern2(R"(^\d{5}$)");

    if(!regex_match(key,pattern2)) {
        cout << "Error! Enter a valid key." << endl;
        polybuis_encryption(x);
    }
    char z[5][5] = {{'A', 'B', 'C', 'D', 'E'},
                    {'F', 'G', 'H', 'J', 'K'},
                    {'L', 'M', 'N', 'O', 'P'},
                    {'Q', 'R', 'S', 'T', 'U'},
                    {'V', 'W', 'X', 'Y', 'Z'} };
    for (int i=0; i<x.length(); i++) {
        for (int j=0; j<5; j++) {
            for (int k=0; k<5; k++) {
                if (x[i] == z[j][k]) {
                    filling_sentence += to_string(j+1);
                    filling_sentence += to_string(k+1);
                }
            }
        }
    }
    for (int i = 0; i < filling_sentence.length(); i++) {
        switch (filling_sentence[i]) {
            case '1': decrypted += key[0]; break;
            case '2': decrypted += key[1]; break;
            case '3': decrypted += key[2]; break;
            case '4': decrypted += key[3]; break;
            case '5': decrypted += key[4]; break;
        }
    }
    cout << decrypted << endl;
    main_menu();
}


// Function for Rail fence encryption
void railfence_encryption(string x){
    string first = "";
    string second = "";
    string third = "";
    for (int i = 0; i < x.length(); i++) {
        if (i % 4 == 0) {
            first += x[i];
        } else if (i % 2 == 1) {
            second += x[i];
        } else {
            third += x[i];
        }
    }
    cout << first << second << third << endl;
    main_menu();
}


// Function for Rail fence decryption
void railfence_decryption(string cipher) {
    vector<vector<char>> rail(3, vector<char>(cipher.length(), '\n'));
    bool dir_down;
    int row = 0, col = 0;
    for (int i = 0; i < cipher.length(); i++) {
        if (row == 0)
            dir_down = true;
        if (row == 3 - 1)
            dir_down = false;
        rail[row][col++] = '*';
        dir_down ? row++ : row--;
    }
    int index = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < cipher.length(); j++)
            if (rail[i][j] == '*' && index < cipher.length())
                rail[i][j] = cipher[index++];
    string result;

    row = 0, col = 0;
    for (int i = 0; i < cipher.length(); i++) {
        if (row == 0)
            dir_down = true;
        if (row == 3 - 1)
            dir_down = false;
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);
        dir_down ? row++ : row--;
    }
    cout << result << endl;
    main_menu();
}


// Menu of decryption method
void menu_decryption() {
    string decryp_text;
    cout << "Enter your message:";
    cin.ignore();
    getline(cin,decryp_text);
    string choice;
    cout << "===== Choose the Cipher =====\n1) Affine\n2) Route\n3) Atbash\n4) Vignere\n5) Baconian\n";
    cout << "6) Simple Substitution\n7) Polybius Square\n8) Morse Code\n9) XOR\n10) Rail-fence\n";
    cin >> choice;
    if (choice == "1") {
        if (!affine_checker(decryp_text)) {
            cout << "Error! The input must contain only alphabetic characters and spaces." << endl;
            menu_decryption();
        }
        int a, b, c;
        a = 5; // These are the parameters introduced in the problem sheet
        b = 8;
        c = 21;
        affine_decryption(decryp_text, a, b, c);
    }
    else if (choice == "2") {
        route_decryption(decryp_text);
    }
    else if (choice =="3" ) {
        cout << "1. Decrypt alphabet\n";
        cout << "2. Decrypt alphabet divided into two halves\n";
        string atbashdechoice;
        cin >> atbashdechoice;
        if (atbashdechoice == "1") {
            atbash_decryption(decryp_text);
        }
        else if (atbashdechoice == "2") {
            cout << "Decrypted text in Atbash: " << atbashDeCipher(decryp_text) << endl;
            main_menu();
        }
        else {
            cout << "Error! Enter a valid choice\n" << endl;
            return menu_decryption();
        }
    }
    else if (choice == "4") {
        string key;
        cout << "Enter the the key you want to decrypt with:";
        cin >> key;
        while (true) {
            if (vigenere_checker(key)) {
                break;
            }
            else {
                cin >> key;
            }
        }
        vigenere_decryption(key, decryp_text);
    }
    else if (choice == "5") {
        baconian_decryption(decryp_text);
    }
    else if (choice == "6") {
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
    else if (choice == "7") {
        polybuis_decryption(decryp_text);
    }
    else if (choice == "8") {
        morse_decryption(decryp_text);
    }
    else if (choice == "9") {
        string key;
        cout << "Enter the the key you want to decrypt with:";
        cin >> key;
        xor_decryption(decryp_text, key);
    }
    else if (choice == "10") {
        railfence_decryption(decryp_text);
    }
    else {
        cout << "Error! Enter a valid choice\n";
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
    cout << "===== Choose the Cipher =====\n1) Affine\n2) Route\n3) Atbash\n4) Vignere\n5) Baconian\n";
    cout << "6) Simple Substitution\n7) Polybius Square\n8) Morse Code\n9) XOR\n10) Rail-fence\n";
    cin >> choice;
    if (choice == "1") {
        if (!affine_checker(encryp_text)) {
            cout << "Error! The input must contain only alphabetic characters or spaces." << endl;
            menu_encryption();
        }
        int a, b, c;
        a = 5; // These are the parameters introduced in the problem sheet
        b = 8;
        c = 21;
        affine_encryption(encryp_text, a, b, c);
    }
    else if (choice == "2") {
        route_encryption(encryp_text);
    }
    else if (choice == "3") {
        cout << "1. Encrypt alphabet\n";
        cout << "2. Encrypt alphabet divided into two halves\n";
        string atbashenchoice;
        cin >> atbashenchoice;
        if (atbashenchoice == "1") {
            atbash_encryption(encryp_text);
        }
        else if (atbashenchoice == "2") {
            cout << "Encrypted text in Atbash: " << atbashCipher(encryp_text) << endl;
            main_menu();
        }
        else {
            cout << "Error! Enter a valid choice\n" << endl;
            menu_encryption();
        }
    }
    else if (choice == "4") {
        string key;
        cout << "Enter the the key you want to encrypt with:";
        cin >> key;
        while (true) {
            if (vigenere_checker(key)) {
                break;
            }
            else {
                cin >> key;
            }
        }
        vigenere_encryption(key, encryp_text);
    }
    else if (choice == "5") {
        baconian_encryption(encryp_text);
    }
    else if (choice == "6") {
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
    else if (choice == "7") {
        polybuis_encryption(encryp_text);
    }
    else if (choice == "8") {
        morse_encryption(encryp_text);
    }
    else if (choice == "9") {
        string key;
        cout << "Enter the the key you want to encrypt with:";
        cin >> key;
        xor_encryption(encryp_text, key);
    }
    else if (choice == "10") {
        railfence_encryption(encryp_text);
    }
    else {
        cout << "Error! Enter a valid choice\n";
        menu_encryption();  // Recurs
    }
}


// Main Menu
void main_menu(){
    string text;
    string choice;
    cout << "\n===== Main Menu =====\n1) Encryption\n2) Decryption\n3) Exit\n";
    cout<<"Enter your choice ==>";
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
        cout << "Error! Enter a valid choice\n";
         main_menu();
    }
}

int main() {
    cout << "\nWelcome to the Cryptography Program!";
    main_menu();
    return 0;
}