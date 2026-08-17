#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> MM(vector<vector<int>> A, vector<vector<int>> B, int n, int m) {
    vector<vector<int>> C(n, vector<int>(n,0));
    int i,j,k;

    for (i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            for (k=0;k<n;k++) {
                C[i][j] += (1LL*A[i][k]*B[k][j])%m;
                C[i][j] %= m;
            }
        }
    }

    return C;
}

int decimalMatrixExpo(vector<int> N, int m) { 

    vector<vector<int>> A(100, vector<int>(100,0));
    for(int i=0; i<100; i++) A[0][i]=1;
    for(int i=0; i<99; i++) A[i+1][i]=1;

    vector<vector<int>> R(100,vector<int>(100,0));
    for(int i=0; i<100; i++) R[i][i]=1;

    vector<vector<int>> A2,A4,A8;
    int i,d,l=N.size();

    for(i=l-1; i>=0; i--) {
        d = N[i];
        while(d-->0) 
            R=MM(R,A,100,m);
        
        A2=MM(A,A,100,m);
        A4=MM(A2,A2,100,m);
        A8=MM(A4,A4,100,m);
        A=MM(A2,A8,100,m);
    }

    int answer = 0;
    for (i=0;i<100; i++) {
        answer+= (R[99][i]*(99-i));
        answer%= m;
    }

    return answer;
}

int main() {
    
    string s;
    vector<int> N;
    cout << "Enter the value of N : ";
    cin >> s;
    
    for(char c : s)
        N.push_back(c-'0');

    int m;
    cout << "Enter the value of m : ";
    cin >> m;

    cout << "Fn : " << decimalMatrixExpo(N,m);
}