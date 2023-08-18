#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    //create a variable sum and a originalNumber
    int sum=0;
    int originalNumber=n;
    while(n>0){
        int lastNumber=n%10;
        sum+=lastNumber*lastNumber*lastNumber;
        n=n/10;


    }   
    if(sum==originalNumber){
        cout<<"Yes it is armstrong number";
    } 
    else{
        cout<<"No it is not armstrong number";
    }
    return 0;
}