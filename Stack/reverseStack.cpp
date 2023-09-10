#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st,int ele){

    if(st.empty()){
        st.push(ele);
        return;
    }

    int topele=st.top();
    st.pop();

    insertAtBottom(st,ele);//recursive call

    //now inserting all using call stack
    st.push(topele);


}



void reverse(stack<int> &st){

    //base condition
    if(st.empty()){
        return ;
    }
    int ele=st.top();//element to be inserted at the bottom
    st.pop();

    reverse(st);

    insertAtBottom(st,ele);

}

int main(){

    stack<int> st;
    for(int i=1;i<5;i++){
        st.push(i);
    }

    reverse(st);
    
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}