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
        string s;cin>>s;
        string t=s;
        bool f=false;
        VI v;
        for(int i=0;i<8;i++) if(s[i]=='0') {
            for(int j=0;j<8;j++) if(i!=j&&s[j]=='0') v.PB(j);
            do {
                for(auto x:v) {
                    if(s[(x+3)%8]=='0'||s[(x+5)%8]=='0') {
                        s[x]='1';
                    }
                    else break;
                }
                int cnt=0;
                for(int j=0;j<8;j++) if(s[j]=='1') ++cnt;
                if(cnt==7) {f=true;break;}
                s=t;
            } while(next_permutation(ALL(v)));
            if(f) break;
            v.clear();
            s=t;
        }
        cout<<(f?"Yes":"No")<<'\n';
    }
    return 0;
}