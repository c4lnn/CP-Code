#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=105;
int n,nxt[N],extend[N];
string s[N];
void get_next(const string &t) {
    int l=0,r=0;
    nxt[0]=SZ(t);
    for(int i=1;i<SZ(t);i++) {
        if(i>r||i+nxt[i-l]>=r) {
            if(i>r) r=i;
            while(r<SZ(t)&&t[r]==t[r-i]) r++;
            nxt[i]=r-i;
            l=i;
        }
        else nxt[i]=nxt[i-l];
    }
}
bool get_extend(const string &s,const string &t) {
    get_next(t);
    int l=0,r=0;
    for(int i=0;i<SZ(s);i++) {
        if(i>r||i+nxt[i-l]>=r) {
            if(i>r) r=i;
            while(r<SZ(s)&&r-i<SZ(t)&&s[r]==t[r-i]) r++;
            extend[i]=r-i;
            l=i;
        }
        else extend[i]=nxt[i-l];
        if(extend[i]==SZ(t)) return true;
    }
    return false;
}
bool solve(const string &t) {
    for(int i=1;i<=n;i++) if(!get_extend(s[i],t)) return false;
    return true;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cin>>s[i];
        int id,mn=0x3f3f3f3f;
        for(int i=1;i<=n;i++) if(SZ(s[i])<mn) mn=SZ(s[i]),id=i;
        string res="";
        for(int l=0;l<SZ(s[id]);l++)
            for(int r=l;r<SZ(s[id]);r++) {
                string t=s[id].substr(l,r-l+1);
                if(!solve(t)) continue;
                if(SZ(t)>SZ(res)||SZ(t)==SZ(res)&&t<res) res=t;
            }
        if(SZ(res)<3) puts("no significant commonalities");
        else cout<<res<<'\n';
    }
    return 0;
}