#include <stdio.h>
#include <iostream>
#include <set>
#include <cmath>
#include <sstream>
#define MAX 100010
using namespace std;
 
int n;
int a[200][200];
int DFS(int i,int j)
{
    if(i==n)
        return a[i][j];
    int x = DFS(i+1,j);
    int y = DFS(i+1,j+1);
     cout<<x<<" "<<y;
    return max(x,y) + a[i][j];
}
 
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=5;i++)
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
        cout<<DFS(1,1)<<endl;
    }
    return 0;
}
//qufeu
