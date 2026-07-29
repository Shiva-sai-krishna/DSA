#include<iostream>
#include<vector>

using namespace std;

int main() { 

    vector<int> nums = {0,2,5,3,4,1,2,4,3,2,6,7,8,3,8,6,4,6,7,5,3};

    // an iterator is a standard traversing technique in STL containers
    // containers like vector, set, map allow traversing of elements using an iterator
    // Regardless of the underlying container implementation we can traverse it's elements
    // An iterator is similar to a pointer as it points to an element. 


    // The begin returns a iterator pointing to the first element
    auto itr = nums.begin();

    // Accessing this element can be done by using the * operator 
    cout << *itr << endl; 

    // To go to the next element we can increment the iterator 
    itr++;

    // The iterator will now point to the next element 
    cout << *itr << endl; 

    // To find the index in which the iterator is in
    // subtract with the first element iterator 
    cout << "iterator is in index : " << itr - nums.begin() << endl;

    // To print the first k elements (let k be 5) then we can do something like this 
    cout << "First K elements : ";
    for (auto itr = nums.begin(); itr - nums.begin() < 5; itr++)
        cout << *itr << " ";
    cout << endl;

    // While you could do the above, C++ style uses something like this 
    cout << "First K elements : ";
    for (auto itr = nums.begin(); itr != nums.begin() + 5; itr++)
        cout << *itr << " ";
    cout << endl;



    // Unlike the first element that is pointed by nums.begin() 
    // The last element is the element pointed before nums.end()
    // Therefore, nums.end() is actually an iterator that points to element after the last element
    // We can think of nums.end() pointing to the last index + 1
    // why do I get the output of the below line as 0? It is a undefined behaviour
    cout << *(nums.end()) << endl;

    // To print all elements 
    cout << "All elements of the vector : ";
    for (auto itr = nums.begin(); itr != nums.end(); itr++) 
        cout << *itr << " "; 
    cout << endl;

    // Vector, string, deque, and array support random-access iterators,
    // allowing iterator arithmetic (itr + n, itr - n) in O(1).

    // List, map, set, unordered_map, and unordered_set do not.
    // Their iterators only support sequential traversal, so
    // iterator arithmetic and subtraction are invalid.


    vector<pair<int, int>> arr = {{1,2}, {3,4}, {5,6}};
    vector<pair<int, int>>::iterator iter = arr.begin();
    // or simply. Also, you cannot declare the same variable twice in the same scope 
    // so I used itere instead of iter

    auto itere = arr.begin();

    cout << "First Pair : " << "{" << (*iter).first << " " << iter->second << "}" << endl;


    // iterators of the same container can be compared with each other
    auto itr1 = arr.begin();
    auto itr2 = arr.begin();

    if (itr1 == itr2)
        cout << "Iterators are equal" << endl;


    // iterators can become invalid. 
    // if an iterator points to the first element and you inserted an element then 
    // it is possible for that iterator to show undefined behaviour. 

}