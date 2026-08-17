#include<iostream>

using namespace std;


// The maximum answer it can give is near 44 within 1 second time

int F(int N) {
    if (N <= 1) return N;
    return (F(N-1) + F(N-2))%10;
}

int main() {
    int n;

    cout << "Enter the value of N : ";
    cin >> n;

    cout << "Result : " << F(n-1) << endl;

}