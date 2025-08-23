#include<iostream>
#include<unordered_map>

using namespace std;
int main() {
    unordered_map<int, string> map;

    // inserting a key-value pair in map
    map[0] = "Sexy"; 
    map[1] = "Not sexy";

    // accessing a value in a map => can be accessed using square brackets or .at() method

    cout<<map[1]<<endl; // Not sexy
    cout<<map.at(1)<<endl; // Not sexy

    // while using [], if the key doesnt exist the default value for the datatype will be returned for the value. 

    // updating the value => if you can access the shit, you can update it.

    map[1] = "Very Sexy";

    cout<<map[1]<<endl; // Very Sexy

    // finding an element => .find() returns a key-value reference struct, if a key is not present it returns end position object for the map i.e. map.end() // formally. Returns iterator to the element with specific key

    auto item = map.find(1); 

    // item->first; // key
    // item->second; // value

    // deleting a key => .erase() can accept key or position object

    // map.erase(0); 

    // size of the map => .size() returns the number of key-value pairs.
    map.size();

    // checking if key exist or not. Altough, there is no built-in .contains method. We can .count(key) method to check it, since no duplicate key exists.
    // returns 1 if exists, else 0;

    cout<<map.count(1)<<endl; // 1

    cout<<map.count(4)<<endl; // 0



    return 0;
}