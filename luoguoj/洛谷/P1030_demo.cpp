#include<bits/stdc++.h>
using namespace std;
const int N=8;
char pre[N],in[N]; //�����������������
stack<char> st;      //��Ÿ��ڵ�
void build(int l1,int r1,int l2,int r2) { //l1,r1,���������飬l2,r2��������
	int i,j;
	st.push(pre[l1]);    //���ڵ���ջ
	for(i=l2; i<=r2; i++)
		if(in[i]==pre[l1])  //�ҵ����ڵ������������λ��i
			break;
	j=l1+(i-l2+1);      //ȷ��������������������������ķֽ��j�����������ĸ��ڵ�
	if(j<=r1 && i+1<=r2)    //���������
		build(j,r1,i+1,r2);
	if(l1+1<=j-1 && l2<=i-1)    //���������
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
