#include<bits/stdc++.h>
using namespace std;
int a[50];
int b[50];
int temp[50];
string s;
int t;
void ss()
{
	int ans=0;
	for(int i=0;i<s.length();i++)
	{		
		if(s[i]==' ') a[++t]=ans,ans=0;
		else ans=ans*10+s[i]-'0';
	}
	a[++t]=ans;
}
int cmp(int a,int b)
{
	return a>b;
}
void move(int cur,int t)
{
	for(int i=1;i<=t;i++)
		temp[i]=a[i];
	for(int i=1;i<=t;i++)
	{
		if(!cur) a[i]=temp[i];
		else a[i]=temp[cur--];
	}
}
int main()
{
	int n;
	while(getline(cin,s))
	{
		t=0;
		ss();
		for(int i=1;i<=t;i++)
		{
			printf("%d ",a[i]);
			b[i]=a[i]; 
		} 
		printf("\n");
		sort(b+1,b+t+1,cmp);
		for(int i=1;i<=t;i++)
			for(int j=1;j<=t;j++)
				if(a[j]==b[i]&&i+j-1!=t)
				{
					if(j!=1)
					{
						move(j,t);
						printf("%d ",t-j+1);
					}
					move(t-i+1,t);
					printf("%d ",i);
					break;
			 	}
		printf("0\n");
	} 
	return 0;
}