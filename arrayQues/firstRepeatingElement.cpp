//problem 
// given an aray of size n. the task is to find the first
// repeating element in the array of integers i.e an element 
// that oxxurs more than once and whose
// index of fist occurence is smallest



#include <iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];

    }


    const int N=1000;//will not work in vs code because of memory issue i guess
    int idx[N];
    for(int i=0;i<N;i++){
        idx[i]=-1;
    }

    int minidx=INT_MAX;

    for(int i=0;i<n;i++){
        if(idx[a[i]]!=-1){
            minidx=min(minidx,idx[a[i]]);
        }
        else{
            idx[a[i]]=i;

        }
    }

    if(minidx==INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<<minidx+1<<endl;
    }
    return 0;
    //7 1 5 3 4 3 5 6

    
    
    


}