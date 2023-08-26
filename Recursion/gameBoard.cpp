#include<iostream>
using namespace std;
//count the number of paths possible from starting point to ending point in gameboard

int gameBoard(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }

    int count=0;//to count the number of paths
    //i will be the number on dice
    for(int i=1;i<=6;i++){
        count+=gameBoard(s+i,e);
    }
    return count;

}


int main(){
    int s,e;
    cin>>s>>e;
    cout<<gameBoard(s,e)<<endl;
    
    return 0;
}