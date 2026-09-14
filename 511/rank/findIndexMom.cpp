#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int> &A, int i, int j) {
    int k = A[i];
    A[i] = A[j];
    A[j] = k;
}

void bubblesort(vector<int>& A, int l, int r) {
    int i, j, n=r-l+1;
    for (i=0; i<n-1; i++) {
        for (j=l; j<r-i; j++) {
            if (A[j] > A[j+1])
                swap(A,j,j+1);
        }
    }
}

int partition(vector<int> &A, int l, int r, int p) {
    swap(A,l,p);
    int i=l+1, j=r, pivote=A[l];
    while (i<=j) {
        while(i<=j && A[i] <= pivote) i++;
        while(i<=j && A[j] > pivote) j--;
        if (i<=j) swap(A,i,j);
    }

    swap(A,l,j);
    return j;
}

int MOM(vector<int>& A, int l, int r);

int findIndex(vector<int> &A, int l, int r, int rank) {
    if (l > r) return -1;
    int n = r-l+1;

    if (n <= 5) {
        bubblesort(A,l,r);
        return r - rank +1;
    } else {
        int p = MOM(A, l, r);
        int k = partition(A, l, r, p);
        int prank = (r-k+1);
        if (prank == rank) return k;
        else if (prank > rank) return findIndex(A,k+1,r,rank);
        else return findIndex(A,l,k-1,rank-prank);
    }
}

int MOM(vector<int>& A, int l, int r) {
    int i,k,n=r-l+1;

    for (i=l,k=l; i+4<=r;i+=5,k++) {
        bubblesort(A,i,i+4);
        swap(A,k,i+2);
    }

    return findIndex(A,l,k-1,(k-l+1)/2);
}


int main() {
    int i, n;
    cout << "Enter the number of Elements : ";
    cin >> n;

    vector<int> A(n,0);
    cout << "Enter the Elements : ";
    for(i=0;i<n;i++) cin >> A[i];

    int x;
    cout << "Enter the rank of the element : ";
    cin >> x;

    int index = findIndex(A, 0, n-1, x);
    if (index != -1) cout << "Element with rank " << x << " : " << A[index] << " having index : " << index;
    else cout << "Not found";
}



