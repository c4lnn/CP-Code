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
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=3*n/2;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
        }
        printf("%d\n",n/2);
    }
    return 0;
}