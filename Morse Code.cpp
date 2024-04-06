#include<iostream>
#include<string>
#include<map>
using namespace std;
void main_menu();

// Function for Morse code encryption
void encryption_morse(string text) {
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
    string encryp_text = "";
    for (int n = 0; n < text.length(); n++) {
        if (isspace(text[n])) {  // Check if the current character is a space
            encryp_text += "   ";
        }
        else {  // If not a space, convert the character to uppercase and find its Morse code equivalent
            encryp_text = encryp_text + morsecode[toupper(text[n])] + " ";
        }
    }
    encryp_text += " ";
    cout << "Encrypted message: " << encryp_text << endl;
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
    string decryp_text = "";
    for (int i = 0; i <= morse.length(); i++) {
        if (!isspace(morse[i]) && i < morse.length()) {  // Check if the current character is a space
            letter += morse[i];
        }
        else if (!letter.empty()) {
            decryp_text += morsecode[letter];
            letter = "";
        }
        else {
            decryp_text += ' ';
        }
    }
    cout << "Decrypted message: " << decryp_text << "\n";

    main_menu();
}


// Main Menu
void main_menu(){
    string text;
    string choice;
    cout << "===== Main Menu =====\n1) Encryption\n2) Decryption\n3) Exit\n";
    cout << "Enter your choice ==>";
    cin >> choice;
    if (choice == "1") {
        cout << "\nEnter your message:";
        cin.ignore();
        getline(cin,text);
        encryption_morse(text);
    }
    else if (choice == "2") {
        cout << "\nEnter your message:";
        cin.ignore();
        getline(cin,text);
        decryption_morse(text);
    }
    else if (choice == "3") {
        exit(0);
    }
    else {
        cout << "\nPlease Enter a Valid Choice\n";
        main_menu();
    }
}

int main() {
    cout << "Welcome to the Cryptography Program!\n";
    main_menu();
    return 0;
}