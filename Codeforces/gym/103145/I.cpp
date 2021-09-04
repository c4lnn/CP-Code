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
const int a[]={7,27,41,49,63,78,108};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        int sum=0;
        for(int i=0;i<n;i++) {
            int x;cin>>x;
            sum+=a[x-1];
        }
        if(sum>=120) sum-=50;
        else if(sum>=89) sum-=30;
        else if(sum>=69) sum-=15;
        cout<<sum<<'\n';
    }
    return 0;
}