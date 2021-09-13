#include<bits/stdc++.h>
using namespace std;
int data=0;
int n,sum=0;
void move(int *num) {
	int *m=num;
	for(int i=0; i<n; m++,i++) {
		int flag=sum/n-*m;
//		cout<<flag<<endl;
		*(m)=*(m)+flag;
		*(m+1)=*(m+1)+(flag*-1);
		if(flag!=0)
		data++;
	}

}
int main() {
	cin>>n;
	int	num[n]= {0};
	for(int i=0; i<n; i++) {
		cin>>num[i];
		sum+=num[i];
	}
	move(num);
	cout<<data;
	return 0;
}

