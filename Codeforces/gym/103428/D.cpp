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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const int N=1e6+5;
int nxt[N],sum[N];
void get_next(const string &s) {
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<SZ(s)) {
        if(j==-1||s[i]==s[j]) nxt[++i]=++j;
        else j=nxt[j];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;cin>>s;
    get_next(s);
    for(int i=nxt[SZ(s)];i;i=nxt[i]) {
        int l=i+1,r=SZ(s)-i;
        if(l<=r) ++sum[l],--sum[r+1];
    }
    for(int i=2;i<=SZ(s);i++) {
       sum[i]+=sum[i-1];
    }
    int q;cin>>q;
    while(q--) {
        int n;cin>>n;
        cout<<sum[n]<<'\n';
    }
    return 0;
}