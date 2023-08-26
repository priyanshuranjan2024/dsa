#include<iostream>
using namespace std;

//print all possible permutations of a string using recursion
//logic is to fix one character and call function on others

//test for abc

void permuation(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;//base case
    }

    for(int i=0;i<s.length();i++){
        char ch=s[i];//fixing one character
        string ros=s.substr(0,i)+s.substr(i+1);

        permuation(ros,ans+ch);
    }
}

int main(){
    string s;
    cin>>s;
    permuation(s,"");
    return 0;
}