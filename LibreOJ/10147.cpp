#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	int num[201];
	int dp_min[201][201]={0};
	int dp_max[201][201]={0};
	int sum[201]={0};
	int minn=0x3f3f3f3f;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		num[i+n]=num[i];
	}
	partial_sum(num+1,num+n+1+n,sum+1);
	for(int i=1;i<=n;i++)
		for(int j=1,k;(k=j+i)<=2*n;j++)
		{
			dp_min[j][k]=0x3f3f3f3f;
			dp_max[j][k]=0;
			for(int l=j;l<k;l++)
			{
				dp_min[j][k]=min(dp_min[j][k],dp_min[j][l]+dp_min[l+1][k]+sum[k]-sum[j-1]);
				dp_max[j][k]=max(dp_max[j][k],dp_max[j][l]+dp_max[l+1][k]+sum[k]-sum[j-1]);
			}
		}
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,dp_min[i][i+n-1]);
		maxn=max(maxn,dp_max[i][i+n-1]);
	}
	cout<<minn<<endl<<maxn;
	return 0;
}