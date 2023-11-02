#include<bits/stdc++.h>
using namespace std;

// Given an array of strings. You can move any number of characters from one string to any other string any 
// number of times. You just have to make all of them equal.  


// Print “Yes” if you can make every string in the array equal by using any number of operations otherwise print 
// “No”.


//firstly there is no need to transform the strings of each element of the array
//each character should be present as a multiple of the size of the array
//This can be done by simply counting each character in all the 
// strings. If each character is present in multiples of the size of the array of strings, then it is pretty clear that we 
// can evenly divide it among all the strings thus making all the strings equal.


//time complexity o(n) where n is no of char in all strings combined


bool canMakeEqual(vector<string> &v){
    //create a unordered map
    unordered_map<char,int> m;
    for(auto str:v){
        //traverse all the char
        for(char c:str){
            m[c]++;
        }
    }

    //now we can check if it is multiple of v.size()

    int n=v.size();
    for(auto ele:m){
        if(ele.second%n!=0){
            //that it is  not multiple of the n
            return false;
            
        }
    }

    return true;


}


int main(){

    int n;
    cin>>n;

    vector<string> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];

    }

    bool ans=canMakeEqual(v);

    if(ans==true){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }



    return 0;
}