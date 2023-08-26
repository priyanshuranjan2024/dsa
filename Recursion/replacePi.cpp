#include<iostream>
using namespace std;
//replace pi with 3.14 in the string
//pipipcoxoxpipipipx
void replacePi(string s){
    if(s.length()==0){//base condition
        return;
    }
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replacePi(s.substr(2));
    }
    else{
        cout<<s[0];
        replacePi(s.substr(1));
    }


}
    


int main(){
    string s;
    cin>>s;
    replacePi(s);
    return 0;
}