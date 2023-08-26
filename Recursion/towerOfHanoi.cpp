#include<iostream>
using namespace std;

void towerOfHanoi(int n,char src,char dest,char help){
    if(n==0){
        return;//base case
    }
    towerOfHanoi(n-1,src,help,dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,help,dest,src);


}
int main(){
    towerOfHanoi(3,'A','C','B');
    return 0;

}