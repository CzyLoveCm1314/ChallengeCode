#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring> 
using namespace std;

int num[26];
string a;
int main(){
	int n;
	cin>>n>>a;
	for(int i=0;i<a.size();i++){
		int t=a[i]-'a';
		t=t+n;
		t=t%26;
		a[i]='a'+t;
	}
	cout<<a;
	return 0; 
}

