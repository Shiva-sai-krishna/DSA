#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int> &A, int i, int j) {
    int k = A[i];
    A[i] = A[j];
    A[j] = k;
}

int partition(vector<int> &A, int l, int r, int p) {
    swap(A,l,p);
    int i=l+1, j=r, pivote=A[l], k=l+1;
    while (i<=j) {
        while(i<=j && A[i]==pivote) swap(A,i++,k++);
        while(i<=j && A[j]==pivote) swap(A,j--,k++);
        while(i<=j && A[i] <= pivote) i++;
        while(i<=j && A[j] > pivote) j--;
        if (i<=j) swap(A,i,j);
    }

    swap(A,l,j);
    return j;
}

int findIndex(vector<int> &A, int l, int r, int rank) {
    if (l > r) return -1;
    int p = rand()%(r-l+1) + l;
    int k = partition(A, l, r, p);
    int prank = (r-k+1);
    int dup=0;
    while(A[k]==A[l+dup]) dup++;
    if (prank == rank) return k;
    else if (prank > rank) return findIndex(A,k+1,r,rank);
    else return findIndex(A,l+dup,k-1,rank-prank);
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


