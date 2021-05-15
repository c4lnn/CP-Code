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
int mn[N],sum[N];
VI p;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    for(int i=2;i<=1000000;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>1000000) break;
            mn[i*x]=x;
        }
    }
    for(int i=0;i<=10000;i++) {
        int t=i*i+i+41;
        for(auto x:p) {
            if(x*x>t) break;
            if(t%x==0) {
                sum[i]=1;
                break;
            }
        }
    }
    for(int i=1;i<=10000;i++) sum[i]+=sum[i-1];
    int l,r;
    while(~scanf("%d%d",&l,&r)) {
        printf("%.2f\n",100.0*(r-l+1-sum[r]+sum[l-1])/(r-l+1)+1e-6);
    }
    return 0;
}