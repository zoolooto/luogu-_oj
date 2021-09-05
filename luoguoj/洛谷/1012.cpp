#include<bits/stdc++.h>
using namespace std;
bool et=true;
int mb=0;
bool compare(int a,int b) {
	int numa=0;
	int flaga=a;
	int flagb=b;
	int numb=0;
	int a_size=0,b_size=0;
	while(1) {
		while(a%10) {
			numa =a%10;
			a/= 10;
			a_size++;
		}
		while(b%10) {
			numb = b%10;
			b/= 10;
			b_size++;
		}
		if(et) {
			mb=numb;
			et=false;
		}
		if(numa>numb&&numb!=0) {
			return true;
		} else if(numa<numb) {
			return false;
		} else if(numa>numb&&numb==0) {
			if(numa>=mb)
			return true;
			else
			return false;
		} else {
			return compare(flaga-numa*pow(10,a_size-1),flagb-numb*pow(10,b_size-1));

		}
	}
}
int main() {
	int n;
	cin>>n;
	int num[n];
	for(int i=0; i<n; i++) {
		cin>>num[i];
	}
	for(int i=0; i<n; i++) {
		int m=0;
		for(int j=i+1; j<n; j++) {
			et=true;
	 		mb=0;
			if(compare(num[j],num[i])) {
				m=num[i];
				num[i]=num[j];
				num[j]=m;
			}
		}
	}
	string str="";
	for(int i=0; i<n; i++) {
		string res;
		stringstream ss;
		ss << num[i];
		ss >> res;
		str+=res;
	}
	cout<<str;
}
