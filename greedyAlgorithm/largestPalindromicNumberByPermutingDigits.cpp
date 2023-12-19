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

    vector<char> v(l);
    int front=0;
    for(int i=9;i>=0;i--){
        //firstly check if it is a odd frequency element then we will place it at the middle
        if(mp[i]%2!=0){
            v[l/2]=char(i+48);//this is to convert i into char as 48 is the ascii of 0
            mp[i]--;
            
        }

        //for the other elements
        while(mp[i]>0){
            v[front]=char(i+48);//place the character at the most significant place
            v[l-front-1]=char(i+48);//place the same character at the least significant place
            //now reduce the frequency by 2 and increase front by 1
            mp[i]-=2;

            front++;


        }

        
    }

    //now make a string res from the vector obtained
    string res="";
    for(int i=0;i<l;i++){
        res+=v[i];
    }

    return res;


    
}

int main(){
    cout<<maxPalindrome("232")<<endl;
    
    
    return 0;
}
