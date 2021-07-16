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
const int N=1e5+5;
int n,k,a[N];
bool check(int mid) {
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(a[i]>mid) cnt+=(int)ceil(1.0*(a[i]-mid)/(k-1));
        if(cnt>mid) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int l=1,r=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        r=max(r,a[i]);
    }
    cin>>k;
    if(k==1) {
        cout<<r<<'\n';
    }
    else {
        while(l<r) {
            int mid=l+r>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        cout<<l<<'\n';
    }
    return 0;
}