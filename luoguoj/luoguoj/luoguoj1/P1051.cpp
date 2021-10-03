#include<bits/stdc++.h>
using namespace std;
struct STU {
	string Name;
	int EndScore;
	int ClassScore;
	char west;
	char cadre;
	int num;
	int money=0;
};

void money(struct STU *stu) {
	if(stu->EndScore>80&&stu->num)
		stu->money+=8000;
	if(stu->EndScore>85&&stu->ClassScore>80)
		stu->money+=4000;
	if(stu->EndScore>90)
		stu->money+=2000;
	if(stu->EndScore>85&&stu->west=='Y')
		stu->money+=1000;
	if(stu->ClassScore>80&&stu->cadre=='Y')
		stu->money+=850;
}
int main() {
	int max,index;
	int m;
	cin>>m;
	int sum=0;
	struct STU stu[m];
	for(int i=0; i<m; i++) {
		cin>>stu[i].Name>>stu[i].EndScore>>stu[i].ClassScore>>stu[i].cadre>>stu[i].west>>stu[i].num;
		if(i==0) {
			max=stu[i].money;
			index=i;
		}
		money(&stu[i]);
		if(stu[i].money>max) {
			max=stu[i].money;
			index=i;
		}
		sum+=stu[i].money;
	}
	bool flag=false;
	for(int i=index+1; i<m; i++) {
		if(stu[i].money==max)
		flag==true;
	}
	cout<<stu[index].Name<<endl;
	if(flag)
	cout<<stu[index].Name<<endl;
	else
	cout<<stu[index].money<<endl;
	cout<<sum<<endl;

	return 0;
}
