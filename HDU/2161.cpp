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
const int N=2e4+5;
int mn[N];
VI p;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    for(int i=2;i<=16000;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>16000) break;
            mn[i*x]=x;
        }
    }
    for(int cs=1;;cs++) {
        int n;
        scanf("%d",&n);
        if(n<=0) break;
        printf("%d: ",cs);
        puts((n!=2&&mn[n]==n)?"yes":"no");
    }
    return 0;
}