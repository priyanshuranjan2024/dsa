#include<bits/stdc++.h>
using namespace std;

//given n activites with their start and finish day given in array start[] and end[].
//select the maximum number of acitivies that can be performed by a single person,assuming that a person can only work on a single activity at a given day.
//note:duration of the activity includes both starting and ending day.

//same as that of maxMeetingProblem

struct activity
{
    int start;
    int end;

};

//firstly create the custom comparator

bool cmp(activity a1,activity a2){
    return a1.end<a2.end;//to sort the array in the ascending order
}

int maxActivityPerformed(vector<activity> &arr){
    sort(arr.begin(),arr.end(),cmp);

    
    int count=1;//this will be our last answer since first one will be always there
    activity last=arr[0];//for traversing and checking
   

    for(int i=1;i<arr.size();i++){
        if(arr[i].start>last.end){
            count++;
            
            last=arr[i];
        }
    }

    return count;

}




int main(){
    int n;
    cin>>n;
    vector<activity> v;
    while(n--){
        int s,e;
        cin>>s>>e;
        activity a;
        a.start=s;
        a.end=e;
        v.push_back(a);
    }

    // cout<<maxActivityPerformed(v)<<endl;
    cout<<maxActivityPerformed(v)<<endl
    ;

    return 0;
}


//this is having some problem
//problem solved take the vector without defining length in main() function

//input
// 4
// 1 2
// 3 4
// 2 3
// 5 6