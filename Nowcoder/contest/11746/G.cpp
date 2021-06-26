#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
LL k,a[N],s[N];
int main() {
    #ifdef DEBUG
        freopen("E:/OneDrive/IO/in.txt","r",stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        int n;
        LL mx=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        int x=0;
        for(int i=1;i<=n;i++) {
            s[i]=s[i-1]+a[i];
            if(a[i]==mx) s[i]-=a[i],x=i;
        }
        LL t1=(k-x+1)/(n-1+mx);
        LL t2=0;
        if(k-s[x]>0) t2=(LL)ceil(1.0*(k-s[x])/(s[n]+mx));
        if(k-x+1>=0&&t2<=t1&&t1>=0) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}