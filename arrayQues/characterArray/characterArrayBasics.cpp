#include<iostream>
using namespace std;
int main(){
    char arr[100];//better to take a large size
    cin>>arr;//inputing something
    cout<<arr<<endl;//outputing someting
    cout<<arr[2]<<endl;//accessing an element
    //printing each element separately
    int i=0;
    while(arr[i]!='\0'){//use ' ' operator
        cout<<arr[i]<<endl;
        i++;
    }
    return 0;
}