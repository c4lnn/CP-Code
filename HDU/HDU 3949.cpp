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
const int N=100;
int n,tot;
LL d[N];
void add(LL x) {
    for(int i=63;~i;i--)
        if((x>>i)&1) {
            if(!d[i]) {d[i]=x;return;}
            x^=d[i];
        }
}
void calc() {
    tot=0;
    for(int i=0;i<63;i++) if(d[i]) ++tot;
}
void update() {
    for(int i=0;i<63;i++)
        for(int j=0;j<i;j++)
            if((d[i]>>j)&1)
                d[i]^=d[j];
}
LL kth(int k) {
    if(tot<n) --k; // 去掉 0
    LL ret=0;
    for(int i=0;i<63;i++)
        if(d[i]) {
            if(k&1) ret^=d[i];
            k>>=1;
        }
    if(k) return -1;
    return ret;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        memset(d,0,sizeof d);
        cin>>n;
        for(int i=1;i<=n;i++) {
            LL x;cin>>x;
            add(x);
        }
        cout<<"Case #"<<cs<<":\n";
        int q;cin>>q;
        calc();
        update();
        for(int i=1;i<=q;i++) {
            int k;cin>>k;
            cout<<kth(k)<<'\n';
        }
    }
    return 0;
}