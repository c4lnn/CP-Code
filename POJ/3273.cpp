#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e6+5;

int n,m;
int a[N];

bool check(int x) {
    int sum=0,t=1;
    for(int i=1;i<=n;i++) {
        if(sum+a[i]<=x) {
            sum+=a[i];
        }
        else {
            sum=a[i];
            t++;
        }
    }
    return t<=m;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
       cin>>n>>m;
    int l=0,r=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        l=max(l,a[i]);
        r+=a[i];
    }
    while(l<r) {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}