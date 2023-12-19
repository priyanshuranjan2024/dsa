#include<bits/stdc++.h>
using namespace std;
#define ll long long int


//ques
// A board of length M and width N is given. The task is to break this board into M * N squares such that cost of 
// breaking is minimum. The cutting cost for each edge will be given for the board in two arrays X[] and Y[] 
// representing the cost of cutting horizontal and vertical edges respectively, i.e X[i] represents the cost of cutting 
// a horizontal edge of size i. In short, you need to choose such a sequence of cutting such that cost is minimized. 
// Return the minimized cost.

// Input:

// M = 6. N = 4

// X[] = {2, 1, 3, 1, 4}

// Y[] = {4, 1, 2}

//answer is 42


// The values of M and N are positive integers.

bool cmp(int x,int y){
    return x>y;
}


ll minBreakCost(int n,int m,vector<ll> &vertical,vector<ll> &horizontal){
    //firstly sort the array X and Y in decreasing order
    sort(vertical.begin(),vertical.end(),cmp);
    sort(horizontal.begin(),horizontal.end(),cmp);

    //create two variables to keep track of the no. of blocks
    int hori_blocks=1;
    int verti_blocks=1;

    //now use the two pointers approach
    int h=0;
    int v=0;

    ll ans=0;

    while(h<horizontal.size() and v<vertical.size()){
        if(vertical[v]>horizontal[h]){
            ans+=vertical[v]*verti_blocks;
            //now update the values
            hori_blocks++;

            v++;

        }
        else{
            ans+=horizontal[h]*hori_blocks;
            //now update the values
            verti_blocks++;
            h++;
        }
    }

    //for the case if one array is exhausted first
    while(h<horizontal.size()){
        ans+=horizontal[h]*hori_blocks;
        verti_blocks++;
        h++;
    }
    while(v<vertical.size()){
        ans+=vertical[v]*verti_blocks;
        hori_blocks++;
        v++;
    }

    return ans;


}





int main(){

    int n,m;
    cin>>m>>n;

    vector<ll> vertical,horizontal;
    
    for(int i=0;i<m-1;i++){
        int x;
        cin>>x;
        vertical.push_back(x);
    }

    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        horizontal.push_back(x);
    }

    cout<<minBreakCost(n,m,vertical,horizontal)<<endl;


    return 0;
}