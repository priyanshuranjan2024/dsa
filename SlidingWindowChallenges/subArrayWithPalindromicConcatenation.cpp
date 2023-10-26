#include<bits/stdc++.h>
using namespace std;

//for a given array and an integer k,
//check if any subarray of size k
//exits in thearray such that concatenation
//of elements form a palindrome.

//the stub function

bool isPalindrome(int num){
    int temp=num;
    int number=0;

    while(temp>0){
        number=number*10+temp%10;
        temp=temp/10;
    }

    if(number==num){
        return true;
    }
    
    return false;

}


//the function will return the starting point of the k sized array which makes the conditions fulfilled
int findPalindromicSubArray(vector<int> arr,int k){
    int num=0;//the number we will store for palindrome
    
    for(int i=0;i<k;i++){
        num=10*num+arr[i];

    }

    if(isPalindrome(num)){
        return 0;//first index
    }

    //now do it on other sliding window
    for(int j=k;j<arr.size();j++){
        //remove the first element and add the end element
        //for sliding window
        num=(num%(int)pow(10,k-1))*10+arr[j];//first operand will remove the first element from the num

        if(isPalindrome(num)){
            return j-k+1;
        }
    }

    return -1;//if palindrome is never found in the original array
}

int main(){
    vector<int> arr={2,3,5,1,1,5};
    int k=4;
    int idx=findPalindromicSubArray(arr,k);
    if(idx==-1){
        cout<<"No such palindrommic subarray exits"<<endl;
    }
    else{
        //print the subarray
        for(int i=idx;i<idx+k;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}