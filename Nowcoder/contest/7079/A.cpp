#include<bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
int n,q;
int a[N],pre[N],suf[N];
int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    pre[0]=n;
    for(int i=1;i<=n;i++) pre[i]=min(pre[i-1],a[i]);
    suf[n+1]=n;
    for(int i=n;i>=1;i--) suf[i]=min(suf[i+1],a[i]);
    for(int i=1;i<=q;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",min(pre[l-1],suf[r+1]));
    }
    return 0;
}