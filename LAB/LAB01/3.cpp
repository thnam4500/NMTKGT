// THE CHANGE-MAKING PROBLEM

#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int>result;

void combination(vector<int>&arr,vector<int>&count,int i,vector<int>&comb,int&target,int&currentMinCoin){
    if(i==count.size())
    {  
        int sum=0;
        int currentCoins = 0;
        for(int i=0;i<comb.size();i++)
        {
            sum+=comb[i]*arr[i];
            currentCoins+=comb[i];
        }
        if(sum==target&&currentCoins<currentMinCoin)
        {
            result=comb;
            currentMinCoin=currentCoins;
        }
    }
    else{
        for(int j=0;j<=count[i];j++)
        {
            comb[i]=j;
            combination(arr,count,i+1,comb,target,currentMinCoin);
        }
    }
}

int main(){
    int target;
    vector<int>arr;
    ifstream file("input_3.txt");
    int input;
    while(file>>input)
    {
        arr.push_back(input);
    }
    target = arr.back();
    arr.pop_back();
    
    vector<int>count(arr.size(),0);
    for(int i=0;i<count.size();i++)
    {
        count[i]=target/arr[i];
    }

    
    vector<int>comb(count.size(),0);
    int currentMinCoin = INT_MAX;
    combination(arr,count,0,comb,target,currentMinCoin);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<": "<<result[i]<<endl;
    }
    return 0;
}