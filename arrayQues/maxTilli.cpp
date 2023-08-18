//given an array of size n.for every i from 0 to n-1
//output max(a[0],...,a[i])
//approach
//create a variable max and iterate from 0 to i and update the max using max()



#include <iostream>
#include<climits>
using namespace std;
int main(){
    //array
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int arrMax=INT_MIN;
    int key;
    cin>>key;//value of i
    for(int i=0;i<key;i++){
        arrMax=max(arr[i],arrMax);
    }
    cout<<arrMax;

    return 0;
}