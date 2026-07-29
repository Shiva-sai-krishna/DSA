#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

struct VectorHash {
    // size_t is unsigned integer that is used to represent size of objects in memory
    // when you use sizeof then it returns the size_t data type
    // The hash function expects you to return a size_t 
    // size_t by nature can wrap around when an overflow happens
    // unlike int which is great for hash
    
    // The first const is a must as the hash function expects you to not meddle with the input
    // The & is usefull as we dont make a copy every time we try to do a hash 
    // The second const is a must as the function expects you to noe meddle with the output
    size_t operator()(const vector<int> &nums) const {
        size_t h = 0; 
        for (int num : nums) 
            h = h*31 + hash<int>{}(num);
        return h;
    }
};


int main() {
    // The keys of a Hash Map must be hashable
    // STL provides int, string hashing functions but 
    // not for vector<int>
    // If you wish to hash a vector as a key 
    // you need to provide its own hash function 

    unordered_map<vector<int>, int, VectorHash> map;
    map[{0,1,2,3}] = 100;
    map[{0,2,4,6}] = 200;
    map[{0,3,6,9}] = 300;

    cout << "Value for Key {0,3,6,9} : " << map[{0,3,6,9}] << endl;

}   
   
   
    