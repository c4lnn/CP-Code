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
const int N=505;
int id[20],tr[N][4],tot[N],fail[N],sz;
void init() {
    for(int i=0;i<=sz;i++) for(int j=0;j<4;j++) tr[i][j]=0;
    for(int i=0;i<=sz;i++) fail[i]=tot[i]=0;
    sz=0;
}
void insert(const string &s) {
    int u=0;
    for(auto c:s) {
        int v=id[c-'A'];
        if(!tr[u][v]) tr[u][v]=++sz;
        u=tr[u][v];
    }
    ++tot[u];
}
void build() {
    queue<int> q;
    for(int i=0;i<4;i++) if(tr[0][i]) q.push(tr[0][i]);
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
            else tr[u][i]=tr[fail[u]][i];
        }
        tot[u]+=tot[fail[u]];
    }
}
int solve(const string &s) {
    int a=0,b=0,c=0,d=0;
    for(auto ch:s) {
        if(ch=='A') ++a;
        else if(ch=='C') ++b;
        else if(ch=='G') ++c;
        else ++d;
    }
    vector<vector<vector<vector<vector<int>>>>> dp(a+1,vector<vector<vector<vector<int>>>>(b+1,vector<vector<vector<int>>>(c+1,vector<vector<int>>(d+1,vector<int>(sz+1)))));
    for(int aa=0;aa<=a;aa++)
        for(int bb=0;bb<=b;bb++)
            for(int cc=0;cc<=c;cc++)
                for(int dd=0;dd<=d;dd++)
                    for(int i=0;i<=sz;i++)
                        dp[aa][bb][cc][dd][i]=0xc0c0c0c0;
    dp[0][0][0][0][0]=0;
    for(int aa=0;aa<=a;aa++)
        for(int bb=0;bb<=b;bb++)
            for(int cc=0;cc<=c;cc++)
                for(int dd=0;dd<=d;dd++)
                    for(int i=0;i<=sz;i++) {
                        if(aa<a) dp[aa+1][bb][cc][dd][tr[i][0]]=max(dp[aa+1][bb][cc][dd][tr[i][0]],dp[aa][bb][cc][dd][i]+tot[tr[i][0]]);
                        if(bb<b) dp[aa][bb+1][cc][dd][tr[i][1]]=max(dp[aa][bb+1][cc][dd][tr[i][1]],dp[aa][bb][cc][dd][i]+tot[tr[i][1]]);
                        if(cc<c) dp[aa][bb][cc+1][dd][tr[i][2]]=max(dp[aa][bb][cc+1][dd][tr[i][2]],dp[aa][bb][cc][dd][i]+tot[tr[i][2]]);
                        if(dd<d) dp[aa][bb][cc][dd+1][tr[i][3]]=max(dp[aa][bb][cc][dd+1][tr[i][3]],dp[aa][bb][cc][dd][i]+tot[tr[i][3]]);
                    }
    int mx=0;
    for(int i=0;i<=sz;i++) mx=max(mx,dp[a][b][c][d][i]);
    return mx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    id[0]=0,id[2]=1,id[6]=2,id[19]=3;
    int n,cs=0;
    while(cin>>n) {
        if(!n) break;
        init();
        string s;
        for(int i=1;i<=n;i++) {
            cin>>s;
            insert(s);
        }
        cin>>s;
        build();
        cout<<"Case "<<++cs<<": "<<solve(s)<<'\n';
    }
    return 0;
}