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
int nxt[30];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;string s;cin>>n>>s;
        memset(nxt,0,sizeof nxt);
        bool f=false;
        for(int i=SZ(s)-1;~i;i--) {
            if(nxt[s[i]-'A']&&nxt[s[i]-'A']!=i+1) {
                    f=true;
                    break;
            }
            nxt[s[i]-'A']=i;
        }
        cout<<(f?"NO":"YES")<<'\n';
    }
    return 0;
}