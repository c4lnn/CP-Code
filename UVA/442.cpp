#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct mat
{
	int c;
	int r;	
	mat(int c=0,int r=0):c(c),r(r){}
}m[26];
int main()
{
	int n;
	cin>>n;
	char c;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		cin>>m[c-'A'].c>>m[c-'A'].r;
	} 
	string str;
	while(cin>>str)
	{
		stack<mat>s;
		int len=str.length();
		int sum=0;
		int flag=0;
		for(int i=0;i<len;i++)
		{
			if(str[i]>='A'&&str[i]<='Z') s.push(m[str[i]-'A']);
			else if(str[i]==')')
			{
				mat m2=s.top();s.pop();
				mat m1=s.top();s.pop();
				if(m1.r==m2.c)
					sum+=m1.c*m2.r*m1.r;
				else 
				{
					flag=1;
					break;
				}
				s.push(mat(m1.c,m2.r));
			}	
		}
		if(flag)
			cout<<"error\n";
		else
			cout<<sum<<endl;
	}
	return 0;
}