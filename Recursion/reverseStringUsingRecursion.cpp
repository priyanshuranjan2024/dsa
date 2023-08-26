#include<iostream>
using namespace std;
//reverse a string recursively 
void reverse(string str){
    if(str.length()==0){  //base condition
        return;
    }

    string ros=str.substr(1);//rest of string
    reverse(ros);
    cout<<str[0];//here str is the one that will be called during the time


}



int main(){
    string str;
    cin>>str;
    reverse(str);
    return 0;
}