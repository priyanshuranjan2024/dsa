#include<iostream>
using namespace std;
//move all x to the end of this string
string moveAllX(string s){
    if(s.length()==0){
        return "";
    }

    char ch=s[0];
    string ans=moveAllX(s.substr(1));
    if(ch=='x'){
        return ans+ch;
    }
    return ch+ans;
}




int main(){
    string s;
    cin>>s;
    cout<<moveAllX(s)<<endl;
    return 0;
}