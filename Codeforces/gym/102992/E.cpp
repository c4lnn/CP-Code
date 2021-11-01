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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
const int DIR[4][2]={0,1,0,-1,-1,0,1,0};
const char S[]="UDLR";
int x,y,cnt[4];
bool solve() {
    VI a={0,1,2,3};
        do {
            int xx=0,yy=0;
            bool f=false;
            for(int i=0;i<4;i++) {
                for(int j=0;j<cnt[a[i]];j++) {
                    xx+=DIR[a[i]][0],yy+=DIR[a[i]][1];
                    if(xx==x&&yy==y) {f=true;break;}
                }
                if(f) break;
            }
            if(!f) {
                for(int i=0;i<4;i++) {
                    for(int j=0;j<cnt[a[i]];j++) {
                        cout<<S[a[i]];
                    }
                }
                cout<<'\n';
                return true;
            }
        }while(next_permutation(ALL(a)));
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        string s;cin>>x>>y>>s;
        memset(cnt,0,sizeof cnt);
        for(auto c:s) {
            if(c=='U') ++cnt[0];
            else if(c=='D') ++cnt[1];
            else if(c=='L') ++cnt[2];
            else ++cnt[3];
        }
        if(x==0&&y==0||!solve()) cout<<"Impossible\n";
    }
    return 0;
}