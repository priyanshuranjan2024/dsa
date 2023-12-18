#include<bits/stdc++.h>
using namespace std;

// Given the weights and profits of N items, in the form of {profit, weight} put these items in a knapsack of 
// capacity W to get the maximum total profit in the knapsack. In Fractional Knapsack, we can break items for 
// maximizing the total value of the knapsack.


//mainly sort the contents using the custom comparator that is value/weight and then using it to add in the answer if it is less than total weight otherwise fractional weight and
//fractional profit because it is fractional knapsack

struct Item
{
    int profit;
    int weight;
    
};



//creating a custom comparator for sorting with respect to  profit/weight ratio
bool compareItems(const Item &item1,const Item &item2){
    double ratio1=static_cast<double>(item1.profit)/item1.weight;
    double ratio2=static_cast<double>(item2.profit)/item2.weight;

    return ratio1>ratio2;

}

//main function for fractional knapsack
double fractionalKnapsack(int W,vector<Item>& items){
    double ans=0;
    //firstly sort
    sort(items.begin(),items.end(),compareItems);//using custom comparators

    for(const auto &item:items){
        if(item.weight<=W){
            ans+=item.profit;
            W-=item.weight;
        }
        //else fractional 
        else{
            //when we can't put the whole weight in the knapsack we will put fractional knapsack
            
            double fration=static_cast<double> (W)/item.weight;
            ans+=fration*item.profit;
            W=0;
        }

    }

    return ans;



}


int main(){

    int n,W;
    cin>>n>>W;
    vector<Item> items(n);
    for(int i=0;i<n;i++){
        int profit,weight;
        cin>>profit>>weight;
        Item it;
        it.profit=profit;
        it.weight=weight;
        items.push_back(it);
    }

    cout<<fractionalKnapsack(W,items)<<endl;

    return 0;
}

// 3  50
// 60 10    
// 100 20 
// 120 30
// 240