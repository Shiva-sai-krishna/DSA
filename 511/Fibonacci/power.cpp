#include<iostream>

using namespace std; 

// Simple Linear Power Function
int linearPower(int x, int n) {
    int result = 1;

    while (n>0) {
        result *= x;
        // result %= 10;
        n--;
    }

    return result;
}

// Binary Exponentiation (Recursive)
int expoPower(int x, int n) {
    if (n == 0) return 1;
    if (n%2 == 0) return expoPower(x*x, n/2);
    return x*expoPower(x*x, n/2);
}

// Binary Exponentiation (Iterative)
int expoPowerIterative(int x, int n) {
    int result = 1; 

    while(n != 0) {
        if (n%2 == 1)
            result *= x;
        x = x*x;
        n = n/2;
    }
    
    return result;
}


// Decimal Exponentiation (Recursive)
int decimalExponentiation(int x, int n) {
    if (n==0) return 1;

    int A,B,C,d,i,var=1;
    d = n%10;
    for (i=0;i<d;i++)
        var*=x;
    
    A = x*x;
    B = A*A;
    C= B*B;
    x = C*A;

    return var*decimalExponentiation(x,n/10);
}

// Decimal Exponentiation (Iterative)
int decimalExponentiationIterative (int x, int n) {
    int A,B,C,i,d,result=1,var;

    while (n>0) {
        d = n%10;
        
        if (d!=0) {
            var = 1;
            for (i=0;i<d;i++)
                var*=x;
            result*=var;
        }

        A=x*x;
        B=A*A;
        C=B*B;
        x=A*C;

        n=n/10;
    }

    return result;
}


int main() {
    int x, n;

    cout << "Enter the value of x and n ";
    cin >> x >> n;

    cout << "x^n : " << expoPowerIterative(x, n) << endl;
}