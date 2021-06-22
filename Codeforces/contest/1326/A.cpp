#include<bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        int n;
        cin>>n;
        if(n==1) cout<<-1<<endl;
        else {
            for(int i=1;i<n-1;i++) cout<<2;
            if((2*(n-1)%3!=0)) cout<<23<<endl;
            else cout<<33<<endl;
        }
    }
    return 0;
}