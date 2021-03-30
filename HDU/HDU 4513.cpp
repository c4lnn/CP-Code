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
const int N=1e5+5;
int a[N],t[N<<1],len[N<<1],n;
int manacher() {
    t[0]=266;
    int k=0;
    for(int i=1;i<=n;i++) t[++k]=1,t[++k]=a[i];
    t[++k]=1;
    int res=0,mx=0,id=0;
    for(int i=1;i<=k;i++) {
        len[i]=i<mx?min(mx-i,len[2*id-i]):1;
        while(i-len[i]>=0&&i+len[i]<=k&&t[i-len[i]]==t[i+len[i]]&&((t[i-len[i]]==1||len[i]==1)?true:t[i-len[i]]<=t[i-len[i]+2])) ++len[i];
        if(i+len[i]>mx) {
            mx=i+len[i];
            id=i;
            if(len[i]>res) res=len[i];
        }
    }
    return res-1;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        printf("%d\n",manacher());
    }
    return 0;
}