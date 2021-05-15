#include <iostream>
#include <algorithm>
using namespace std;
const int N=1005;
int a[N],b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1]-1;
        int sum=0;
        for(int i=n;i>=1;i-=2) sum^=b[i];
        cout<<(sum?"Georgia will win":"Bob will win")<<'\n';
    }
    return 0;
}