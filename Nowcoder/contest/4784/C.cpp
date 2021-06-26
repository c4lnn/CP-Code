#include<bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        long long n,m;
        cin>>n>>m;
        __int128 x=(__int128)n*(n-1)/2-m;
        long long l=0,r=n,ans;
        while(l<r) {
            long long mid=l+r+1>>1;
            if(x<=(__int128)(n-mid)*(n-mid+1)/2) l=mid;
            else r=mid-1;
        }
        cout<<l<<endl;
    }
    return 0;
}