#include<bits/stdc++.h>
using namespace std;

// Check whether two Strings are anagram of each other. Return true if they are else return false.

// An anagram of a string is another string that contains the same characters, only the order of characters can 
// be different. For example, “abcd” and “dabc” are an anagram of each other.



// We need to figure out the criteria of two strings to be anagrams"

//  The first criteria is that length of 2 strings has to be the same for them to be anagrams"

//  Secondly, the frequency of every character in a string has to be equal to the frequency of every character in 
// the other string"

//  No character to be extra or different in any of the strings"

//  Thus, to main the count of the frequency for every character in the first string, we use a HashMap"

//  Now, we can follow 2 approaches here: maintain a HashMap for both the strings and in the end just 
// compare both the HashMaps, if they are equal we return true else false"

//  This can be optimized by using only 1 HashMap. We store frequency for each character in any one of the 
// strings. Then traverse over the other string, and for every character, first check if it is present in the HashMap 
// or not. If it is not present, the strings cannot be anagrams anyways, so we return false. Else, we decrease its 
// current frequency from the HashMap"

//  Secondly, let’s consider if we can design a hash function which will give the same value for two strings if they 
// are anagram of each other. In anagrams, only frequency matters, thus we can sort the strings through the 
// hash function, i.e. hash(str) = sort(str). Now if hash(str1) = hash(str2) means str1 and str2 are anagrams.


//other approach can be two use two vector to store the frequency of a-z  for both the strings and then compare


bool checkAnagram(string s1,string s2){
    //check the size of the strings first
    if(s1.size()!=s2.size()){
        return false;
    }
    //create a map to store the frequency of any one string

    unordered_map<char,int> m;

    //store the frequency
    for(auto c1:s1){
        m[c1]++;
    }

    //now traverse the second string
    for(auto c2:s2){
        //firstly check if it is not present 
        if(m.find(c2)==m.end()){
            return false;
        }
        else{
            //reduce the frequency of the char
            m[c2]--;
        }
    }

    //now check if m's second elements are empty or not
    for(auto ele:m){
        if(ele.second!=0){
            return false;
        }
    }

    return true;
}




int main(){

    //taking two strings input 
    string s1,s2;
    cin>>s1>>s2;

    if(checkAnagram(s1,s2)){
        cout<<"Anagram"<<endl;
    }
    else{
        cout<<"Not Anagram"<<endl;
    }



    return 0;
}


//time complexity o(n) where n is length of s1 +length of s2