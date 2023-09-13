#include<iostream>
#include<stack>
using namespace std;


//this approach uses 2 stack to do this thing therefore pushing is not costly but pop() is costly by reference to time complexity


// class queue{
//     stack<int> s1;
//     stack<int> s2;

//     public:
//     void push(int x){
//         //push only in stack 1
//         s1.push(x);
//     }

//     int pop(){
//         if(s1.empty() && s2.empty()){
//             cout<<"Queue is empty"<<endl;
//             return -1;
//         }

//         if(s2.empty()){
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }

//         int topval=s2.top();
//         s2.pop();
//         return topval;

//     }

//     bool empty(){
//         if(s1.empty() && s2.empty()){
//             return true;
//         }

//         return false;
//     }


// };





//now using recursion to pop() basically we will just pop the element from the stack then 
//if stack is empty we will print that if not we will recursively pop and store it in item variable then push the item variable 
//and then return the item

class queue{
    stack<int> s1;
    
    

    public:
    void push(int x){
        //push only in stack 1
        s1.push(x);
    }

    int pop(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int x=s1.top();
        s1.pop();

        if(s1.empty()){
            return x;
        }

        int item=this->pop();
        s1.push(x);
        return item;



    }

    bool empty(){
        if(s1.empty()){
            return true;
        }

        return false;
    }


};


int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

    cout<<q.empty()<<endl;
    return 0;
}