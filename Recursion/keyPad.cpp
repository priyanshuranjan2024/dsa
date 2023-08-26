#include<iostream>
using namespace  std;
//print all posible words from phone digits
string keypad[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keyPad(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;//base case
        return;
    }

    char ch=s[0];//taking the number
    string code=keypad[ch-'0'];
    string ros=s.substr(1);
    for(int i=0;i<code.length();i++){
        keyPad(ros,ans+code[i]);
    }





}


int main(){
    string num;
    cin>>num;
    keyPad(num,"");
    return 0;
}
