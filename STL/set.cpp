#include<iostream>
#include<unordered_set>

using namespace std;

void printSet(unordered_set<int> set) { 
    cout << "Set : ";
    for (int x : set) 
        cout << x << " ";
    cout << endl;
}

int main() { 
    unordered_set<int> set;

    if (set.empty())
        cout << "Set is Empty" << endl;

    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(4);
    set.insert(5);

    printSet(set);


    if (set.count(5))
        cout << "Set contains 5" << endl;
    
    unordered_set<int>::iterator iterator = set.find(4);
    if (iterator != set.end())
        cout << "Set contains 4" << endl;


    set.erase(4);
    set.erase(5);

    printSet(set);

    set.clear();
    if (set.empty())
        cout << "Set is Empty" << endl;

}