/*
#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<stdlib.h>
using namespace std;
struct node {
	int id;
	node *left, *right;
};
int main() {
	int n;
	cin >> n;
	node *root = (node*)malloc(sizeof(node));
	(*root).id = 0;
	(*root).left = NULL;
	node *p;
	node *newnode = (node*)malloc(sizeof(node));
	(*root).right = newnode;
	(*newnode).id = 1;
	(*newnode).left = root;
	(*newnode).right = NULL;
	int op, cnt;
	for (int i = 2; i <= n; i++) {
		scanf("%d%d", &cnt, &op);
		p = root;
		while (p != NULL) {
			if (p->id == cnt) {
				node *newnode = (node*)malloc(sizeof(node));
				(*newnode).id = i;
				if (op == 0) {
					(*newnode).right = p;
					(*newnode).left = (*p).left;
					p->left->right = newnode;
					(*p).left = newnode;
				}
				else {
					newnode->left = p;
					newnode->right = p->right;
					p->right->left = newnode;
					p->right = newnode;
				}
				break;
			}
			else p = p->right;
		}
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &cnt);
			p = root->right;
		while (p != NULL) {
			if (p->id == cnt) {
				p->left->right = p->right;
				p->right->left = p->left;
				free(p);
				break;
			}
			p = p->right;
		}
		
	}
	p = root->right;
	int flag = 0;
	while (p != NULL) {
		if(flag) cout << ' ' <<p->id ;
		else {
			cout << p->id;
			flag = 1;
		}
		p = p->right;
	}
	cout << endl;
	return 0;
}
*/

#include<cstdio>
int n, m, i, j, k, p, t, c;
struct pd {
	int l = 0, r = 0; 
}q[100005];
int main() { 
	int head = 1; 
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		scanf("%d%d", &k, &p);
		if (p) {
			q[i].r = q[k].r;
			q[k].r = i;
			q[i].l = k;
			q[q[i].r].l = i; 
		}
		else {
			q[i].l = q[k].l;
			q[k].l = i;
			q[i].r = k;
			q[q[i].l].r = i; 
			if (k == head) head = i; 
		}
	}
	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d", &t);
		q[q[t].r].l = q[t].l;
		q[q[t].l].r = q[t].r;
		q[t].l = q[t].r = 0; 
	}
	printf("%d", head);
	p = head;
	while (q[p].r) {
		p = q[p].r;
		printf(" %d", p);
	}
	return 0;
}