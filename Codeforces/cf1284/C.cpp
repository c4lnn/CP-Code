#include<bits/stdc++.h>
 
using namespace std;
  
typedef long long ll;

const int N=250005;

int n,m;
ll fac[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	cin>>n>>m;
	fac[1]=1;
	for(int i=2;i<=n;i++) fac[i]=fac[i-1]*i%m;
	ll ans=0;
	for(int i=1;i<=n;i++) ans=(ans+fac[i]*fac[n-i+1]%m*(n-i+1)%m)%m;
	cout<<ans<<endl; 
	return 0;
}