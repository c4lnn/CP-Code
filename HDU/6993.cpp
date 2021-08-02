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
char s[31][101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        for(int i=0;i<30;i++) cin>>s[i];
        cout<<"Case #"<<cs<<":\n";
        int l=0,r=0;
        for(int j=0;j<100;j++) {
            bool f=false;
            for(int i=0;i<30;i++) if(s[i][j]=='#') {
                f=true;
                if(!l) l=r=j;
                else ++r;
                break;
            }
            if(!f) {
                if(l&&j-l==9) {
                    int t=j+1;
                    for(int i=0;i<30;i++) if(s[i][t]=='#') {
                        f=true;
                        ++r;
                        break;
                    }
                }
                if(l&&j-l==3) {
                    int t=j+4;
                    for(int i=0;i<30;i++) if(s[i][t]=='#') {
                        bool f=false;
                        for(int k=0;k<30;k++) if(s[k][t+6]=='#') {
                            r=t+6;
                            j=r+1;
                            f=true;
                            break;
                        }
                        if(f) break;
                    }
                }
            }
            if(!f&&l) {
                cout<<l+1<<' '<<r+1<<'\n';
                l=0;
            }
        }
    }
    return 0;
}