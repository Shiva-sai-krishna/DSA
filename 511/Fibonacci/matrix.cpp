#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> MM(vector<vector<int>> &A, vector<vector<int>> &B, int n){
    int i,j,k;

    vector<vector<int>> C(n, vector<int>(n,0));
    
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            for(k=0;k<n;k++) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    return C;
}

void printM(vector<vector<int>> &A,int n) {
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// Binary Matrix Exponentiation
vector<vector<int>> powerM(vector<vector<int>> &A, int n, int N) {

    vector<vector<int>> R(n, vector<int>(n,0));
    int i,j;

    for(i=0;i<n;i++)
        R[i][i]=1;

    while(N>0) {
        if(N%2 == 1) 
            R = MM(R,A,n);
        
        A = MM(A,A,n);
        N = N/2;
    }

    return R;
}

// Decimal Matrix Exponentiation
vector<vector<int>> powerM2(vector<vector<int>> &A, int n, int N) {

    vector<vector<int>> X(n, vector<int>(n,0));
    vector<vector<int>> Y(n, vector<int>(n,0));
    vector<vector<int>> Z(n, vector<int>(n,0));
    vector<vector<int>> R(n, vector<int>(n,0));
    int i,j,d;

    for(i=0;i<n;i++)
        X[i][i] = R[i][i]=1;

    while(N>0) {
        d = N%10;
        if(d != 0) {
            for(i=0;i<d;i++)
                X=MM(X,A,n);
            R = MM(R,X,n);
        } 
        
        X = MM(A,A,n);
        Y = MM(X,X,n);
        Z = MM(Y,Y,n);
        A = MM(X,Z,n);

        N = N/10;
    }

    return R;
}


int main () {

    vector<vector<int>> A = {{1,2,3},{2,3,4},{3,4,5}};
    vector<vector<int>> B = {{1,1,0},{1,0,1},{0,1,1}};
    vector<vector<int>> C = MM(A,B,3);

    B = powerM2(B,3,12);
    printM(B,3);
}


