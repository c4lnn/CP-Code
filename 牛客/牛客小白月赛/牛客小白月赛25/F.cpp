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
    int n,m,sum=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n-m;i++) {
        int x;
        scanf("%d",&x);
        sum+=x;
    }
    printf("%.5f %.5f\n",(double)(sum+m)/n,(double)(sum+m*5)/n);
    return 0;
}