#include<bits/stdc++.h>
using namespace std;
//place n queen in nxn chess board such that no 2 queen attack each other

//function to check if the box is safe or not
bool isSafe(int** arr,int x,int y,int n){
    //checking for column
    for(int row=0;row<n;row++){
        if(arr[row][y]==1){
            return false;
        }
    }

    //checking for left diagonal
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    //checking for right diagonal
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }

    //if all safe then
    return true;

}


//column not needed
bool nQuenn(int** arr,int x,int n){
    //base case
    if(x>=n){
        return true;
    }

    for(int col=0;col<n;col++){
        //checking if it is safe
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;

            if(nQuenn(arr,x+1,n)){
                return true;
            }
            //otherwise

            arr[x][col]=0;//backtracking


        }
    }
    return false;//if we cannot place the queen in any column

}

int main(){
    int n;
    cin>>n;

    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }


    if(nQuenn(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;

    
}