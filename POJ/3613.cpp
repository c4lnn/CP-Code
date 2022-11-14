#include<iostream>
#include<cstring>
#include<map>

using namespace std;

const int N=205;

int n,t,s,e;
map<int,int>mp;
int cnt;
struct mat {
    int m[N][N];
    mat() {
        memset(m,0x3f,sizeof m);
    }
}w;
mat floyd(mat a,mat b) {
    mat res;
    for(int k=1;k<=cnt;k++) {
        for(int i=1;i<=cnt;i++) {
            for(int j=1;j<=cnt;j++) {
                res.m[i][j]=min(res.m[i][j],a.m[i][k]+b.m[k][j]);
            }
        }
    }
    return res;
}
void solve() {
    mat res=w;
    mat a=w;
    int x=n-1;
    while(x) {
        if(x&1) res=floyd(res,a);
        a=floyd(a,a);
        x>>=1;
    }
    cout<<res.m[s][e]<<endl;
}
int main() {
    cin>>n>>t>>s>>e;
    for(int i=1;i<=t;i++) {
        int val,u,v;
        cin>>val>>u>>v;
        if(!mp[u]) mp[u]=++cnt;
        if(!mp[v]) mp[v]=++cnt;
        u=mp[u],v=mp[v];
        w.m[u][v]=w.m[v][u]=min(w.m[u][v],val);
    }
    s=mp[s],e=mp[e];
    solve();
     return 0;
}