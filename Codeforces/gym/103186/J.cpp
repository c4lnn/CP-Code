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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    VI a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(ALL(a),greater<int>());
    LL aa=0,bb=0;
    for(int i=0;i<n;i++) {
        if(i&1) bb+=a[i];
        else aa+=a[i];
    }
    LL res=abs(aa)-abs(bb);
    aa=0,bb=0;
    sort(ALL(a));
    for(int i=0;i<n;i++) {
        if(i&1) bb+=a[i];
        else aa+=a[i];
    }
    cout<<max(res,abs(aa)-abs(bb))<<'\n';
    return 0;
}