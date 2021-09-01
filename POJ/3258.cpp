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
const int N=5e4+5;
int a[N],len,n,m;
bool check(int mid) {
    int t=m,l=0,r=n;
    while(len-a[r]<mid) {
        if(t) --t;
        else return false;
        --r;
    }
    for(int i=1;i<=r;i++) {
        if(a[i]-a[l]<mid) {
            if(t) --t;
            else return false;
        }
        else l=i;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>len>>n>>m;
    a[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a,a+n+1);
    int l=1,r=len;
    while(l<r) {
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
    return 0;
}