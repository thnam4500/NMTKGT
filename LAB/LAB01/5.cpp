// TRAVELING SALESMAN PROBLEM

#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;

int process(vector<vector<int>>&matrix, vector<int>&arr)
{
    int dist=0;
    for(int i=0;i<arr.size();i++)
    {
        if(matrix[arr[i]][arr[(i+1)%arr.size()]]==0)
        {
            return INT_MAX;
        }
        else
            dist+=matrix[arr[i]][arr[(i+1)%arr.size()]];
    }
    return dist;
}

void permutation(vector<vector<int>>&matrix,vector<int>&arr,int pivot,vector<int>&result,int&currentDist)
{
    if(pivot==arr.size()-1)
    {
        int totalDist = process(matrix,arr);
        if(totalDist<currentDist)
        {
            result=arr;
            currentDist=totalDist;
        }
    }
    for(int i=pivot;i<arr.size();i++)
    {
        swap(arr[i],arr[pivot]);
        permutation(matrix,arr,pivot+1,result,currentDist);
        swap(arr[i],arr[pivot]);
    }
}

int main()
{
    ifstream file("input_5.txt");
    int n;
    file>>n;
    vector<vector<int>>matrix(n+1,vector<int>(n+1,0));
    int cityA,cityB,dist;
    file>>cityA;
    while(cityA!=-1)
    {
        file>>cityB;
        file>>dist;
        matrix[cityA][cityB]=dist;
        matrix[cityB][cityA]=dist;
        file>>cityA;
    }
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        arr[i]=i+1;
    }
    vector<int>result;
    int currentDist=INT_MAX;
    permutation(matrix,arr,0,result,currentDist);
    for(int x:result)
        cout<<x<<" ";
    cout<<"\n"<<currentDist;
}