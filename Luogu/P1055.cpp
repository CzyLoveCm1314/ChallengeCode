#include<cstring>
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string str;
int recognize(string x){
	int j=1;
	int sum=0;
	for(int i=0;i<x.size();i++){
		if(j==10)break;
		if(x[i]!='-'){
			sum+=(x[i]-'0')*j;
			j++;
			//cout<<x[i]<<' ';
		}
	}
	return sum%11;
}
int main(){
	cin>>str;
	int flag=recognize(str);
	//cout<<flag<<endl;
	if(str[str.size()-1]-'0'==flag ||(flag==10&&str[str.size()-1]=='X')) cout<<"Right"<<endl;
	else{
		if(flag==10)str[str.size()-1]='X';
		else str[str.size()-1]='0'+flag;
		cout<<str<<endl;
	}
	return 0;
}
