#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stdlib.h>
using namespace std;

#define maxn 10000100
char s[maxn];
struct node {
	node *next[26];
	node *fail;
	int sum;
};
node *root;
node *q[maxn];
int cnt;

void Insert(char *s) {
	node *p = root;
	for (int i = 0; s[i]; i++) {
		int x = s[i] - 'a';
		if (!p->next[x]) {
			node *newnode = (struct node *)malloc(sizeof(node));
			for (int i = 0; i < 26; i++) newnode->next[i] = 0;
			newnode->fail = 0;
			newnode->sum = 0;
			p->next[x] = newnode;
		}
		p = p->next[x];
	}
	p->sum++;
}

void BuildFailer() {
	int head, tail;
	head = 0;
	tail = 1;
	q[head] = root;
	node *p;
	node *temp;
	while (head < tail){
		temp = q[head++];
		for (int i = 0; i <= 25; i++){
			if (temp->next[i]){
				if (temp == root) temp->next[i]->fail = root;
				else{
					p = temp->fail;
					while (p){
						if (p->next[i]){
							temp->next[i]->fail = p->next[i];
							break;
						}
						p = p->fail;
					}
					if (p == NULL) temp->next[i]->fail = root;
				}
				q[tail++] = temp->next[i];
			}
		}
	}
}
void AcAutomation(char *ch){
	node *p = root;
	int len = strlen(ch);
	for (int i = 0; i < len; i++){
		int x = ch[i] - 'a';
		while (!p->next[x] && p != root) p = p->fail;
		p = p->next[x];
		if (!p) p = root;
		node *temp = p;
		while (temp != root){
			if (temp->sum >= 0){
				cnt += temp->sum;
				temp->sum = -1;
			}
			else break;
			temp = temp->fail;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		cnt = 0;
		root = (struct node *)malloc(sizeof(struct node));
		for (int j = 0; j<26; j++) root->next[j] = 0;
		root->fail = 0;
		root->sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			char temp[60] = { 0 };
			scanf("%s", &temp);
			Insert(temp);
		}
		BuildFailer();
		scanf("%s", s);
		AcAutomation(s);
		printf("%d\n", cnt);
	}
	return 0;
}