#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],s[N];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int f=0;
    if(n&1) {
        if(s[n]-s[n>>1]-s[n>>1]<s[n]-s[n+1>>1]-s[n+1>>1]) f=1;
    }
    int a=n/2+f,b=n-a;
    cout<<"Outgoing #: "<<b<<'\n';
    cout<<"Introverted #: "<<a<<'\n';
    cout<<"Diff = "<<s[n]-s[a]-s[a]<<'\n';
    return 0;
}