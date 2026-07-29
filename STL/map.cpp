#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main() {

    // The unordered map uses Hashing for the Keys 
    // Therefore Referencing and searching them is O(1)
    // However, in worst case due to collisions 
    // and internal usage of linked list 
    // searchin could end up being O(N)
    // If the keys hash to the same bucket 

    unordered_map<int, int> map;

    // maps of C++ have a unique feature 
    // where if you tried to find the value for a key 
    // that does not exist in the map 
    // It would add that key to the map 
    // assign a default value to it
    // and return that default value. 

    // int             -> 0
    // double          -> 0.0
    // bool            -> false
    // char            -> '\0'
    // string          -> ""
    // vector<int>     -> empty vector
    // pair<int,int>   -> {0,0}

    // Which is why 
    cout << "Current size of Map : " << map.size() << endl;
    cout << "Value of Key 911 : " << map[911] << endl;
    cout << "Current size of Map : " << map.size() << endl;


    // To officially add keys and values we simply use the [] operator
    // Or use the insert method
    map[0] = 0;
    map[1] = 1;
    map[2] = 2;
    map.insert({3,3});

    // To remove a key from a map use the erase operator
    map.erase(3);

    // To search if an element is present in the map we have two options 
    // First is the iterator and the preffered method 

    auto itr = map.find(2);
    if (itr == map.end())
        cout << "Key 2 NOT found" << endl;
    else 
        cout << "value for Key 2 : " << itr->second << endl;

    // A map stores its elements as the pair container in STL
    // Where the first stores the key and second stores the value
    // Therefore  we can directly use the -> operator on iterator


    // The other way to find element is using the count 
    // count returns the frequency of a key in the map
    // since keys are always unique the count returns 0 or 1
    // and since 0 is false and 1 is true we can use it check if a key exists
    // And now that we know that the key exists we can find the value using the [] operator
    // However there is a problem. We are searching twice. once when we use the count 
    // and once when we use the []. Which is the reason why itr method is preffered. 

    if (map.count(2)) 
        cout << "Key 2 found AGAIN with value " << map[2] << endl;
    else 
        cout << "Key 2 NOT found" << endl;


    // To iterator through a map 
    cout << "Map Key : Value " << endl;
    for (auto &p : map)
        cout << p.first << " : " << p.second << '\n';

    
}