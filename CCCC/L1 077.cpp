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
    VI a(30);
    for(int i=0;i<=23;i++) cin>>a[i];
    int x;
    while(cin>>x) {
        if(x<0||x>23) break;
        cout<<a[x]<<' '<<(a[x]>50?"Yes":"No")<<'\n';
    }
    return 0;
}