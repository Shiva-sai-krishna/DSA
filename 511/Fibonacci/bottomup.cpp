#include<iostream>

using namespace std;

int main () {
    int a = 0, b = 1, c, n;

    cout << "Enter the value of N : ";
    cin >> n;

    for (int i = 0; i < n-2; i++) { 
        c = (a + b)%10;
        a = b;
        b = c;
    }

    cout << "Result : " << c << endl;
}