#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=3e5+5;
char s[N];
int n,m,tot[2];
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        memset(tot,0,sizeof tot);
        scanf("%s",s+1);
        bool f=false;
        for(int l=1,r=1;r<=n;r++) {
            if(r-l+1>m) {
                if(s[l]!='?') tot[s[l]-'0']--;
                l++;
            }
            if(s[r]=='?') {
                if(r-m>=1&&s[r-m]!='?') s[r]=s[r-m],tot[s[r]-'0']++;
            }
            else if(s[r]=='0') {
                if(r-m>=1&&s[r-m]=='1') {f=true;break;}
                tot[0]++;
            }
            else {
                if(r-m>=1&&s[r-m]=='0') {f=true;break;}
                tot[1]++;
            }
            if(tot[0]>m/2||tot[1]>m/2) {f=true;break;}
        }
        puts(f?"NO":"YES");
    }
    return 0;
}