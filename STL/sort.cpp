#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class student {
    public : 
        string name;
        int age, roll; 

        student(int roll, string name, int age) {
            this->name = name;
            this->age = age;
            this->roll = roll;
        }

        bool operator<(const student& A) const{
            return A.roll < roll;
        }
};

bool compare(student A, student B) {
    return A.roll < B.roll;
}

int main() { 
    vector<int> A = {0,2,5,3,4,1};

    // Sort in ascending order. The function expects iterators. 
    sort(A.begin(), A.end());

    // sort partially 
    sort(A.begin()+1, A.end() - 1);

    cout << "Vector A : ";
    for (auto x : A) 
        cout << x << " ";
    cout << endl;

    // Sort using a Lambda Function 
    sort(A.begin(), A.end(), [](int a, int b){ 
        return b < a;
    });
    cout << "Vector A : ";
    for (auto x : A) 
        cout << x << " ";
    cout << endl;


    vector<student> B;
    B.push_back(student(91, "Shiva", 25));
    B.push_back(student(536, "Sai", 21));
    B.push_back(student(4313, "Krishna", 15));

    // sort using a custom comparator
    sort(B.begin(), B.end(), compare);

    cout << "Vector B : ";
    for (student x : B) 
        cout << x.name << " ";
    cout << endl;

    // sort using comparator overloading
    sort(B.begin(), B.end());

    cout << "Vector B : ";
    for (student x : B) 
        cout << x.name << " ";
    cout << endl;

}   