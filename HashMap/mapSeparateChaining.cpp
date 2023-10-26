#include<bits/stdc++.h>
using namespace std;

//implement hashtable with closed addressing
//everything here is in o(1) worst case o(n)

//firstly create a class Hashing
class Hashing{

    

    vector<list<int>> hashtable;//create the hastable as vector of linked list
    int buckets;//for no. of buckets in the hashtables or the size of the hashtable

    public:

    //create the constructor of the class
    Hashing(int size){
        buckets=size;
        //now resize the hashtable according to the size given
        hashtable.resize(size);
    }

    //now create the hash function which will return hash value
    int hashValue(int key){

        //using division method
        return key%buckets;

    }

    //creating a function to add the key to the hashtable
    void add(int key){
        //firstly find the idx where we will store the key at the end of the linked list
        int idx=hashValue(key);
        hashtable[idx].push_back(key);

    }

    //for search we will make a function which will have return type of list iterator
    list<int>::iterator search(int key){
        int idx=hashValue(key);
        return find(hashtable[idx].begin(),hashtable[idx].end(),key);

    }

    //deleting the element will require you to use erase function where you will pass the iterator from the search function
    void deleteing(int key){
        int idx=hashValue(key);
        if(search(key)!=hashtable[idx].end()){
            //this means that the key exists in the linked list of the hashtable
            hashtable[idx].erase(search(key));
            cout<<"Key is delelted"<<endl;
        }
        else{
            cout<<"Key is not present in the hashtable"<<endl;
        }




    }

};

int main(){
     Hashing h(10);

    h.add(5);
    h.add(9);
    h.add(3);

    h.deleteing(3);
    h.deleteing(3);

    

    return 0;
}