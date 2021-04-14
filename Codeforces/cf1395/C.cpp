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
int a[205],b[205];
int n,m;
bool judge(int x) {
    for(int i=1;i<=n;i++) {
        int j;
        for(j=1;j<=m;j++) {
            int t=a[i]&b[j];
            int k;
            for(k=0;k<9;k++) if(((x>>k)&1)==0&&((t>>k)&1)==1) break;
            if(k==9) break;
        }
        if(j>m) return false;
    }
    return true;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    int res=0;
    for(int i=0;i<1<<9;i++) {
        if(judge(i)) {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}