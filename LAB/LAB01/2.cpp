// SUBSEQUENCE WITH LARGEST SUM

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("input_2.txt");
    int n;
    file>>n;
    float value;
    vector<float>arr;
    while(file>>value)
    {
        arr.push_back(value);
    }
    file.close();
    int start=-1,end=-1;
    float sum = 0,maxSum;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]<arr[i])
        {
            sum=arr[i];
            start=i;
        }
        else
        {
            sum+=arr[i];
            if(maxSum<sum)
            {
                maxSum=sum;
                end=i;
            }
        }
    }
    if(start==-1)
    {
        cout<<"\n"<<maxSum;
    }
    else
    {
        for(int i=start;i<=end;i++)
            cout<<arr[i]<<" ";
        cout<<"\n"<<maxSum;
    }
    return 0;
}