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
const int N=2005;
char s[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>s[i];
    }
    string t;cin>>t;
    int res=0,cnt=0;
    for(int i=0;i<n;i++) {
        cnt=0;
        for(int j=0;j<n;j++) {
            if(s[i][j]=='1') cnt=0;
            else {
                ++cnt;
                if(cnt>=m) ++res;
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}