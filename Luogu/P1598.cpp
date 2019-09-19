#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring> 
using namespace std;

int num[26];
string a;
int main(){
	for(int i=0;i<4;i++){
		getline(cin,a);
		for(int j=0;j<a.size();j++){
			if(a[j]<='Z'&&a[j]>='A')
				num[a[j]-'A']++;
		}
	}
	int mx=-1;
	for(int i=0;i<26;i++) {
		mx=max(num[i],mx);
	//	cout<<char(i+'A')<<','<<num[i]<<endl;
	}
	for (int i=0;i<26;i++) num[i]=mx-num[i];
	for (int i=0;i<mx;i++){
		for(int j=0;j<26;j++){
			if(num[j]>0){
				cout<<' ';
				num[j]--;
			}
			else cout<<'*';	
			if(j!=25)cout<<' ';
		}
		cout<<endl;
	}
	cout<<"A";
	for (int i=1;i<26;i++)cout<<' '<<char(i+'A');
}

