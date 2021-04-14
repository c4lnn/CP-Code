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
        int a,b;
        cin>>a>>b;
        if(b-a%b==b) cout<<0<<endl;
        else cout<<b-a%b<<endl;
    }
    return 0;
}