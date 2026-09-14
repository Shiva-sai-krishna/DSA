#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void swap(vector<int>& A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// if (i<=j) swap(A,i,j); we need an if condition here 
// because at the end we want j to point to an element that is less or equal to pivote
// or in other words
// we want j to point to the last index of the left partition

int partition(vector<int> &A, int l, int r, int p) {
    swap(A,l,p);
    int i=l+1, j=r, pivote = A[l];
    while (i <= j) { 
        while (i <= j && A[i] <= pivote) i++;
        while (i <= j && A[j] > pivote) j--;
        if (i<=j) swap(A,i,j); 
    }

    swap(A,l,j);
    return j;
}

void quicksort(vector<int> &A, int l, int r) {
    if (l < r) {
        int p = rand()%(r-l+1) + l;
        int k = partition(A,l,r,p);
        quicksort(A,l,k-1);
        quicksort(A,k+1,r);
    } 
}


int main() {
    int i, n;
    cout << "Enter the number of Elements : ";
    cin >> n;

    vector<int> A(n,0);
    cout << "Enter the Elements : ";
    for(i=0;i<n;i++) cin >> A[i];

    quicksort(A,0,n-1);

    cout << "Sorted Sequence : ";
    for(i=0;i<n;i++) cout << A[i] << " ";
    cout << endl;
}