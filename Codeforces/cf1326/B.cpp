#include<bits/stdc++.h>

using namespace std;

const int N=200010;
int a[N],b[N];

int main() {
 	//freopen("in.txt","r",stdin);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>b[i];
	a[1]=b[1];
	int mx=max(0,a[1]);
	for(int i=2;i<=n;i++) {
		a[i]=b[i]+mx;
		mx=max(a[i],mx);
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
 	return 0;
}