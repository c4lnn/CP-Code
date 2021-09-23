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
    int n;
    while(cin>>n) {
        VI a(n),cnt(10);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(ALL(a));
        LL sum=0;
        for(int i=0;i<n;i++) {
            if(a[i]%9) {
                int t=a[i]/9-cnt[a[i]%9];
                if(t) sum+=t;
                ++cnt[a[i]%9];
            }
            else {
                int t=a[i]/9-1-cnt[0];
                if(t) sum+=t;
                ++cnt[0];
            }
        }
        cout<<(sum&1?'A':'B')<<'\n';
    }
    return 0;
}