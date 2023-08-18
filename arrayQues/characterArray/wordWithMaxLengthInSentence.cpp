#include<iostream>
using namespace std;
int main(){
    int n;//no. of characters
    cin>>n;
    cin.ignore();//for clearing the buffer
    char arr[n+1];
    cin.getline(arr,n);
    


    int currLength=0,maxLength=0;
    int i=0;
    int st=0,maxst=0;//for printing the largest word
    while(true){
        if(arr[i]==' ' || arr[i]=='\0'){
            if(currLength>maxLength){
                maxLength=currLength;
                maxst=st;
                
            }
            st=i+1;
            currLength=0;
        }
        else
        currLength++;



        if(arr[i]=='\0'){
            break;

        }
        i++;
    }
    cout<<maxLength<<endl;
    for(int i=0;i<maxLength;i++){
        cout<<arr[i+maxst];
    }
    return 0;
}
//test against do or die