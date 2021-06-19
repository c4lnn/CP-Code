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
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        VI a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        sort(ALL(a));
        if(n==2) {
            cout<<a[0]<<' '<<a[1]<<'\n';
            continue;
        }
        int d=INT_MAX,pos;
        for(int i=1;i<n;i++) {
            if(a[i]-a[i-1]<d) {
                d=a[i]-a[i-1];
                pos=i;
            }
        }
        if(pos==n-1) {
            cout<<a[pos]<<' ';
            for(int i=0;i<n-2;i++) cout<<a[i]<<' ';
            cout<<a[pos-1]<<'\n';
        }
        else {
            cout<<a[pos-1]<<' ';
            for(int i=pos+1;i<n;i++) cout<<a[i]<<' ';
            for(int i=0;i<pos-1;i++) cout<<a[i]<<' ';
            cout<<a[pos]<<'\n';
        }
    }
    return 0;
}