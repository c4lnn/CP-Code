#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const int N=4000;
int w[N];
int f[N][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,b;
    cin>>n>>b;
    for(int i=1;i<=n;i++) cin>>w[i];
    memset(f,0xc0,sizeof f);
	f[0][0]=f[1][1]=0;
    for(int i=2;i<=n;i++)
    	for(int j=min(i,b);j>=0;j--) {
    		f[j][0]=max(f[j][0],f[j][1]);
    		if(j) f[j][1]=max(f[j-1][0],f[j-1][1]+w[i]);
    	}
    int res=f[b][0];
    memset(f,0xc0,sizeof f);
    f[0][0]=0,f[1][1]=w[1];
    for(int i=2;i<=n;i++)
    	for(int j=min(i,b);j>=0;j--) {
    		f[j][0]=max(f[j][0],f[j][1]);
    		if(j) f[j][1]=max(f[j-1][0],f[j-1][1]+w[i]);
    	}
    res=max(res,f[b][1]);
    cout<<res<<endl;
    return 0;
}