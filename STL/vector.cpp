#include<vector>
#include<iostream> 

using namespace std;

int main() { 
    vector<int> A;
    vector<int> B(5);
    vector<int> C(5,-1);
    vector<int> D = {1,2,3,4,5};

    cout << "Vector C : ";
    for (int x : C)
        cout << x << " ";
    cout << endl;

    A.push_back(0);
    A.push_back(5);
    A.push_back(10);

    A.pop_back();
    A.pop_back();

    cout << "Vector A : ";
    for (int i=0; i<A.size(); i++)
        cout << A[i];
    cout << endl;

    D.clear();
    if (D.empty())
        cout << "Vector D is Empty" << endl;
    else 
        cout << "Vector D is not Empty" << endl;

}