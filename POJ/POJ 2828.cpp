#include <cstdio>
#include <iostream>
using namespace std;
const int N=2e5+5;
int n,a[N],val[N],x[N],y[N];
int lowbit(int x) {
    return x&-x;
}
void update(int x) {
    for(int i=x;i<=n;i+=lowbit(i)) ++a[i];
}
int query(int x) {
    int ret=0;
    for(int i=x;i;i-=lowbit(i)) ret+=a[i];
    return ret;
}
int main() {
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n;i++) a[i]=0;
        for(int i=1;i<=n;i++) {
            scanf("%d%d",&x[i],&y[i]);
            ++x[i];
        }
        for(int i=n;i>=1;i--) {
            int l=x[i],r=n;
            while(l<r) {
                int mid=l+r>>1;
                if(mid-query(mid)>=x[i]) r=mid;
                else l=mid+1;
            }
            update(l);
            val[l]=y[i];
        }
        for(int i=1;i<=n;i++) printf("%d ",val[i]);
        puts("");
    }
    return 0;
}