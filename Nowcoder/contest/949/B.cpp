#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second

#define lowbit(x) x&(-x)
#define mem(arr,val) memset(arr,val,sizeof arr)

typedef pair<int,int>pii;
const int mod=1e9+7;
ll s[10000];
ll a[10000];
int main()
{
	int n,m;
	s[1]=a[1]=1;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++) a[i]=(a[i-1]*2+2)%mod,s[i]=a[i]+s[i-1];
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",(s[b]-s[a-1])%mod);
	}
	return 0;
}
