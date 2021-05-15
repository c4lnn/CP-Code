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
const int N=1e6+5;
char s[N];
int nxt[N],res[N];
void get_next(const string &t) {
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<SZ(t)) {
        if(j==-1||t[i]==t[j]) {
            ++i,++j;
            nxt[i]=j;
        }
        else j=nxt[j];
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        scanf("%s",s);
        get_next(s);
        int len=strlen(s);
        int t=len,cnt=0;
        while(nxt[t]!=-1) res[++cnt]=len-nxt[t],t=nxt[t];
        printf("Case #%d: %d\n",cs,cnt);
        sort(res+1,res+1+cnt);
        for(int i=1;i<=cnt;i++) printf("%d%c",res[i],i==cnt?'\n':' ');
    }
    return 0;
}