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
int main() {
    int n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    printf("%d %d\n",x,y);
    int s;
    if(y!=m) {
        s=0;
        for(int i=1;i<=m;i++) if(i!=y) printf("%d %d\n",x,i);
    }
    else {
        s=1;
        for(int i=m-1;i>=1;i--) printf("%d %d\n",x,i);
    }
    for(int i=1;i<=n;i++) {
        if(i!=x) {
            if(s==1) for(int j=1;j<=m;j++) printf("%d %d\n",i,j),s=0;
            else for(int j=m;j>=1;j--) printf("%d %d\n",i,j),s=1;
        }
    }
    return 0;
}