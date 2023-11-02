#include<bits/stdc++.h>
using namespace std;


// Given an array arr[] of length N, find the length of the longest subarray with a sum equal to 0.


//approach
//1.brute force using nested loop with time complexity of o(n^2)

//2.find the prefix sum array of the array then make a map with the unique prefix sum and its value
//then do the needy

int maxZeroSubArrayLength(vector<int> &v){
    unordered_map<int,int> m;//to store the prefix sum and its position
    int prefixSum=0;
    int maxLen=0;//because no such present then size will be 0 don't take int_min

    for(int i=0;i<v.size();i++){
        //first calulate the prefixSum for the element
        prefixSum+=v[i];
        //check if the prefixSum is zero
        if(prefixSum==0){
            maxLen++;
        }

        if(m.find(prefixSum)!=m.end()){
            //aleready present in the map
            maxLen=max(maxLen,i-m[prefixSum]);

        }
        else{
            //if not present then add it to the map
            m[prefixSum]=i;
        }
    }

    return maxLen;
    

}



int main(){

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<maxZeroSubArrayLength(v)<<endl;  
//     8
// 15 -2 2 -8 1 7 10 23
// 5


    return 0;
}