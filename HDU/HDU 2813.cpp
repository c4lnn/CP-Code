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
const int INF=0x3f3f3f3f;
const int N=205;
int w[N][N],la[N],lb[N],ma[N],mb[N],vb[N],slk[N],pre[N];
unordered_map<string,int> mp1,mp2;
int km(int n,int nn) {
    for(int i=1;i<=n;i++) {
        la[i]=-INF;
        lb[i]=ma[i]=mb[i]=0;
        for(int j=1;j<=n;j++) la[i]=max(la[i],w[i][j]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) vb[j]=pre[j]=0,slk[j]=INF;
        int b=0,p=-1;
        for(mb[b]=i;mb[b];b=p) {
            int d=INF,a=mb[b];
            vb[b]=1;
            for(int j=1;j<=n;j++)
                if(!vb[j]) {
                    int t=la[a]+lb[j]-w[a][j];
                    if(t<slk[j]) slk[j]=t,pre[j]=b;
                    if(slk[j]<d) d=slk[j],p=j;
                }
            for(int j=0;j<=n;j++) {
                if(vb[j]) la[mb[j]]-=d,lb[j]+=d;
                else slk[j]-=d;
            }
        }
        for(;b;b=pre[b]) mb[b]=mb[pre[b]],ma[mb[b]]=b;
    }
    int res=0;
    for(int i=1;i<=nn;i++) res+=w[i][ma[i]];
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    while(cin>>n>>m>>k) {
        int cnt1=0,cnt2=0;
        mp1.clear(),mp2.clear();
        memset(w,0xc0,sizeof w);
        for(int i=1;i<=k;i++) {
            string s1,s2;
            cin>>s1>>s2;
            if(!mp1.count(s1)) mp1[s1]=++cnt1;
            if(!mp2.count(s2)) mp2[s2]=++cnt2;
            int u=mp1[s1],v=mp2[s2];
            cin>>w[u][v];
            w[u][v]=-w[u][v];
        }
        cout<<-km(max(n,m),n)<<'\n';
    }
    return 0;
}