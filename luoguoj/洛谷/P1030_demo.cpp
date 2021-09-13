#include<bits/stdc++.h>
using namespace std;
const int N=8;
char pre[N],in[N]; //先序数组和中序数组
stack<char> st;      //存放父节点
void build(int l1,int r1,int l2,int r2) { //l1,r1,是先序数组，l2,r2中序数组
	int i,j;
	st.push(pre[l1]);    //父节点入栈
	for(i=l2; i<=r2; i++)
		if(in[i]==pre[l1])  //找到父节点在中序遍历的位置i
			break;
	j=l1+(i-l2+1);      //确定左子树和右子树在先序遍历的分界点j，即右子树的父节点
	if(j<=r1 && i+1<=r2)    //求解右子树
		build(j,r1,i+1,r2);
	if(l1+1<=j-1 && l2<=i-1)    //求解左子树
		build(l1+1,j-1,l2,i-1);
}

int main() {
	cin>>pre;
	cin>>in;
	int size=strlen(pre);
	build(0,size-1,0,size-1);
	while(!st.empty()) {
		cout<<st.top();
		st.pop();
	}

	return 0;
}
