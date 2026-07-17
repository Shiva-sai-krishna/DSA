#include<iostream>
using namespace std;

int main () { 

    int x,y;
    string s, line;

    cout << "Enter two Integers : " << endl;
    cin >> x >> y;

    cout << "Enter a String : " << endl;
    cin >> s;

    cout << "Enter a Line : " << endl; 
    cin.ignore(); 
    getline(cin, line);

    cout << "Sum of Two numbers : " << x+y << endl;
    cout << "Entered String : " << s << endl;
    cout << "Entered Line : " << line << endl;

}
