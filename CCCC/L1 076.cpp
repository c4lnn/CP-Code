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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;DB m;cin>>n>>m;
    for(int i=1;i<=n;i++) {
        DB p;cin>>p;;
        if(p<m) printf("On Sale! %.1f\n",p);
    }
    return 0;
}