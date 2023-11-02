#include<bits/stdc++.h>
using namespace std;

// Check whether two Strings are isomorphic of each other. Return true if they are else return false.

// Two strings are isomorphic of each other if there is a one-to-one mapping possible for every character of the 
// first string to every character of second string and all occurrences of every character in first string maps to the 
// same character in the second string.

//firstluy check whether the two strings are equal in size or not
//then we have to check that every character should be connected to only one character in the other string
//so we may use a map to store the <char,char>

bool isIsomorphic(string s1,string s2){
    //firt check if s1 and s2 are of same length or not
    if(s1.length()!=s2.length()){
        return false;
    }

    //now use a unordered map
    unordered_map<char,char> m;

    //checking one-many from s1 to s2
    for(int i=0;i<s1.size();i++){
        //check if it is present in the map
        if(m.find(s1[i])!=m.end()){
            //then check if it is mapped to its same positioned char in s2
            if(m[s1[i]]!=s2[i]){
                return false;
            }
        }

        //if not present in the map then add it
        else{
            m[s1[i]]=s2[i];
        }
    }

    m.clear();

    //now check one-many from s2-s1
    //we can also create a separate function for checking one to many mapping
    for(int i=0;i<s2.size();i++){
        if(m.find(s2[i])!=m.end()){
            if(m[s2[i]]!=s1[i]){
                return false;
            }
        }
        else{
            m[s2[i]]=s1[i];
        }
    }

    return true;

}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    if(isIsomorphic(s1,s2)){
        cout<<"is isomorphic"<<endl;

    }
    else{
        cout<<"is not isomorphic"<<endl;
    }


    return 0;
}

//time complexity o(n)