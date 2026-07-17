#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {

    vector<int> A = {0,2,5,3,4,1};
    sort(A.begin(), A.end());

    if (binary_search(A.begin(), A.end(), 3))
        cout << "3 is found" << endl;
    
    // first element strictly greater than target
    int up = upper_bound(A.begin(), A.end(), 2.5) - A.begin();

    // first element greater than or equal to target
    int low = lower_bound(A.begin(), A.end(), 2) - A.begin();
    
    cout << "upper bound of 2.5 : " << A[up] << endl;
    cout << "lower bound of 2.5 : " << A[low] << endl;

    // Linear Search 
    auto iterator = find(A.begin(), A.end(), 3);
    int idx = iterator - A.begin(); 

    cout << "Found 3 at index : " << idx << endl;


}