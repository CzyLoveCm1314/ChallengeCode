#include<string>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

string a;

int main(){
	cin>>a;
	int flag=0;
	for(int i=0;i<a.size();i++){
		if(a[i]=='.')flag=1;
		else if(a[i]=='/')flag=2;
		else if(a[i]=='%')flag=3;	
	}
	string temp;
	if(flag==0) for(int i=a.size()-1;i>=0;i--) temp+=a[i];
	else if(flag==1){
		int cnt;
		for(int i=0;i<a.size();i++){
			if(a[i]=='.'){
				cnt=i;
				break;
			}
		}
		for(int i=cnt-1;i>=0;i--)	temp+=a[i];
		temp+='.';
		for(int i=a.size()-1;i>cnt;i--)	temp+=a[i];
	}
	else if(flag==2){
		int cnt;
		for(int i=0;i<a.size();i++){
			if(a[i]=='/'){
				cnt=i;
				break;
			}
		}
		for(int i=cnt-1;i>=0;i--)	temp+=a[i];
		temp+='/';
		for(int i=a.size()-1;i>cnt;i--)	temp+=a[i];
	}
	else{
		int cnt;
		for(int i=0;i<a.size();i++){
			if(a[i]=='%'){
				cnt=i;
				break;
			}
		}
		for(int i=cnt-1;i>=0;i--)	temp+=a[i];
	}
	//cout<<temp<<endl;
	if(flag==0){
		int j=0;
		while(temp[j]=='0')j++;
		for(int i=j;i<temp.size();i++)cout<<temp[i];
		if(j==temp.size())cout<<0;
	}
	else if(flag==1){
		int i,j;
        i=0;
        while(temp[i]=='0')i++;
        j=temp.size()-1;
        while(temp[j]=='0')j--;
        if(temp[i]=='.')cout<<0;
        for(int k=i;k<=j;k++)cout<<temp[k];
        if(temp[j]=='.')cout<<0;
	} 
	else if(flag==2){
		int i,j,k;
        i=0;
        while(temp[i]=='0')i++;
        j=temp.size()-1;
        while(temp[j]=='0')j--;
        if(temp[i]=='/')cout<<0;
        for(k=i;k<=j;k++){
			cout<<temp[k];
			if(temp[k]=='/')break;
		}
		k=k+1;
		 while(temp[k]=='0')k++;
		 for(int i=k;i<temp.size();i++)cout<<temp[i]; 
	}
	else {
		int j=0;
		while(temp[j]=='0')j++;
		for(int i=j;i<temp.size();i++)cout<<temp[i];
			if(j==temp.size())cout<<0;
		cout<<'%';
	}
	
	
	return 0;
}
