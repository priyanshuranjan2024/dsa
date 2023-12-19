#include<bits/stdc++.h>
using namespace std;

//ques
// The task is to find the smallest number with given sum of digits as S 
//and number of digits as D.

// Example 1:

// Input:

// S = 9 

// D = 2

// Output:

// 18

void smallestNumber(int d,int s){
    vector<char> v(d,'0');
    //corner case if it is not possible to make such a number 
    //that is 9*d<s
    if(9*d<s){
        cout<<"-1"<<endl;
        return;
    }
    
    s--;


    int i;
    for( i=d-1;i>=0;i--){
        if(s<9){
            break;
        }

        v[i]='9';
        s-=9;
        
    }
    
    v[0]='1';
    v[i]=char(s+'0');

    //now print the number
    for(int j=0;j<v.size();j++){
        cout<<v[j]<<"";
    }
}

int main(){

    int d,s;
    cin>>d>>s;

    smallestNumber(d,s);


    

    return 0;
}