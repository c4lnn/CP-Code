#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
ll n,a[100],b[100];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        ll mn1=1e18,mn2=1e18;
        ll sum=0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),mn1=min(mn1,a[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&b[i]),mn2=min(mn2,b[i]);
        for(int i=1;i<=n;i++) {
            ll t1=a[i]-mn1,t2=b[i]-mn2;
            sum+=min(t1,t2)+abs(t2-t1);
        }
        printf("%lld\n",sum);
    }
    return 0;
}