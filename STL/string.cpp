// string is a class that has 3 properities in it
// size of string or length of string which is stored as a variable 
// capacity of the string after which a new larger memory is allocated 
// and finally the actual pointer to the char array 

// The char array, similar to the C - String has a '\0' (ASCII : 0) at the end 
// Though that character is not counted towards the length 

// unlike strings in java strings in C++ are mutable 
// we can go an change individual characters in the string 

// strings are STL containers and therefore supports 
// iterators, sorting, searching 


#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    // to convert a string to integer use stoi()
    // to convert an integer to string use to_string

    string numer = to_string(3699);
    int num = stoi("3699");

    // substr(start index, length) will return you the string 
    // if length is longer than the max length of the string then no problem 
    
    string name = "shiva sai krishna";
    string first = name.substr(0, 5);
    string full_name = name.substr();
    string last_name = name.substr(10);

    cout << first << " " << last_name << endl;

    // replace will first erase characters of length starting from the index and then add the string at that place
    // replace(start index, length, string)
    // It can be thought of as a combination of erase and append 
    string rename = name.replace(0,5,"Avani");
    
    // erace (start index, length) will remove the chars
    // erace (index) will remove char at that index
    name.erase(0, 5);
    name.erase(0);
    
    // insert (start index, string) allows insertion at a particular index
    // There are no other overloads
    name.insert(0, "shiva ");

    // add a string / character into an existing string using the += operator (without copy)
    // You can use the + operator if you want a new copy of the string 
    name += "anand";
    name = name + " tokal";

    // append servers similar purpose to + / += but have some overloaded functions 
    // You can directly append a string or a section of a string 
    // You can append characters of some frequency
    name.append(" is");
    name.append("### a ###", 3, 3);
    name.append(3, 'B');


    cout << name << endl;

    // find() can be used to search for a string in another string and return the first index
    // rfind() will do the same but will give you the index of last occurace
    // find(pattern, start index of pattern, length of pattern)
    // Here 5 means how many characters in the pattern

    int ind;
    // return the index of first occurance of tokal from the left
    ind = name.find("tokal");

    // Search starting from the index 5 of name
    ind = name.find("tokal", 5);

    // Search starting from the index 5 of name, also only count the first 2 characters of tokal so, to
    ind = name.find("tokal", 5, 2);


    // You can use -1 or string::npos
    if (ind == -1) 
        cout << "NOT FOUND" << endl;
    else 
        cout << "FOUND" << endl;

    // find_first_of(chars) and find_last_of(chars) finds the chars in the string
    // if found returns its index 
    string random = "0123456789";
    int index = random.find_first_of("369");
    cout << "A char from 369 found at position : " << index << endl;


    // Sort a string 
    random = "025341";
    sort(random.begin(), random.end());
    cout << random << endl;

}