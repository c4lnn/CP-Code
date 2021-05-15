#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        int t=0,mx=0;
        for(int i=1;i<=n;i++) {
            int x;
            cin>>x;
            t^=x;
            mx=max(mx,x);
        }
        cout<<(mx==1&&!t||mx>1&&t?"John":"Brother")<<'\n';
    }
    return 0;
}