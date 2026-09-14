#include<iostream>
#include<vector>

using namespace std;

int findRank(vector<int> A, int x) {
    int rank=1;
    for(int ele : A) {
        if (ele > x)
            rank++;
    }
    return rank;
}

int main() {
    int i, n;
    cout << "Enter the number of Elements : ";
    cin >> n;

    vector<int> A(n,0);
    cout << "Enter the Elements : ";
    for(i=0;i<n;i++) cin >> A[i];

    int x;
    cout << "Enter the Element to find rank of : ";
    cin >> x;

    int rank = findRank(A, x);
    cout << "Rank of " << x << " : " << rank;
}


