#include<iostream>
using namespace std;

//generate all the substrins of the string recursively
void subString(string s,string ans){
    //base condition
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch=s[0];
    string ros=s.substr(1);


    subString(ros,ans);//one call for not printing the next one
    subString(ros,ans+ch);//one call for  printing the other character
}



int main(){
    string s;
    cin>>s;
    subString(s,"");
    cout<<endl;

    return 0;
}