#include<bits/stdc++.h>
using namespace std;
void proving(string str) {
	int sum=0;
	int j=1;
	for(int i=0,j=1; i<str.length()&&j<=9; i++) {
		if(str[i]-'0'>=0&&str[i]-'0'<=9) {
			sum=sum+(str[i]-'0')*j;
			j++;
		}
	
	}
	sum=sum%11;
	char flag;
	if(sum==10)
		flag='X';
	else
		flag=sum+'0';
		     if(str[str.length()-1]!=flag)
		     {
			     str[str.length()-1]=flag;
			     cout<<str;
			 }
		else
		cout<<"Right";
}
int main() {
	string str;
	cin>>str;
	proving(str);
	return 0;
}
