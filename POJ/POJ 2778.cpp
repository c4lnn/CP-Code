#include <iostream>
#include <cstring>
#include <queue>
#define SZ(x) (int)(x).size()
using namespace std;
typedef long long LL;
const LL MOD=100000;
const int N=15;
int n,m,tr[N*N][4],fail[N*N],st[N*N],cnt;
struct M {
    LL a[N*N][N*N];
    void clear() {memset(a,0,sizeof a);}
    M() {clear();}
    M operator * (const M &T) const {
        M ret;
        for(int i=0;i<=cnt;i++)
            for(int k=0;k<=cnt;k++) {
                LL t=a[i][k];
                if(!t) continue;
                for(int j=0;j<=cnt;j++) {
                    if(!T.a[k][j]) continue;
                    ret.a[i][j]=(ret.a[i][j]+T.a[k][j]*t%MOD)%MOD;
                }
            }
        return ret;
    }
    M operator ^ (LL b) const {
        M ret,bas;
        for(int i=0;i<=cnt;i++) ret.a[i][i]=1;
        for(int i=0;i<=cnt;i++)
            for(int j=0;j<=cnt;j++)
                bas.a[i][j]=a[i][j];
        while(b) {
            if(b&1) ret=ret*bas;
            bas=bas*bas;
            b>>=1;
        }
        return ret;
    }
}mat;
int get(char c) {
    if(c=='A') return 0;
    if(c=='C') return 1;
    if(c=='T') return 2;
    return 3;
}
void insert(const string &s) {
    int u=0;
    for(int i=0;s[i];i++) {
        int v=get(s[i]);
        if(!tr[u][v]) tr[u][v]=++cnt;
        u=tr[u][v];
    }
    st[u]=1;
}
void build() {
    queue<int> q;
    for(int i=0;i<4;i++) if(tr[0][i]) q.push(tr[0][i]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v=0;v<4;v++) {
            if(tr[u][v]) fail[tr[u][v]]=tr[fail[u]][v],q.push(tr[u][v]);
            else tr[u][v]=tr[fail[u]][v];
        }
        st[u]|=st[fail[u]];
    }
}
void get_matrix() {
    for(int i=0;i<=cnt;i++) {
        if(st[i]) continue;
        for(int j=0;j<4;j++) {
            if(st[tr[i][j]]) continue;
            ++mat.a[i][tr[i][j]];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++) {
        string s;
        cin>>s;
        insert(s);
    }
    build();
    get_matrix();
    mat=mat^n;
    LL res=0;
    for(int i=0;i<=cnt;i++) res=(res+mat.a[0][i])%MOD;
    cout<<res<<'\n';
    return 0;
}