#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

string a,b;
void tosmall(string &x){
	for(int i=0;i<x.size();i++){
		if(x[i]<='Z'&&x[i]>='A') {
			x[i]=x[i]+('a'-'A');
			//cout<<x[i]<<endl; 
		}	
	}
}
int main(){
	getline(cin,a);
	tosmall(a);
	//cout<<a<<endl;
	getline(cin,b);
	tosmall(b);
	//cout<<b<<endl;
	string temp;
	int sum=0;
	int flag=-1;
	for(int i=0;i<b.size();i++){
		if(b[i]!=' ') temp+=b[i];
		else{
			if(temp==a){
			//	cout<<temp<<endl;
				sum++;
				if(flag==-1)flag=i-temp.size();
			}
			temp.clear();
		}
	}
	if(temp==a){
		//cout<<temp<<endl;
		sum++;
		if(flag==-1)flag=b.size()-temp.size();
	}

	if(sum>0) cout<<sum<<' '<<flag<<endl;
	else cout<<-1<<endl;
	return 0;
}
