#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
    	cin>>n;
    	n+=n;
    	for(int i=1;i<=n;i++) cin>>a[i];
    	sort(a+1,a+1+n);
    	cout<<abs(a[n/2]-a[n/2+1])<<endl;
	}
 	return 0;
}