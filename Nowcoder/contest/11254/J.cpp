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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
namespace GenHelper
{
    unsigned z1,z2,z3,z4,b,u;
    unsigned get()
    {
        b=((z1<<6)^z1)>>13;
        z1=((z1&4294967294U)<<18)^b;
        b=((z2<<2)^z2)>>27;
        z2=((z2&4294967288U)<<2)^b;
        b=((z3<<13)^z3)>>21;
        z3=((z3&4294967280U)<<7)^b;
        b=((z4<<3)^z4)>>12;
        z4=((z4&4294967168U)<<13)^b;
        return (z1^z2^z3^z4);
    }
    bool read() {
      while (!u) u = get();
      bool res = u & 1;
      u >>= 1; return res;
    }
    void srand(int x)
    {
        z1=x;
        z2=(~x)^0x233333333U;
        z3=x^0x1234598766U;
        z4=(~x)+51;
        u = 0;
    }
}
using namespace GenHelper;
bool edge[8005][8005];
int deg[8005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, seed;
    cin >> n >> seed;
    srand(seed);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            edge[j+1][i+1] = edge[i+1][j+1] = read();
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) if(edge[i][j]==1) {
            ++deg[i],++deg[j];
        }
    }
    LL sum=0;
    for(int i=1;i<=n;i++) sum+=deg[i]*(n-1-deg[i]);
    cout<<n*(n-1)*(n-2)/6-sum<<'\n';
    return 0;
}