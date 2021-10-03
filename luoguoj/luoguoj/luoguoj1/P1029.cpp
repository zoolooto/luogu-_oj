#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b) {
	if(a==b)
		return a;
	if(a>b)
		return gcd(a-b,b);
	if(a<b)
		return gcd(b-a,a);
}
int main() {
	int x=0,y=0;
	cin>>x>>y;
	int data=0;
	int  multiplication=x*y;
	for(int i=x; i<=sqrt(multiplication); i++) {
		if(multiplication%i==0) {
			int num=multiplication/i;
			if(gcd(i,num)==x&&gcd(i,num)*y==multiplication)
			{
				if(i==num)
				data++;
				if(i!=num)
				data+=2;
			}
		}
	}
	cout<<data;
}
