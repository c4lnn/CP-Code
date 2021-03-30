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
const int N=1e4+5;
string s[N];
int n;
set<string> res;
int get_min(const string &s) {
    int k=0,i=0,j=1;
    while(k<SZ(s)&&i<SZ(s)&&j<(SZ(s))) {
        if(s[(i+k)%SZ(s)]==s[(j+k)%SZ(s)]) ++k;
        else {
            s[(i+k)%SZ(s)]>s[(j+k)%SZ(s)]?i=i+k+1:j=j+k+1;
            if(i==j) ++i;
            k=0;
        }
    }
    return min(i,j);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    while(~scanf("%d",&n)) {
        res.clear();
        for(int i=1;i<=n;i++) {
            cin>>s[i];
            int pos=get_min(s[i]);
            res.insert(s[i].substr(pos,SZ(s[i])-pos)+s[i].substr(0,pos));
        }
        printf("%d\n",SZ(res));
    }
    return 0;
}