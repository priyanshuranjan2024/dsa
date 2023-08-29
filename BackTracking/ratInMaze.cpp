#include<iostream>
using namespace std;


bool isSafe(int** arr,int x,int y,int n){//function to decide whether rat could go to that place or not


    if(x<n && y<n && arr[x][y]==1){
        return true;
    }

    return false;

}

//now the important function
bool ratInMaze(int** arr,int x,int y,int n,int**  solArr){

    //base condition that rat reached the end
    if(x==(n-1) && y==(n-1)){
        solArr[x][y]=1;
        return true;

    }


    
    if(isSafe(arr,x,y,n)){
        solArr[x][y]=1;
        //recursive call
        //checking if solution present in right direction
        if(ratInMaze(arr,x+1,y,n,solArr)){
            return true;
        }


        //checking solution present in downward direction
        if(ratInMaze(arr,x,y+1,n,solArr)){
            return true;
        }


        //if not found then backtrak
        solArr[x][y]=0;
        return false;


    }


    //not found then return false
    return false;


}

int main(){



    int n;//size of the 2d array
    cin>>n;


    
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];//dynamic memory allocation of 2d array
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    //initialising the solArr
    int** solArr=new int*[n];
    for(int i=0;i<n;i++){
        solArr[i]=new int[n];//dynamic memory allocation of 2d array
        //initiasing them with 0
        for(int j=0;j<n;j++){
            solArr[i][j]=0;
        }
    }
    cout<<endl;//for printing puroose only
    

    if(ratInMaze(arr,0,0,n,solArr)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
        }
    }


    return 0;


}

// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1