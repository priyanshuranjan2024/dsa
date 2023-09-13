#include<iostream>
#include<queue>
using namespace std;


//there are two methods for this one is by making push costly other is by  making pop() costly

// //method 1: making the push costly
// //we will add  new element in q2 and then pop() the elements from q1 and add it in q2 then swap

// class Stack{
//     int N;
//     queue<int> q1;
//     queue<int> q2;

//     public:

//     Stack(){
//         N=0;
//     }

//     void push(int val){
//         q2.push(val);
//         N++; //because we have pushed one element

//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }

//         //now swap q1 and q2;

//         queue<int> temp=q1;
//         q1=q2;
//         q2=temp;

//     }

//     void pop(){
//         q1.pop();
//         N--;
//     }

//     int top(){
//         return q1.front();
//     }

//     int size(){
//         return N;
//     }

    


// };

// int main(){

//     Stack st;

//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);

//     cout<<st.top()<<endl;
    

    
//     return 0;
// }



//method 2: making pop() costly
//pop() and push in q2 from q1 till its size is 1 and then pop the last element in q1 and then swap q1 and q2

class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    Stack(){
        int N=0;
    }

    void pop(){
        //check first if q is empty
        if(q1.empty()){
            return;
        }

        while(q1.size()!=1){
            q2.push(q1.front());

            q1.pop();
            

        }

        q1.pop();//pop  the last one element
        N--;

        //now swap the queues
        queue<int> temp=q1;
        q1=q2;
        q2=temp;


    }


    void push(int val){
        q1.push(val);
        N++;


    }

    int top(){
        if(q1.empty()){
            return -1;
        }

        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        int ans=q1.front();//that is the last element

        q2.push(ans);//now q2 is like the old q1 so let's swap it again and return ans

        queue<int> temp=q1;
        q1=q2;
        q2=q1;

        return ans;

    }

    int size(){
        return N;
    }

};


int main(){

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;



    return 0;
}