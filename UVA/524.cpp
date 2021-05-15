#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int v[17];
int a[17];
int prime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
void ring(int n,int cur)
{
	if(cur==n&&prime(a[cur-1]+a[0]))
	{
		for(int i=0;i<n;i++)
		{
			cout<<a[i];
			if(i!=n-1)
				cout<<" ";
			else
				cout<<endl;
		}
	}
	else
		for(int i=2;i<=n;i++)
			if(!v[i])
				if(!cur||cur&&prime(a[cur-1]+i))
				{
					v[i]=1;
					a[cur]=i;
					ring(n,cur+1);
					v[i]=0;
				}
}
int main()
{
	int n;
	int t=0;
	while(cin>>n)
	{
		memset(a,0,sizeof a);
		memset(v,0,sizeof v);
		a[0]=1;	
		if(t)
		cout<<endl;
		cout<<"Case "<<++t<<":\n";
		ring(n,1);
	}
	return 0;
}