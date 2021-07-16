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
//head
const int N=1e6+5;
int n;
string t1[N],t2[N],s[N];
bool cmp(const string &a,const string &b) {
    return SZ(a)>SZ(b);
}
int main() {
    #ifdef DEBUG
        freopen("E:/OneDrive/IO/in.txt","r",stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++)
        for(int j=0;s[i][j]&&s[i][j]!='#';j++)
            t1[i]+=s[i][j];
    sort(t1+1,t1+1+n,cmp);
    for(int i=2;i<=n;i++) {
        if(t1[1].substr(0,SZ(t1[i]))!=t1[i])
            return cout<<0<<'\n',0;
    }
    for(int i=1;i<=n;i++) {
        for(int j=SZ(s[i])-1;~j&&s[i][j]!='#';j--) t2[i]+=s[i][j];
        reverse(ALL(t2[i]));
    }
    sort(t2+1,t2+1+n,cmp);
    for(int i=2;i<=n;i++) {
        if(t2[1].substr(SZ(t2[1])-SZ(t2[i]),SZ(t2[i]))!=t2[i])
            return cout<<0<<'\n',0;
    }
    cout<<-1<<'\n';
    return 0;
}