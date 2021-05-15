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
const int N=1e6+5;
int a[N];
char s[N];
int main() {
    freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    getchar();
    for(int cs=1;cs<=tt;cs++) {
        gets(s);
        int cnt=0,res=0,t=0;
        for(int i=0;s[i];i++) {
            if(isdigit(s[i])) {
                t=t*10+s[i]-'0';
            }
            else {
                a[++cnt]=t;
                t=0;
            }
        }
        if(t) a[++cnt]=t;
        for(int i=1;i<=cnt;i++) {
            for(int j=i+1;j<=cnt;j++) {
                res=max(res,__gcd(a[i],a[j]));
            }
        }
        printf("%d\n",res);
    }
    return 0;
}