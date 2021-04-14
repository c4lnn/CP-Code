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
//head
LL a[5];
char s[5];
LL dfs1(LL a,LL b,LL c) {
    if(s[1]=='+'&&s[2]=='*') return min({(a+b)*c,(a+c)*b,(b+c)*a});
    else if(s[1]=='+'&&s[2]=='+') return a+b+c;
    else if(s[1]=='*'&&s[2]=='+') return min({a*b+c,a*c+b,b*c+a});
    return a*b*c;
}
LL dfs2(LL a,LL b,LL c,LL d) {
    if(s[0]=='+') return min({dfs1(a+b,c,d),dfs1(a+c,b,d),dfs1(a+d,b,c),dfs1(b+c,a,d),dfs1(b+d,a,c),dfs1(c+d,a,b)});
    return min({dfs1(a*b,c,d),dfs1(a*c,b,d),dfs1(a*d,b,c),dfs1(b*c,a,d),dfs1(b*d,a,c),dfs1(c*d,a,b)});
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    for(int i=0;i<4;i++) cin>>a[i];
    for(int i=0;i<3;i++) cin>>s[i];
    cout<<dfs2(a[0],a[1],a[2],a[3])<<"\n";
    return 0;
}