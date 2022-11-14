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
struct AC {
    int tr[N][26],fail[N],len[N],id[N],last[N],tot[N],sz; // fail 指针指向与当前前缀匹配的最长后缀的位置
    void init() {
        for(int i=0;i<=sz;i++) {
            for(int j=0;j<26;j++) tr[i][j]=0;
            fail[i]=tot[i]=0;
        }
        sz=0;
    }
    void insert(const string &s,int i) {
        int u=0;
        for(auto c:s) {
            int v=c-'a';
            if(!tr[u][v]) {
                tr[u][v]=++sz;
                len[sz]=len[u]+1;
                last[sz]=0xc0c0c0c0;
            }
            u=tr[u][v];
        }
        id[i]=u;
    }
    void build() {
        queue<int> q;
        for(int v=0;v<26;v++) if(tr[0][v]) q.push(tr[0][v]);
        while(SZ(q)) {
            int u=q.front();
            q.pop();
            for(int v=0;v<26;v++) {
                if(tr[u][v]) fail[tr[u][v]]=tr[fail[u]][v],q.push(tr[u][v]);
                else tr[u][v]=tr[fail[u]][v];
            }
        }
    }
} ac;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        ac.init();
        string s;cin>>s;
        int n;cin>>n;
        for(int i=1;i<=n;i++) {
            string t;cin>>t;
            ac.insert(t,i);
        }
        ac.build();
        int u=0;
        for(int i=0;i<SZ(s);i++) {
            int v=s[i]-'a';
            u=ac.tr[u][v];
            int t=u;
            while(t) {
                if(ac.last[t]+ac.len[t]<=i) {
                    ++ac.tot[t];
                    ac.last[t]=i;
                }
                t=ac.fail[t];
            }
        }
        for(int i=1;i<=n;i++) cout<<ac.tot[ac.id[i]]<<'\n';
    }
    return 0;
}