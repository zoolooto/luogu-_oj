#include<bits/stdc++.h>
using namespace std;
const int N=8;
char bac[N],in[N]; //后序数组和中序数组
stack<char> st; 
void dfs(int l1,int r1,int l2,int r2)//l1,r1中序，l2,r2后序 
{
	cout<<bac[r2];
	int i,j;
	for(i=l1;i<=r1;i++)
	{
		if(in[i]==bac[r2])
		break;
	} 
	j=r2-(r1-i+1);
	if(i-1>=l1&&j>=l2)
	dfs(l1,i-1,l2,j);//左子树 
	if(r1>=i+1&&r2-1>=j+1)
	dfs(i+1,r1,j+1,r2-1);//右子树 
}
int main()
{
	cin>>in;
	cin>>bac;
	int n=strlen(bac);
	dfs(0,n-1,0,n-1);
} 
