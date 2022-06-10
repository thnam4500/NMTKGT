// CONVEX HULL

#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <unordered_set>
using namespace std;

const double PI = 3.14159265;

struct point{
    double x,y;
};

double computeAngle(const point &from,const point &to)
{
    double angle = atan2(to.y-from.y, to.x-from.x);
    if(angle < 0)
        angle+=2*PI;
    return angle;
}

int findNextPointIndex(vector<point>&points,int&curPointIndex,unordered_set<int>&inList)
{
    double minAngle = 2*PI;
    int nextIndex;
    for(int i=0;i<points.size();i++)
    {
        if(i==curPointIndex||inList.find(i)!=inList.end())
            continue;
        double angle = computeAngle(points[curPointIndex],points[i]);
        if(angle < minAngle)
        {
            minAngle = angle;
            nextIndex = i;
        }
    }
    inList.insert(nextIndex);
    return nextIndex;
}

int main()
{
    ifstream file("input_4.txt");
    int n;
    file>>n;
    point extremePoint;
    int extremePointIndex;
    extremePoint.x = INT_MAX;
    extremePoint.y = INT_MAX;
    vector<point> points(n);
    for(int i=0;i<n;i++)
    {
        file>>points[i].x;
        file>>points[i].y;
        if(extremePoint.y>points[i].y)
        {
            extremePoint = points[i];
            extremePointIndex = i;
        }
        else if(extremePoint.y==points[i].y)
        {
            if(extremePoint.x>points[i].x)
            {
                extremePoint = points[i];
                extremePointIndex = i;
            }
        }
    }

    vector<int> convexHullPoints;
    unordered_set<int> inList;
    convexHullPoints.push_back(extremePointIndex);
    while(true)
    {
        int curPointIndex = convexHullPoints.back();
        int nextIndex = findNextPointIndex(points,curPointIndex,inList);
        if(nextIndex==extremePointIndex)
            break;
        convexHullPoints.push_back(nextIndex);
    }

    for(int i=0;i<convexHullPoints.size();i++)
    {
        cout<<"("<<points[convexHullPoints[i]].x<<" , "<<points[convexHullPoints[i]].y<<") ";
    }
    return 0;
}