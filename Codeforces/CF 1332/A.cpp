#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int x,y,x1,y1,x2,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        int f=0;
        if(a-b>x-x1) f=1;
        if(b-a>x2-x) f=1;
        if(c-d>y-y1) f=1;
        if(d-c>y2-y) f=1;
        if(x==x1&&x==x2&&(a||b)) f=1;
        if(y==y1&&y==y2&&(c||d)) f=1;
        if(f) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}