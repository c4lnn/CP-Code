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
const DB EPS=1e-9;;
const DB E=2.718281828;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    DB a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    DB l=0,r=1e9;
    for(int i=0;i<10000;i++) {
        DB mid=(l+r)/2.0;
        if(pow(mid,a)+b*log(mid)/log(E)-c<EPS) l=mid;
        else r=mid;
    }
    printf("%.14f\n",l);
    return 0;
}