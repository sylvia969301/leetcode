/*
Reference :https://www.cplusplus.com/reference/vector/vector/
Points:
    - Vectors are sequence containers representing arrays that can change in size.
    - Sequence, Individual elements are accessed by their position in this sequence.
    - Dynamic array, allows direct access to any element in the sequence.
    - Allocator-aware, The container uses an allocator object to dynamically handle its storage needs.
    - Operation : push_back(), pop_back(), begin(), end(), front(), back(), size(), empty(), clear(), resize()
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printVector(vector<int> &v, string name){
    cout << name << ": [";
    for (int i =0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "]"<< endl;
}

int main(){
    /*[Declaration]*/
    vector<int> first; //empty vector of ints
    vector<int> second (4,100);   // four ints with value 100
    vector<int> third (second.begin(), second.end()); // iterating through second 
    vector<int> fourth(third); // a copy of third
    
    // the iterator constructor can also be used to construct from arrays
    int myInts[] = {1, 3, 4, 5, 6};
    vector<int> fifth (myInts, myInts + sizeof(myInts)/ sizeof(int));
    cout << "size of a myInts[]: " << (sizeof(myInts)/sizeof(*myInts)) << endl;
    printVector(first, "first");
    printVector(second, "second");
    printVector(third, "third");
    printVector(fourth, "fourth");
    printVector(fifth, "fifth");

    /*[Access]*/
    cout << "second[2] = "<<second[2] <<endl; // O(1)
    cout << "fifth.front() = " << fifth.front() << endl;// O(1)
    cout << "fifth.back() = " << fifth.back() << endl ;//O(1)

    /*[Capacity]*/
    if (!fifth.empty()) cout << "fifth.size() = " << fifth.size() << endl; //O(1)

    /*[Modifier]*/
    second.clear(); //O(n)
    printVector(second, "second");
    
    second.push_back(10); //O(1)
    second.push_back(11);
    printVector(second, "second");

    fifth.pop_back(); //O(1)
    printVector(fifth, "fifth");

    fifth.resize(2); //O(n) 
    printVector(fifth, "fifth");

    third.resize(5, 20);//O(n)
    printVector(third, "third");

    swap(fifth[0], fifth[1]); //O(1)
    printVector(fifth, "fifth");

    return 0;
}