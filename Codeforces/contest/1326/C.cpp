#include<bits/stdc++.h>

using namespace std;

const int N=200010;

pair<int,int>a[N];
int b[N];
int main() {
 	//freopen("in.txt","r",stdin);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
	sort(a+1,a+1+n);
	long long mx=0;
	for(int i=n,t=1;t<=k;i--,t++) mx+=a[i].first,b[t]=a[i].second;
	sort(b+1,b+1+k);
	long long ans=1;
	for(int i=2;i<=k;i++) ans=ans*(b[i]-b[i-1])%998244353;
	cout<<mx<<" "<<ans<<endl;
 	return 0;
}