#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2*1e5+1;
char a[maxn];
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=n-x+1;i<=n;i++)
	{
		if(i==n-y)
		{
			if(a[i]=='0')
				ans++;	
		}	
		else
			if(a[i]=='1')
				ans++;
 	}	 
 	cout<<ans;
	return 0;
}