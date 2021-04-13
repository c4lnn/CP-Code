#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;char c;
    cin>>n>>c;
    int sum=1;
    for(int i=3;;i+=2) {
        if(sum+2*i>n) {
            int jj=0;
            for(int j=i-2;j>=1;j-=2,jj++) {
                for(int k=0;k<jj;k++) cout<<' ';
                for(int k=0;k<j;k++) cout<<c;
                cout<<'\n';
            }
            jj-=2;
            for(int j=3;j<=i-2;j+=2,jj--) {
                for(int k=0;k<jj;k++) cout<<' ';
                for(int k=0;k<j;k++) cout<<c;
                cout<<'\n';
            }
            cout<<n-sum<<'\n';
            break;
        }
        sum+=2*i;
    }
    return 0;
}