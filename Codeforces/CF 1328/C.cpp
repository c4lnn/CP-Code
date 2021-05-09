#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
//head
const int N=50010;
char s[N];
int a[N],b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        cin>>s+1;
        bool f=false;
        for(int i=1;i<=n;i++) {
            if(s[i]=='2') {
                if(!f) a[i]=b[i]=1;
                else a[i]=0,b[i]=2;
            }
            else if(s[i]=='1') {
                if(!f) f=true,a[i]=1,b[i]=0;
                else a[i]=0,b[i]=1;
            }
            else a[i]=b[i]=0;
        }
        for(int i=1;i<=n;i++) cout<<a[i];
        cout<<endl;
        for(int i=1;i<=n;i++) cout<<b[i];
        cout<<endl;
    }
    return 0;
}