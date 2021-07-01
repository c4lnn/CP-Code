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
const int N=2e6+5;
int a[N],sum[N],n,k,q;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+(a[i]==a[i-1]?0:1);
    }
    for(int i=1;i<=q;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        puts(sum[r]-sum[l-1]+(sum[l]==sum[l-1])>=k?"Yes":"No");
    }
    return 0;
}