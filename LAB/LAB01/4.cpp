// CONVEX HULL

#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;

struct point{
    float x,y;
};

int main()
{
    ifstream file("input_4.txt");
    int n;
    file>>n;
    point extremePoint;
    extremePoint.x = INT_MAX;
    extremePoint.y = INT_MAX;
    vector<point> points(n);
    for(int i=0;i<n;i++)
    {
        file>>points[i].x;
        file>>points[i].y;
        if(extremePoint.y>points[i].y)
        {
            extremePoint= points[i];
        }
        else if(extremePoint.y==points[i].y)
        {
            if(extremePoint.x>points[i].x)
            {
                extremePoint= points[i];
            }
        }
    }
    cout<<endl;
    cout<<extremePoint.x<<" "<<extremePoint.y<<endl;
    return 0;
}