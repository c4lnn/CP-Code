#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        int h1,a1,h2,a2;
        cin>>h1>>a1>>h2>>a2;
        if(a1>=h2) cout<<-1<<endl;
        else {
            int t=h2/a1;
            if(h2%a1) t++;
            t--;
            int res=h1/(t*a2);
            if(h1%(t*a2)==0) res--;
            cout<<res<<endl;
        }
    }
    return 0;
}