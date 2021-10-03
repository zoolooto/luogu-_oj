#include<bits/stdc++.h>
using namespace std;
struct Node {
	Node *left;
	Node *right;
	Node():left(NULL),right(NULL) {
	}
	char data;
};
char judge(string s) {
	if (s == string(s.length(), '0')) return 'B';
	if (s == string(s.length(), '1')) return 'I';
	return 'F';
}
Node *create(Node *tree,string stu) {
	if(stu.length()>1) {
		tree->left=new Node();
		tree->right=new Node();
		tree->left=create(tree->left,stu.substr(0,floor(stu.length()/2)));
		tree->right=create(tree->right,stu.substr(round(stu.length()/2),floor(stu.length()/2)));
		tree->data=judge(stu);
	} else {
		tree->data=judge(stu);
	}
	return tree;
}
void postOrder(Node *t) {
	if(t) {
		postOrder(t->left);
		postOrder(t->right);
		cout<<t->data;
	}
}
int main() {
	string str;
	int n;
	cin>>n>>str;
	Node tree;
	tree=*create(&tree,str);
	postOrder(&tree);
	return 0;
}
