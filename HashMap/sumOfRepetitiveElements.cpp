#include<bits/stdc++.h>
using namespace std;

//You are given an integer n, representing the number of elements. 
//Then, you will be given n elements.
// You have to return the sum of repetitive elements i.e. the elements that appear more than one time.


//approach make a map which will store number and its frequency in the array or the vector and then find the elements 
//which have frequency more than one


int main(){
    //taking the size of the array
    int n;
    cin>>n;
    int arr[n];


    //taking input of the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //now create a map to store the elements and its frequency
    map<int,int> m;
    for(int i=0;i<n;i++){
        //storing the frequency
        m[arr[i]]++;//will create for eg m[1]++ will insert in the map [1,1]
    }

    int sum=0;
    for(auto pair:m){
        //taking the sum of the repeatitive elements in the array
        if(pair.second>1){
            sum+=pair.first;
        }
    }

    cout<<"Answer is "<<sum<<endl;



    return 0;
}