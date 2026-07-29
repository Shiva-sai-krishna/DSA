#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){ 

    // Priority queues are Max Heaps by default 
    // ie they store the elements as a binary tree 
    // such that parent is always greater than its children
    
    // For primitive data types a comparator is already defined 
    // comparators for strings and pairs uses lexiographically
    // However, for objects, a custom comparator needs to be created


    // Here is a simple priority queue. 
    // You can only do push, pop and top 
    // pop does not return the deleted element
    // Also you cannot iterate through the elements of a pq (Heap)

    priority_queue<int> pq;

    pq.push(1);
    pq.push(2);
    pq.push(3);

    cout << "Top element : " << pq.top() << endl;

    for (int i=0; i<3; i++)
        pq.pop();


    // you could also create a heap directly if you have an array of integers
    // This will create the heap in O(n) instead of O(nlogn)
    vector<int> nums = {1,2,3};
    pq = priority_queue(nums.begin(), nums.end());
    
    cout << "Top element : " << pq.top() << endl;
    
    // To print all elements in the Heap
    cout << "Queue : ";
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;



    // If you want a min heap you need to use the greater comparator 
    // There are a total of three types that needs to be provided
    // The type of the value that the heap will store 
    // The underlying data structure that the heap should use
    // You will always use a vector 99% but there are cases to use deque
    // And the comparator that the heap should use

    // It is confusing that min heap uses that greater comparator 
    // while max heap uses the less comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;



}
