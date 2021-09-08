#include<iostream>
#include<cstdio>
#include <cmath>
#define MAXSIZE 1000
using namespace std;
int data[20];
int ans,n,num;
bool primenumber(int num) {
	for(int i=2; i<=sqrt(num); i++) {
		if(num%i==0)
			return false;
	}
	return true;
}
void DFS(int x,int sum,int d) {
	if(x==num) {
		if(primenumber(sum))ans++;
	} else {
		for(int i=d; i<n; i++) {
			DFS(x+1,sum+data[i],i+1);
		}
	}
}
int main() {
	cin>>n>>num;
	for(int i=0; i<n; i++) {
		cin>>data[i];
	}
	DFS(0,0,0);
	cout<<ans;
	return 0;

}
