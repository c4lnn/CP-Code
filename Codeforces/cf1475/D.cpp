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
const int N=2e5+5;
int n,m;
LL a[N];
vector<LL> p,q;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        p.clear(),q.clear();
        p.PB(0),q.PB(0);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) {
            int x;
            cin>>x;
            if(x==1) p.PB(a[i]);
            else q.PB(a[i]);
        }
        sort(p.begin()+1,p.end(),greater<LL>());
        sort(q.begin()+1,q.end(),greater<LL>());
        for(int i=1;i<SZ(p);i++) p[i]+=p[i-1];
        for(int i=1;i<SZ(q);i++) q[i]+=q[i-1];
        int res=INT_MAX;
        for(int i=0,j=SZ(q)-1;i<SZ(p);i++) {
            bool f=false;
            while(j>=0&&p[i]+q[j]>=m) --j,f=true;
            if(f) ++j;
            if(p[i]+q[j]>=m) res=min(res,i+j*2);
        }
        cout<<(res==INT_MAX?-1:res)<<'\n';
    }
    return 0;
}