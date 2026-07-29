#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// A class is a decleration and therefore needs a semi colon
class Comparator { 
    public : 
        bool operator()(pair<int, int> A, pair<int, int> B) {
            return A.second > B.second;
        }
            
};

int main() {
    // If you have to use a heap with other objects that have many attributes
    // or need a special way to prioritize the elements in the heap 
    // then you must implement your own comparator and pass it on to the heap

    // I want my heap to be a min heap of the second element of the pair

    auto comparator = [](pair<int, int> A, pair<int, int> B){return A.second > B.second;};
    vector<pair<int, int>> elements = {{1,2}, {3,4}, {6,4}};

    // Using the Lambda Comparator
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(elements.begin(), elements.end(), comparator);

    // Using the Class Comparator 
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> pq2(elements.begin(), elements.end());

    // Printing the Heap 
    cout << "Heap Elements are : \n";
    while (!pq.empty()) {
        cout << "{" << pq.top().first << " : " << pq.top().second << "}" << endl;
        pq.pop();
    }

    // If you were to use a pq of pair<int, string> 
    // the it would by default be a max heap 
    // that would keep compare the int first 
    // so your top has the highest int value
    // but if the ints are same then it compares the strings
    // and strings are compared lexiographically 
    

}