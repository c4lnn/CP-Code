#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    VI res;
    for(int i=10;i<=99;i++) {
        int sum=i/10+i%10;
        if(sum*2>n||n-sum*2>9) continue;
        res.PB(i*1000+(n-sum*2)*100+i%10*10+i/10);
    }
    for(int i=100;i<=999;i++) {
        int sum=i/100+i/10%10+i%10;
        if(sum*2!=n) continue;
        res.PB(i*1000+i%10*100+i/10%10*10+i/100);
    }
    sort(ALL(res));
    if(SZ(res)) {
        for(int i=0;i<SZ(res);i++) cout<<res[i]<<'\n';
    }
    else cout<<-1<<'\n';
    return 0;
}