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
const int N=35;
int tr[N][26],st[N],fail[N],cnt;
struct M {
    ULL a[N][N];
    void clear() {memset(a,0,sizeof a);}
    M() {clear();}
    M operator * (const M &T) const {
        M ret;
        for(int i=0;i<=cnt;i++)
            for(int k=0;k<=cnt;k++) {
                ULL t=a[i][k];
                if(!t) continue;
                for(int j=0;j<=cnt;j++) {
                    if(!T.a[k][j]) continue;
                    ret.a[i][j]+=T.a[k][j]*t;
                }
            }
        return ret;
    }
    M operator ^ (ULL b) const {
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
}a;
void init() {
    for(int i=0;i<=cnt;i++) for(int j=0;j<26;j++) tr[i][j]=0;
    for(int i=0;i<=cnt;i++) st[i]=fail[i]=0;
    cnt=0;
}
void insert(const string &s) {
    int u=0;
    for(auto c:s) {
        int v=c-'a';
        if(!tr[u][v]) tr[u][v]=++cnt;
        u=tr[u][v];
    }
    st[u]=1;
}
void build() {
    queue<int> q;
    for(int i=0;i<26;i++) if(tr[0][i]) q.push(tr[0][i]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v=0;v<26;v++) {
            if(tr[u][v]) fail[tr[u][v]]=tr[fail[u]][v],q.push(tr[u][v]);
            else tr[u][v]=tr[fail[u]][v];
        }
        st[u]|=st[fail[u]];
    }
}
void get_matrix() {
    a.clear();
    for(int i=0;i<=cnt;i++) {
        if(st[i]) continue;
        for(int j=0;j<26;j++) {
            if(st[tr[i][j]]) continue;
            ++a.a[i][tr[i][j]];
        }
    }
    ++cnt;
    for(int i=0;i<cnt;i++) a.a[cnt][i]=a.a[0][i];
    a.a[cnt][cnt]=1;
}
ULL qpow(ULL a,ULL b) {
    ULL ret=1;
    while(b) {
        if(b&1) ret*=a;
        a*=a;
        b>>=1;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ULL m;
    M t;
    t.a[0][0]=26,t.a[0][1]=0;
    t.a[1][0]=26,t.a[1][1]=1;
    while(cin>>n>>m) {
        init();
        for(int i=1;i<=n;i++) {
            string s;
            cin>>s;
            insert(s);
        }
        build();
        M tt;
        tt.a[0][0]=26,tt.a[0][1]=1;
        tt=tt*(t^(m-1));
        ULL res=tt.a[0][0];
        get_matrix();
        M b;
        for(int i=0;i<cnt;i++) b.a[0][i]=a.a[0][i];
        b.a[0][cnt]=1;
        b=b*(a^(m-1));
        for(int i=0;i<cnt;i++) res-=b.a[0][i];
        cout<<res<<'\n';
    }
    return 0;
}