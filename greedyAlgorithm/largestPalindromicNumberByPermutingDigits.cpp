#include<bits/stdc++.h>
using namespace  std;

// Given N(very large), the task is to print the largest palindromic number obtained by permuting the digits of N. If 
// it is not possible to make a palindromic number, then print an appropriate message

bool isPossible(unordered_map<int,int> &mp){
    int count=0;//no. of digits with odd frequency
    for(int i=0;i<=9;i++){
        //firstly check if it is present in the map or not
        if(mp.count(i)){
            if(mp[i]%2!=0){
                count++;
            }
            if(count>1){
                return false;
            }
        }
    }

    return true;
}

string maxPalindrome(string num){
    int l=num.size();
    //create an unordered map
    unordered_map<int,int> mp;
    for(int i=0;i<l;i++){
        mp[num[i]-'0']++;
    }

    //call the isPossible  function
    if(!isPossible(mp)){
        return "Not Possible";
    }


    
}

int main(){
    
    return 0;
}
