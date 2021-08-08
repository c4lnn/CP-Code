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
int n,m;
bool st[8];
DB a[8];
vector<VI> res;
int dfs2(int x,bool f) {
    if(x==n*2-1) {
        if(fabs(a[x]-m)>1e-8) return 0;
        else if(f) return 1;
        return 2;
    }
    int ret=0;
    for(int i=1;i<=x;i++) if(!st[i]) {
        st[i]=true;
        for(int j=1;j<=x;j++) if(i!=j&&!st[j]) {
            st[j]=true;
            a[x+1]=a[i]+a[j];
            ret|=dfs2(x+1,f);
            a[x+1]=a[i]-a[j];
            ret|=dfs2(x+1,f);
            a[x+1]=a[i]*a[j];
            ret|=dfs2(x+1,f);
            if(fabs(a[j])>1e-8) {
                a[x+1]=a[i]/a[j];
                ret|=dfs2(x+1,f|((int)a[x+1]!=(int)ceil(a[x+1])));
            }
            st[j]=false;
        }
        st[i]=false;
    }
    return ret;
}
void dfs1(int x,int d) {
    if(x==n+1) {
        if(dfs2(n,false)==1) {
            res.PB(vector<int>{(int)a[1],(int)a[2],(int)a[3],(int)a[4]});
        }
        return;
    }
    for(int i=d;i<=13;i++) {
        a[x]=i;
        dfs1(x+1,i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    dfs1(1,1);
    cout<<SZ(res)<<'\n';
    for(auto x:res) {
        for(int i=0;i<n;i++) {
            cout<<x[i]<<" \n"[i==n-1];
        }
    }
    return 0;
}