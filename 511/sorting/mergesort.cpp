#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &A, int l, int r) {
    int i,j,k, m = (l+r)/2, n=(r-l+1);
    vector<int> B(n,0);

    for (i=l, j=m+1, k=0; i<=m && j<=r;) {
        if (A[i] <= A[j]) B[k++] = A[i++];
        else B[k++] = A[j++];
    }

    while (i<=m) B[k++] = A[i++];
    while (j<=r) B[k++] = A[j++];

    k=0;
    i=l;
    while (k<n) A[i++] = B[k++];
}


void mergesort(vector<int>& A, int l, int r) {
    if (l>=r) return;
    int m = (l+r)/2;
    mergesort(A,l,m);
    mergesort(A,m+1,r);
    merge(A,l,r);
}


int main() {
    int i, n;
    cout << "Enter the number of Elements : ";
    cin >> n;

    vector<int> A(n,0);
    cout << "Enter the Elements : ";
    for(i=0;i<n;i++) cin >> A[i];

    mergesort(A,0,n-1);

    cout << "Sorted Sequence : ";
    for(i=0;i<n;i++) cout << A[i] << " ";
    cout << endl;
}