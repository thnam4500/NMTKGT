// KNAPSACK PROBLEM

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void solve(string str, vector<int>&weights,vector<int>&values,int&maxWeight,string&result,int&currentValue)
{
    if(str.size()==weights.size())
    {
        int totalWeight = 0;
        int totalValues = 0;
        for(int i=0;i<weights.size();i++)
        {
            totalWeight += weights[i]*(str[i]-'0');
            totalValues += values[i]*(str[i]-'0');
        }
        if(totalWeight<=maxWeight)
        {
            if(totalWeight>currentValue)
            {
                result=str;
                currentValue=totalValues;
            }
        }
    }
    else{
        solve(str+"0",weights,values,maxWeight,result,currentValue);
        solve(str+"1",weights,values,maxWeight,result,currentValue);
    }
}

int main(){
    ifstream file("input_6.txt");
    int W,n;
    file>>W>>n;
    vector<int>weights(n,0);
    vector<int>values(n,0);
    for(int i=0;i<n;i++)
    {
        file>>weights[i]>>values[i];
    }
    int currentValue=0;
    string result="";
    solve("",weights,values,W,result,currentValue);
    for(int i=0;i<result.size();i++)
    {
        if(result[i]-'0')
        {
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    cout<<currentValue;
    return 0;
}