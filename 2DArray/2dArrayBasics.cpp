#include<iostream> 
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];//declaring a 2-d array
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];//taking input 
        }
    }

    //printing the matrix
    cout<<"Matrix is"<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }


    
    //searching for element in matrix
    int x;
    cin>>x;
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==x){
                flag=true;
            }
            
        }
    }

    if(flag){
        cout<<"Element found in the matrix"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

    
    return 0;
}