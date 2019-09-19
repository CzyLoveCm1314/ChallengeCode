#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

string a,b;
int hash(string x){
	int res=1;
	for(int i=0;i<x.size();i++){
		res=res*(x[i]-'A'+1);
	}
	return res%47;
}
int main(){
	cin>>a>>b;
	if(hash(a)==hash(b)) cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	
	return 0;
}
