#include<iostream>

using namespace std;

int main() { 

    // Take the number as a string
    string s;
    cout << "Enter the number (n) : ";
    cin >> s;

    // convert the number to a digit array
    int l = s.size();
    int n[l];
    for(int i=0; i<l; i++)
        n[i] = s[i]-'0';


    // Take the modulo 
    int m; 
    cout << "Enter the value of Modulo (m) : ";
    cin >> m;
    
    // Find the periodic sequence and store it in an array
    int i=2, p=2, period[6*m+10];
    period[0] = 0;
    period[1] = 1;

    while(true) {
        period[i] = (period[i-1]+period[i-2])%m;
        if (period[i]==1 && period[i-1]==0)
            break;
        i++;
        p++;
    }    
        
    p = p-1;
    cout << "Value of P : " << p << endl;

    // Perform N % P. Remember to start from the MSB
    int r = 0;
    for(int i=0;i<l;i++) 
        r = ((r*10)+n[i])%p;
    cout << "Value of R : " << r << endl;

    // N is the Nth fib sequence. F(0) = 0, F(1) = 1;
    cout << "F(N) : " << period[r] << endl;
}
