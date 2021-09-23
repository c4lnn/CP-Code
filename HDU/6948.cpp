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
    int k;string s;
    while(cin>>k>>s) {
        int res=0;
        VI cnt(26);
        queue<int> q[26];
        for(int l=0,r=0;r<SZ(s);r++) {
            int x=s[r]-'a';
            ++cnt[x];
            q[x].push(r);
            int t=0;
            for(int i=cnt[x];i>k;i--) {
                t=q[x].front()+1;
                q[x].pop();
            }
            while(l<t) {
                int y=s[l++]-'a';
                --cnt[y];
                if(y!=x) q[y].pop();
            }
            res=max(res,r-l+1);
        }
        cout<<res<<'\n';
    }
    return 0;
}