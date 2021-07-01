#include<bits/stdc++.h>

using namespace std;

long long l[100],r[100];

void init() {
    l[1]=r[1]=1;
    for(int i=2;;i++) {
        l[i]=r[i-1]+1;
        r[i]=r[i-1]*2+(i%2==0?1:0);
        if(r[i]>=1e18){break;}
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t;cin>>t;
    while(t--) {
        long long n;
        cin>>n;
        int i=1;
        for(;;i++) if(n>=l[i]&&n<=r[i]) break;
        if(i%2) cout<<"XiaoQiao"<<endl;
        else cout<<"XiaoHuiHui"<<endl;
    }
    return 0;
}