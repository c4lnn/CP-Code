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
const int N=1e6+5;
int mn[N];
LL phi[N];
VI p;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    for(int i=2;i<=1000000;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i),phi[i]=i-1;
        for(int j=0;j<SZ(p);j++) {
            if(p[j]>mn[i]||i*p[j]>1000000) break;
            mn[i*p[j]]=p[j];
            phi[i*p[j]]=i%p[j]?phi[i]*(p[j]-1):phi[i]*p[j];
        }
    }
    for(int i=3;i<=1000000;i++) phi[i]+=phi[i-1];
    int n;
    while(~scanf("%d",&n)&&n) {
        printf("%lld\n",phi[n]);
    }
    return 0;
}