#include<iostream>
#include <algorithm>
#include<vector>
#include<set>
#define fr(i,m,n) for(int i=m;i<n;i++)
using namespace std;
#include <fstream>

struct Point{
    int x;
    int y;
    Point(int a,int b){
        x=a;
        y=b;
    }
};

bool isLeft(Point a,Point b,Point c){
    int x=(b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);
    return x>0;
}

void solve(vector<Point> points) {
    set<Point> hull;
    int n=points.size();
    bool x;
    fr(i,0,n-1){
        if(isLeft(points[i],points[i+1],points[(i+2)%n])){
            cout<<"L";
        }
        else{
            cout<<"R";
        }
    }
    cout<<"\n";
}

int main() {
    vector<Point> points;
    ifstream indata; 
    int x,y;
    indata.open("input1.txt"); 
    if(!indata) { 
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    while ( !indata.eof() ) { 
        indata >> x;
        indata >> y;
        points.push_back(Point(x,y));
    }
    indata.close();
    solve(points);
}
