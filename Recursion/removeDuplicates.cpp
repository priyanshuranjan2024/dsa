#include<iostream>
using namespace std;
//remove all duolicates from the string
string removeDup(string s){
    if(s.length()==0){
        return "";//base case
    }

    char ch=s[0];
    string ans=removeDup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    else{
        return (ch+ans);
    }

}


int main(){
    string s;
    cin>>s;
    cout<<removeDup(s)<<endl;
    return 0;
}