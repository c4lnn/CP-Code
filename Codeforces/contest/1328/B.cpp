#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
//head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        int res;
        int t1,t2;
        int pre=0;
        for(int i=2,j=0,t=1;;i++) {
            j+=t;
            t++;
            if(k<=j) {t1=i,t2=k-pre;break;}
            pre=j;
        }
        for(int i=n;i>=1;i--) {
            if(i==t1||i==t2) cout<<'b';
            else cout<<'a';
        }
        cout<<endl;
    }
    return 0;
}