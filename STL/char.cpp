#include<iostream>
#include<cctype>

using namespace std;

int main() {
    // Characters are represented using an integer through the ASCII mapping
    // ASCII has a total of 128 entries in its mapping. 
    // '0' - 48  '9' - 57
    // 'A' - 65  'Z' - 90
    // 'a' - 97  'z' - 122
    // ' ' - 32
    // A Character takes one byte 


    // Convert character from lower case to upper case 
    char c = 'a';

    // check if char is lower case 
    // Similarly for upper case you add 32
    if (c >= 'a' && c <= 'z') 
        c = c - ('a' - 'A');
    
    cout << "Uppercase : " << c << endl;


    // Convert Digit to char
    int i = 7;
    c = '0' + i;

    cout << "Char Digit : " << c << endl;

    // Convert char to digit 
    i = c - '0';

    cout << "integer digit : " << i << endl;

    // check if char is alpha num or not
    c = 'x';

    if ((c >= 'a' && c<= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c<= '9'))
        cout << "Character is Alphanumeric" << endl;
    else 
        cout << "Not Alpha Numeric" << endl;

    // The STL Library provides you with the cctype library 
    // that automatically does these operations
    // These are legal to use in an interview
    // These only apply for characters and not strings 

    char lowerC = tolower(c);
    char upperC = toupper(c);
    bool flag = isalnum(c);
    bool flag2 = isalpha(c);
    bool flag3 = isdigit(c);

}