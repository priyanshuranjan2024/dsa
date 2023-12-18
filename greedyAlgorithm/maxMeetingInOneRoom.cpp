#include<bits/stdc++.h>
using namespace std;

//font size at the beginning was 14

//ques
// There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of 
// meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can 
// be accommodated in the meeting room. Print all meeting numbers.

//firstly create a sturct called meeting holding start and end time of the meeting
//also it will contain the idx of the meeting as we have to print it

struct meeting
{
    int start;
    int end;
    int idx;

};

//create a custom comparator which will compare the meeting end time and sort the vector in 
//increasing order

bool cmp(meeting m1,meeting m2){
    return m1.end<m2.end;
}


void print_maxMeeting(vector<meeting> &arr){
    //firstly sort the vector using custom cmp
    sort(arr.begin(),arr.end(),cmp);
    //will always consider the first meeting
    cout<<arr[0].idx<<" ";
    //create a variable for the last meeting taken
    meeting last=arr[0];
    //traverse the sorted array
    for(int i=1;i<arr.size();i++){
        //check whether next meeting start time is greater than last meeting end time
        if(arr[i].start>last.end){
            cout<<arr[i].idx<<" ";
            last=arr[i];


        }

    }

}


int main(){
    int n;
    cin>>n;
    vector<meeting> arr;
    int i=0;//idx
    while(n--){
        int s,e;
        cin>>s>>e;
        i++;
        meeting m;
        m.start=s;
        
        m.end=e;
        m.idx=i;

        arr.push_back(m);

    }

    print_maxMeeting(arr);





    return 0;
}

//input
// 6
// 1 2
// 3 4
// 0 6
// 5 7
// 8 9
// 5 9

//output 
// 1 2 4 5
