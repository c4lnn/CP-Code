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
unordered_map<int,int> fa;
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int a,int b) {
    int ta=find(a),tb=find(b);
    if(ta==tb) return;
    fa[ta]=tb;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;cin>>n>>q;
    for(int i=1;i<=q;i++) {
        int o,x;cin>>o>>x;
        if(o==1) {
            fa[x]=x;
            if(fa.count(x-1)) merge(x-1,x);
            if(fa.count(x+1)) merge(x,x+1);
        }
        else {
            if(!fa.count(x)) cout<<x<<'\n';
            else cout<<find(x)+1<<'\n';
        }
    }
    return 0;
}