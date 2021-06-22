#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const int N=100010;
int m;
pii a[N];
int b[N];
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        cin>>m;
        for(int i=1;i<=m;i++) cin>>a[i].fi,a[i].se=i;
        sort(a+1,a+1+m);
        int res=0;
        for(int i=m;i;i--) {
            res+=1<<a[i].fi;
            if(res==1<<30) {
                for(int i=1;i<=m;i++) b[i]=0;
                for(int j=m;j>=i;j--) b[a[j].se]=1;
                break;
            }
        }
        if(res==1<<30) {
            for(int i=1;i<=m;i++) cout<<b[i];
            cout<<endl;
        }
        else cout<<"impossible"<<endl;
    }
    return 0;
}