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
const int N=205;
int w[N][N],la[N],lb[N],ma[N],mb[N],vb[N],slk[N],pre[N];
string s[N];
int km(int n) {
    for(int i=1;i<=n;i++) {
        la[i]=0xc0c0c0c0;
        lb[i]=ma[i]=mb[i]=0;
        for(int j=1;j<=n;j++) la[i]=max(la[i],w[i][j]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) vb[j]=pre[j]=0,slk[j]=0x3f3f3f3f;
        int b=0,p=-1;
        for(mb[b]=i;mb[b];b=p) {
            int d=0x3f3f3f3f,a=mb[b];
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
    for(int i=1;i<=n;i++) res+=w[i][ma[i]];
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n) {
        for(int i=1;i<=n;i++) cin>>s[i];
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) if(i!=j) {
                int t1=SZ(s[i])-1,t2=0,len=0;
                while(~t1&&t2<SZ(s[j])&&s[i][t1]==s[j][t2]) ++len,--t1,++t2;
                w[i][j]=len;
            }
        }
        cout<<km(n)<<'\n';
    }
    return 0;
}