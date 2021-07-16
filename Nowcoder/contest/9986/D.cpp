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
    int n,cnt;
    while(cin>>n>>cnt) {
        int sum=0;
        for(int i=1;i<=n;i++) {
            int x;
            cin>>x;
            if(x==cnt) cnt=-1;
            else if(n!=2) sum=(sum+x)%11;
            else sum=x;
        }
        cout<<sum<<'\n';
    }
    return 0;
}