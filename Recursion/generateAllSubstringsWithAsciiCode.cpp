#include<iostream>
using namespace std;
//generate all substring of the given string once normally once with its ascii code
//will use 3 recursive call in place of 2 as used in generateAllSubstrings.cpp
void subString(string s,string ans){
    //base condition
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    string ros=s.substr(1);
    int code=ch;//ascii code

    //3 recursive call
    subString(ros,ans);
    subString(ros,ans+ch);
    subString(ros,ans+to_string(code));

}


int main(){
    string s;
    cin>>s;
    subString(s,"");
    return 0;
}