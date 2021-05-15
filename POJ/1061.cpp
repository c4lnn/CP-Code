#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if(!b) {x=1;y=0;return a;}
    LL ret=exgcd(b,a%b,x,y);
    LL z=x;
    x=y,y=z-a/b*y;
    return ret;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    LL a,b,m,n,l;
    scanf("%lld%lld%lld%lld%lld",&a,&b,&m,&n,&l);
    LL x,y;
    if(a>b) swap(a,b),swap(m,n);
    b-=a;
    m-=n;
    if(m<0) m=-m,b=-b;
    LL t=exgcd(m,l,x,y);
    if(b%t) puts("Impossible");
    else {
        x=b/t*x;
        LL tt=l/t;
        x=(x%tt+tt)%tt;
        printf("%lld\n",x);
    }
    return 0;
}