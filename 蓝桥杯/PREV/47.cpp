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
const DB EPS=1e-3;
const int N=1e4+5;
PII a[N];
multiset<PII> s;
bool check(int mid) {
    int l=0;
    multiset<PII> t=s;
    while(1) {
        bool f=false;
        for(set<PII>::iterator it=t.begin();it!=t.end();it++) {
            int x=it->SE,y=it->FI;
            if(x-mid<=l&&y+mid>=l) {
                f=true;
                if(l<=x+mid) l+=y-x;
                else l=y+mid;
                t.erase(it);
                break;
            }
        }
        if(!f||l>=20000) break;
    }
    return l>=20000;
}
int main() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x,y;cin>>x>>y;
        s.insert(MP(y<<1,x<<1));
    }
    int l=0,r=20000;
    while(l<r) {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l%2==0) cout<<l/2<<'\n';
    else cout<<fixed<<setprecision(1)<<l/2.0<<'\n';
    return 0;
}