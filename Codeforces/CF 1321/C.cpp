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
const int N=105;
int n,cnt,pre[N],nxt[N];
char s[N];
bool find(int x) {
    for(int i=nxt[0];i<=n;i=nxt[i]) {
        if(s[i]-'a'!=x) continue;
        if(pre[i]!=0&&s[pre[i]]-'a'==x-1||nxt[i]!=n+1&&s[nxt[i]]-'a'==x-1) {
            nxt[pre[i]]=nxt[i];
            pre[nxt[i]]=pre[i];
            ++cnt;
            return true;
        }
    }
    return false;
}
bool solve() {
    for(int i=25;i>=1;i--) if(find(i)) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s+1;
    nxt[0]=1;
    for(int i=1;i<=n;i++) {
        nxt[i]=i+1;
        pre[i]=i-1;
    }
    while(solve()) {}
    cout<<cnt<<'\n';
    return 0;
}