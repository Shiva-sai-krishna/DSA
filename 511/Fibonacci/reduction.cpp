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

void divide(vector<int> &N, int d) {
    int q,r=0,i,l=N.size(),num;

    for(i=0;i<l;i++) {
        num=(r*10)+N[i];
        q = num/d;
        r = num%d;
        N[i]=q;
    }

}

bool isZero(vector<int> &N) {
    for (int ele : N) {
        if (ele) 
            return false;
    }

    return true;
}

bool isOdd(vector<int> &N) {
    int l = N.size();
    return (N[l-1]%2 == 1);
}

int binaryMatrixExpo(vector<int> N, int m) {

    vector<vector<int>> A(2, vector<int>(2,1));
    A[1][1] = 0;

    vector<vector<int>> R(2,vector<int>(2,0));
    R[0][0] = R[1][1] = 1;

    while (!isZero(N)) {
        if (isOdd(N)) 
            R = MM(R, A, 2, m);
        
        A = MM(A,A,2,m);
        divide(N,2);
    }

    return R[1][0];
}

int decimalMatrixExpo(vector<int> N, int m) { 

    vector<vector<int>> A(2, vector<int>(2,1));
    A[1][1] = 0;

    vector<vector<int>> R(2,vector<int>(2,0));
    R[0][0] = R[1][1] = 1;

    vector<vector<int>> A2,A4,A8;
    int i,d,l=N.size();

    for(i=l-1; i>=0; i--) {
        d = N[i];
        while(d-->0) 
            R=MM(R,A,2,m);
        
        A2=MM(A,A,2,m);
        A4=MM(A2,A2,2,m);
        A8=MM(A4,A4,2,m);
        A=MM(A2,A8,2,m);
    }

    return R[1][0];
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