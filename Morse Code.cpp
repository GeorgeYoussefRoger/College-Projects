#include<iostream>
#include<string>
#include<map>
using namespace std;
void main_menu();

// Function for Morse code encryption
void encryption_morse(string x) {
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
    cout << "Encrypted message: " << morsetext << "\n";
    main_menu();
}


// Function for Morse code decryption
void decryption_morse(string morse) {
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
    cout << "Decrypted message: " << decryp << "\n";

    main_menu();
}


// Main Menu
void main_menu(){
    string text;
    string choice;
    cout << "===== Main Menu =====\n1) Encryption\n2) Decryption\n3) Exit\n";
    cout<<"Entre your choice \n ==>";
    cin >> choice;
    if (choice == "1") {
        cout << "\nEnter your message: \n";
        cin.ignore();
        getline(cin,text);
        encryption_morse(text);
    }
    else if (choice == "2") {
        cout << "\nEnter your message: \n";
        cin.ignore();
        getline(cin,text);
        decryption_morse(text);
    }
    else if (choice == "3") {
        exit(0);
    }
    else {
        cout << "\nPlease enter a valid choice\n";
        main_menu();
    }
}
int main() {
    cout<<"Welcome  to the Cryptography Program!\n";
    main_menu();
    return 0;
}