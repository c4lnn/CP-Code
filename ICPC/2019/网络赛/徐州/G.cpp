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
char t[N<<1];
int pos[26],nxt[N][26],len[N<<1];
LL manacher(const string &s) {
    int k=0,mid=0,r=0;
    LL res=0;
    t[0]='$';
    for(int i=0;s[i];i++) t[++k]='#',t[++k]=s[i];
    t[++k]='#';
    for(int i=1;i<=k;i++) {
        len[i]=i<r?min(r-i,len[2*mid-i]):1;
        while(i-len[i]>=1&&i+len[i]<=k&&t[i-len[i]]==t[i+len[i]]) ++len[i];
        if(len[i]+i>r) {
            r=len[i]+i;
            mid=i;
        }
        int ll=(i-1)/2,rr=(i+len[i]-1)/2-1;
        for(int j=0;j<26;j++) if(nxt[ll][j]<=rr) {
            res+=rr-nxt[ll][j]+1;
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;cin>>s;
    memset(pos,0x3f,sizeof pos);
    for(int i=SZ(s);~i;i--) {
        pos[s[i]-'a']=i;
        for(int j=0;j<26;j++) {
            nxt[i][j]=pos[j];
        }
    }
    cout<<manacher(s)<<'\n';
    return 0;
}