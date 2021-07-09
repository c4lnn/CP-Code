#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const int N=1e5+5;
int a[N];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        int cnt=0;
        int mn=0x3f3f3f3f;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            if(a[i]) mn=min(mn,a[i]);
            if(!a[i]) cnt++;
        }
        sort(a+1,a+1+n);
        swap(a[1],a[cnt+1]);
        swap(a[2],a[cnt+2]);
        int t=0;
        for(int i=n;i>=2;i--) {
            a[i]*=mn;
            a[i]+=t;
            t=a[i]/10;
            a[i]%=10;
        }
        if(t) printf("%d",t);
        for(int i=2;i<=n;i++) printf("%d",a[i]);
        puts("");
    }
    return 0;
}