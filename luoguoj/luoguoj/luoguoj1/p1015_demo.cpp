#include<iostream>
using namespace std;
int q[101],n,l;
int jj() {
	for(int i=0; i<=l/2; i++)
		if(q[i]!=q[l-1-i])
			return 0; //判断是否是回文数
	return 1;
}
void add() {
	int i,c[101]= {0};
	for(i=0; i<l; i++)  {
		c[i]=q[i]+q[l-1-i]+c[i];//模拟进制加法  
		c[i+1]+=c[i]/n;//处理进位的问题
		c[i]%=n;//模拟进制加法  
	}
	if(c[l]!=0) l++;//最多多一位 不可能多两位 
	for(i=l-1; i>=0; i--)   q[l-1-i]=c[i];//放了全局数组中进行判断 
}
int main() {
	string m;
	cin>>n>>m;
	l=m.length();
	for(int i=0; i<l; i++)  {
		if(m[i]<'A')    q[i]=m[i]-'0';//字符转换为整数 
		else if('A'<=m[i]&&m[i]<'Z')    q[i]=m[i]-'A'+10;//若是十六进制 
		else q[i]=m[i]-'a'+10;//若是十六进制小数表示 
	}
	if(jj()==1)   {
		cout<<"STEP=0";
		return 0;
	}
	for(int num=1; num<=30; num++)  {
		add();
		if(jj()==1)    {
			cout<<"STEP="<<num;
			return 0;
		}
	}
	cout<<"Impossible!";
	return 0;
}
