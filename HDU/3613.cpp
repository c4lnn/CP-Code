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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=5e5+5;
char s[N],t[N<<1];
int len[N<<1],sum[N<<1],v[100];
int manacher(const string &s) {
    t[0]='$';
    int k=0,mx=0,id=0;
    for(int i=0;s[i];i++) t[++k]='#',t[++k]=s[i];
    t[++k]='#';
    for(int i=1;i<=k;i++) sum[i]=sum[i-1]+(t[i]=='#'?0:v[t[i]-'a']);
    for(int i=1;i<=k;i++) {
        len[i]=i<mx?min(mx-i,len[2*id-i]):1;
        while(i-len[i]>=1&&i+len[i]<=k&&t[i-len[i]]==t[i+len[i]]) ++len[i];
        if(i+len[i]>mx) {
            mx=len[i]+i;
            id=i;
        }
    }
    int res=0;
    for(int i=2;i<=k;i++) {
        int w=0;
        if(i!=(k+1)/2&&i-len[i]==0) w+=sum[i+len[i]-1];
        int pos=i+len[i]-1+(k-i-len[i]+2)/2;
        if(pos+len[pos]-1==k) w+=sum[k]-sum[i+len[i]-1];
        res=max(res,w);
    }
    return res;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        for(int i=0;i<26;i++) scanf("%d",&v[i]);
        scanf("%s",s);
        printf("%d\n",manacher(s));
    }
    return 0;
}