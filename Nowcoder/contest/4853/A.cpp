#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

int a[100010];
ll cnt[50];
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll res=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        for(int j=0;j<30;j++)
            if(a[i]&(1<<j))
                cnt[j]++;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<30;j++)
            if(a[i]&(1<<j))
                res+=cnt[j]*(1<<j);
    cout<<res<<endl;
    return 0;
}