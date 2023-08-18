/*this  program deals with how to convert the string into upper or lowercase*/

#include "bits/stdc++.h"
using namespace std;
int main(){
    // //doing  manually using the concept 'a'-'A'=32
    // string str="asdf";
    // string str1="ASDF";
    // //converting into uppercase
    // for(int i=0;i<str.size();i++){
    //     if(str[i]>='a' && str[i]<='z'){
    //         str[i]-=32;
    //     }
    // }
    // cout<<str<<endl;
    // //converting into lowercase
    // for(int i=0;i<str1.size();i++){
    //     if(str1[i]>='A' && str1[i]<='Z'){
    //         str1[i]+=32;
    //     }
    // }
    // cout<<str1<<endl;


    //doing it using inbuilt function
    
    string str="roHan";
    transform(str.begin(),str.end(),str.begin(),::toupper);
    cout<<str<<endl;

    transform(str.begin(),str.end(),str.begin(),::tolower );
    cout<<str<<endl;

    return 0;
}