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
const int N=1e5+5;
char s[N];
int cnt[30];
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        memset(cnt,0,sizeof cnt);
        scanf("%s",s+1);
        int len=strlen(s+1);
        bool f=false;
        for(int i=1;i<=len;i++) cnt[s[i]-'a']++;
        int res=0;
        for(int i=0;i<=25;i++) res=max(res,cnt[i]);
        printf("Case #%d: %d\n",cs,res);
    }
    return 0;
}