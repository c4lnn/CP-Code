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
    int tt,n,m,res=0;
    scanf("%d",&tt);
    for(int i=1;i<=tt;i++) {
        scanf("%d%d",&n,&m);
        int t=(int)(log(n)/log(2))+1;
        if(t>m) res^=(i-1);
        else res^=i;
    }
    printf("%d\n",res);
    return 0;
}