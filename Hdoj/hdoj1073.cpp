#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 5100;
char a1[maxn], a2[maxn];
char b1[maxn], b2[maxn];
char temp[maxn];

void input(char a[], char b[]){
	cin.getline(temp, maxn);
	while (strcmp(temp, "START") != 0) cin.getline(temp, maxn);
	while (cin.getline(temp, maxn)){
		if (strcmp(temp, "END") == 0)break;
		if (strlen(temp) != 0)strcat(a, temp);
		strcat(a, "\n");
	}
	int t = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++){
		if (a[i] != ' ' && a[i] != '\t' && a[i] != '\n')
			b[t++] = a[i];
	}
	b[t] = '\0';
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		a1[0] = '\0';
		a2[0] = '\0';
		input(a1, b1);
		input(a2, b2);
		if (strcmp(a1, a2) == 0) printf("Accepted\n");
		else if (strcmp(b1, b2) == 0) printf("Presentation Error\n");
		else printf("Wrong Answer\n");
	}
	return 0;
}