#include<bits/stdc++.h>
using namespace std;


//ques
// You are a person on an island. There is only one shop in this island, this shop is open on all days of the week 
// except for Sunday. Consider following constraints: 


// S – Number of days you are required to survive.

// N – Maximum unit of food you can buy each day.

// M -  Unit of food required each day to survive.


// Currently, it’s Monday, and you need to survive for the next S days. 


// Find the minimum number of days on which you need to buy food from the shop so that you can survive the 
// next S days, or determine that it isn’t possible to survive. 


bool isSurvival(int s,int n,int m){
    double total_Food=(s-s/7)*n;//total food that can be bought
    double totalFoodRequired=s*m;

    if(total_Food<totalFoodRequired){
        return false;
    }

    return true;


}


//function to calculate minuimum no. of days we require to buy food
//we will not wait for food to finish but we will buy all the food required

int minimumNoOfDays(double s,double n,double m){
    if(!isSurvival(s,n,m)){
        return -1;//that is not possible to survive
    }

    //otherwise
    return ceil(s*m/n);
}



int main(){
    double s,n,m;
    cin>>s>>n>>m;
    cout<<minimumNoOfDays(s,n,m)<<endl;
    

    return 0;
}


//this will work only if you take double as input not int as ceil works only on double


