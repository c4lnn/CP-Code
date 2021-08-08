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
// head
const int N=1e5+5;
bool st[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m;cin>>n>>m;
        memset(st,false,sizeof st);
        for(int i=1;i<=m;i++) {
            int x;cin>>x;
            st[x]=true;
        }
        int cnt=0,len=0;
        PII mx={0,0};
        for(int i=1;i<=n;i++) {
            if(!st[i]) ++len;
            else {
                if(len>mx.FI) mx={len,cnt};
                else if(len==mx.FI) mx.SE=cnt;
                ++cnt;
                len=0;
            }
        }
        if(len>mx.FI) mx={len,cnt};
        else if(len==mx.FI) mx.SE=cnt;
        if(mx.FI<=n-m-mx.FI||mx.SE>=mx.FI-(n-m-mx.FI)) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}