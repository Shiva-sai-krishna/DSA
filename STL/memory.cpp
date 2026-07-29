// When dealing with larger STL Containerslike 
// vectors, maps, sets, pairs and even strings 
// Try to use their reference instead of making a copy of it


#include<iostream>
#include<vector>

using namespace std; 

int main() { 

    vector<int> nums = {0,2,5,3,4,1};

    // This would make a copy of nums
    auto arr = nums; 

    // This would use a reference
    auto &ref = nums;



    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<vector<int>> copy;

    // This would copy the inner vectors into vec
    // push back would then add a new copy of vec into copy
    // causing a total of two different copies

    for (auto vec : mat)
        copy.push_back(vec);


    // This would use a reference of them as vec
    // emplace back would however, push a copy of vector as vectors cannot store references.
    // So you never have a reason to use emplace back
    // causing a total of one copy 

    for (auto &vec : mat)
        copy.emplace_back(vec);


    
}


