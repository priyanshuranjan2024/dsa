#include<bits/stdc++.h>
using namespace std;


bool isPossible(int arr[], int n,int m, int min){
    int studentRequired=1;
    int sum=0;//page alloted to a single student
    for(int i=0;i<n;i++){
        if(arr[i]>min){
            //if pages is greater then min possible then return false
            return false;
        }
        if(sum+arr[i]>min){
            //means that we will need a new student
            studentRequired++;
            sum=arr[i];//for new student
            if(studentRequired>m){
                return false;
            }
        }
        else{
            //if pages are still less than min
            sum+=arr[i];

        }

    }

    return true;
    


}

int allocateMinimumPages(int arr[],int n,int m){
    //n represents  the number of books and m represents the number of studentsand n also represents the size of array
    int sum=0;//for defining the range of binary search which will be equal to the sum of all elements in the array
    //if n<m no appropriate solution can be given so lets make a case for it
    if(n<m){
        return -1;
    }

    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }

    int start=0;//student is getting nothing
    int end=sum;//student is getting everything

    int ans=INT_MAX;//the thing we have to return

    //start the binary search
    while (start<=end)
    {
        int mid=(start+end)/2;
        if(isPossible(arr,n,m,mid)){
            //if it is true
            ans=min(mid,ans);
            //now i wil search for a more minimum value 
            end=mid-1;
        }
        else{
            //search in right side of mid
            start=mid+1;
        }
    }

    return ans;
    

}

int main(){
    int arr[]={12,34,67,90};
    int n=4;
    int m=2;
    cout<<allocateMinimumPages(arr,n,m)<<endl;

    return 0;
}