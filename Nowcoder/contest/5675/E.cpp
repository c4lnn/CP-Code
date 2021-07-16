#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const int N=1e5+5;
int n,a[N],s[N];
signed main() {
    int T;
    scanf("%lld",&T);
    while(T--) {
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) {
            scanf("%lld",&a[i]);
            s[i]=s[i-1]+a[i];
        }
        int t=s[n]/n+(s[n]%n>0);
        for(int i=1;i<=n;i++) {
            if(a[i]<=t) a[i+1]-=t-a[i];
            else if(a[i]>t) {
                int temp=s[i]/i+(s[i]%i>0);
                a[i+1]-=(temp-t)*(i-1)-(a[i]-temp);
                t=temp;
            }
        }
        printf("%lld\n",t);
    }
    return 0;
}

/*
1
4
3 8 2 2

*/