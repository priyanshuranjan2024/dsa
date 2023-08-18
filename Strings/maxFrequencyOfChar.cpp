#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str="ajfdafohrhasoklasghpoarhgathisisthenbestthingintheworld";
    int freq[26];
    for(int i=0;i<26;i++){
        freq[i]=0;
    }//initialising the  array with 0 as each sotrage

    for(int i=0;i<str.size();i++){
        freq[str[i]-'a']++;//will increase the frequency of that char
    }

    int maxChar=0;
    char ans='a';
    for(int i=0;i<26;i++){
        if(freq[i]>maxChar){
            maxChar=freq[i];
            ans=i+'a';
        }
    }
    cout<<maxChar<<" "<<ans<<endl;




    return 0;
}