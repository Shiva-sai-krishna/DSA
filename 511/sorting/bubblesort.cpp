    #include<iostream>
    #include<vector>

    using namespace std;

    void swap(vector<int>& A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    void bubblesort(vector<int>& A, int l, int r) {
        int i, j, idx, n = r - l + 1;
        for (i=0; i<n-1; i++) {
            for (j=l; j<r-i; j++) {
                if (A[j] > A[j+1])
                    swap(A,j,j+1);
            }
        }
    }

    int main() {
        int i, n;
        cout << "Enter the number of Elements : ";
        cin >> n;

        vector<int> A(n,0);
        cout << "Enter the Elements : ";
        for(i=0;i<n;i++) cin >> A[i];

        bubblesort(A,0,n-1);

        cout << "Sorted Sequence : ";
        for(i=0;i<n;i++) cout << A[i] << " ";
        cout << endl;
    }