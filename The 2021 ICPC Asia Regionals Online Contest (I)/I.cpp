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
const int N=1e5+5;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int pos=0;
    VI b;
    while(cin>>a[pos]) {++pos;}
    for(int i=0;i<pos-2;i++) b.push_back(a[i]);
    sort(ALL(b));
    int x=a[pos-2],y=a[pos-1];
    int l=lower_bound(ALL(b),x-y)-b.begin();
    int r=upper_bound(ALL(b),x+y)-b.begin()-1;
    if(l<=r) {
        for(int i=r;i>=l;i--) {
            cout<<b[i]<<' ';
        }
    }
    else cout<<'\n';
    return 0;
}