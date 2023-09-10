#include<iostream>
using namespace std;

#define n 100

class stack{
    int* arr;
    int top;

    public:
    stack(){
        arr=new int[n];
        top=-1;
    }

    void push(int x){
        
        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return ;
        }

        top++;
        arr[top]=x;



    }

    void pop(){
        if(top==-1){
            cout<<"No elements present"<<endl;
            return;
        }

        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"No elements present"<<endl;
            return -1;
        }

        return arr[top];

    }

    bool empty(){
        return top==-1;//will return true if it is empty
    }


};


int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    return 0;
}