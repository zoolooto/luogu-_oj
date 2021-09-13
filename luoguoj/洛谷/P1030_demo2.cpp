#include<bits/stdc++.h>
using namespace std;
struct node *creat(char *a, char *b, int n) {
	struct node *ptr;
	char *p;
	int count = 0;
	if (n <= 0)
		return NULL;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr -> data = *a;
	for (p = &b[0]; p <= b + n - 1; p ++) {
		if (*p == *a)
			break;
	}
	count = p - b;
	ptr -> l = creat(a + 1, b, count);
	ptr -> r = creat(a + 1 + count, p + 1, n - 1 - count);
	return ptr;
}
