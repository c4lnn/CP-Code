#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const int N=1e4+5;
int mn[N],sum[N],cnt[N];
VI p;
void prime_seive(int n) {
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(int j=0;j<SZ(p);j++) {
            int x=p[j];
            if(x>mn[i]||x*i>n) break;
            mn[i*x]=x;
        }
    }
    sum[0]=p[0];
    for(int i=1;i<SZ(p);i++) sum[i]=sum[i-1]+p[i];
    for(int i=0;i<SZ(p);i++) {
        for(int j=i;j<SZ(p);j++) {
            int d=sum[j]-(!i?0:sum[i-1]);
            if(d>n) break;
            ++cnt[d];
        }
    }
}
int main() {
    prime_seive(10000);
    int n;
    while(~scanf("%d",&n)&&n) {
        cout<<cnt[n]<<'\n';
    }
    return 0;
}