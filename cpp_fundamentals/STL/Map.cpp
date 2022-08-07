#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;

void printMap(map<string, int>, string);

int main(){
    /* [Constructor] */
    map<string, int> userHeights = {{"Adam", 178}, {"Bob", 185}};
    map<string, int> userAges;

    /* [Assignment] */
    userAges["Adam"] = 20;
    userAges["bob"] = 22;

    printMap(userHeights, "user heights");
    printMap(userAges, "user ages");

    /* [Modification] */
    userHeights["Adam"] = 158;
    printMap(userHeights, "Modified user heights");

    userHeights.insert({"Carlie", 190});
    printMap(userHeights, "Modified user heights");

    // Erase by iterator position
    auto it = userHeights.find("Carlie");
    userHeights.erase(it);
    printMap(userHeights, "Modified user heights");

    return 0;
}

void printMap(map<string, int> m, string name){
    cout << name << ": { ";
    for(auto x : m){
        cout << x.first << ": " << x.second << ", ";
    }
    cout << " }" << endl ;
}