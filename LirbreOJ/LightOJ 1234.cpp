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
DB t[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    DB sum=0;
    for(int i=1;i<=100000000;i++) {
        sum+=1.0/i;
        if(i%100==0) t[i/100]=sum;
    }
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        int n;
        scanf("%d",&n);
        DB res=t[n/100];
        for(int i=n;i%100!=0;i--) res+=1.0/i;
        printf("Case %d: %.10f\n",cs,res);
    }
    return 0;
}