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
struct R {
    string a;
    int b,c,d;
    bool operator < (const R &T) const {
        return a<T.a;
    }
}a[N];
int n,m;
unordered_map<string,int> mp;
VI v[N];
int main() {
    #ifdef DEBUG
        freopen("E:/OneDrive/IO/in.txt","r",stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].d>>a[i].c;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) mp[a[i].a]=i;
    for(int i=1;i<=n;i++) v[a[i].b].PB(i);
    cin>>m;
    for(int i=1;i<=m;i++) {
        int o;
        cin>>o;
        if(o==1) {
            string s;
            cin>>s;
            int t=mp[s];
            cout<<a[t].b<<' '<<a[t].c<<' '<<a[t].d<<'\n';
        }
        else {
            int x;
            cin>>x;
            for(auto i:v[x]) cout<<a[i].a<<'\n';
        }
    }
    return 0;
}