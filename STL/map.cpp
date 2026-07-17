#include<unordered_map>
#include <iostream>

using namespace std;

void printMap(unordered_map<int, string> map) { 
    cout << "KEY : VALUE" << endl;
    cout << "_____________" << endl;

    for (pair pair : map) 
        cout << pair.first << " : " << pair.second << endl;
    cout << endl;
}

int main() { 
    unordered_map<int, string> map;

    map[0] = "Hello";
    map[9] = "Shiva";
    map[32] = "Dragon";

    printMap(map);

    if (map.count(9)) 
        cout << "9 present in map with value : " << map[9] << endl;
    
    if (map.find(32) != map.end())
        cout << "32 present in map with value : " << map[32] << endl;

    map.erase(0);
    printMap(map);

    map.clear();
    if (map.empty())
        cout << "map is empty" << endl;
}