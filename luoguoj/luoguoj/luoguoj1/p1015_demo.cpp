#include<iostream>
using namespace std;
int q[101],n,l;
int jj() {
	for(int i=0; i<=l/2; i++)
		if(q[i]!=q[l-1-i])
			return 0; //�ж��Ƿ��ǻ�����
	return 1;
}
void add() {
	int i,c[101]= {0};
	for(i=0; i<l; i++)  {
		c[i]=q[i]+q[l-1-i]+c[i];//ģ����Ƽӷ�  
		c[i+1]+=c[i]/n;//�����λ������
		c[i]%=n;//ģ����Ƽӷ�  
	}
	if(c[l]!=0) l++;//����һλ �����ܶ���λ 
	for(i=l-1; i>=0; i--)   q[l-1-i]=c[i];//����ȫ�������н����ж� 
}
int main() {
	string m;
	cin>>n>>m;
	l=m.length();
	for(int i=0; i<l; i++)  {
		if(m[i]<'A')    q[i]=m[i]-'0';//�ַ�ת��Ϊ���� 
		else if('A'<=m[i]&&m[i]<'Z')    q[i]=m[i]-'A'+10;//����ʮ������ 
		else q[i]=m[i]-'a'+10;//����ʮ������С����ʾ 
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
