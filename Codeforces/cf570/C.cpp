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
const int N=3e5+5;
char s[N];
int st[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m>>s+1;
    int sum=0;
    for(int i=1;i<=n;i++) {
        if(s[i]!='.') st[i]=1;
        else st[i]=0;
        if(i!=1&&st[i]==0&&st[i-1]==0) st[i-1]=-1,++sum;
    }
    for(int i=1;i<=m;i++) {
        int x;char c;cin>>x>>c;
        if(st[x]==-1&&c!='.') {
            st[x]=1,--sum;
            if(st[x-1]==-1) st[x-1]=0,--sum;
        }
        else if(st[x]==0&&c!='.') {
            st[x]=1;
            if(st[x-1]==-1) st[x-1]=0,--sum;
        }
        else if(st[x]==1&&c=='.') {
            if(x!=1&&st[x-1]==0) st[x-1]=-1,++sum;
            if(x!=n&&st[x+1]!=1) st[x]=-1,++sum;
            else st[x]=0;
        }
        cout<<sum<<'\n';
    }
    return 0;
}