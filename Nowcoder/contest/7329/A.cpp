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
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        DB n;
        scanf("%lf",&n);
        DB a=n*6,b=n*0.5;
        while(a>=360) a-=360;
        while(b>=360) b-=360;
        if(a>b) printf("%d\n",(int)(min(a-b,360-a+b)+0.5));
        else printf("%d\n",(int)(min(b-a,360-b+a)+0.5));
    }
    return 0;
}