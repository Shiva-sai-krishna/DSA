#include<iostream>

using namespace std;

int F(int n, int* memo) {
    if (memo[n] == -1) 
        memo[n] = (F(n-1, memo)+F(n-2, memo))%10;
    
    return memo[n];
}

int main () {
    int n;

    cout << "Enter the value of N : ";
    cin >> n;

    int memo[n+1];

    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    memo[0] = 0;
    memo[1] = 1;

    cout << "Result : " << F(n-1, memo) << endl;
}