//SHAKER SORT

#include <iostream>
#include <fstream>
using namespace std;



int main(){
    int n;
    ifstream file("input_1.txt");
    file>>n;
    float *arr = new float[n];

    for(int i=0;i<n;i++)
        file>>arr[i];
    file.close();
    
    int i=1;

    int end = n-1;
    int start = 1;
    bool isSwapped = true;
    while(isSwapped)
    {
        isSwapped=false;
        int tempStart = start;
        for(int j=end;j>=tempStart;j--)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
                start = j;
                isSwapped = true;
            }
        }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        int tempEnd = end;
        for(int j=start;j<=end;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                end = j;
                isSwapped = true;
            }
        }
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}