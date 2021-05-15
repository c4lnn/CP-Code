#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int n;
int a[20];

int check() {
    int tot=0;
    for(int i=1;i<n;i++) if(a[i]+1!=a[i+1]) tot++;
    return tot;
}
int f(int tot) {
    return ceil((double)tot/3);
}
bool dfs(int depth,int max_depth) {
    int tot=check();
    if(!tot) return true;
    if(depth+f(tot)>max_depth) return false;
    int temp[20];
    memcpy(temp,a,sizeof a);
    for(int len=1;len<=n;len++) {
        for(int l=1;l+len-1<=n;l++) {
            int r=l+len-1;
            for(int k=r+1;k<=n;k++) {
                int x=l;
                for(int i=r+1;i<=k;i++) a[x++]=temp[i];
                for(int i=l;i<=r;i++) a[x++]=temp[i];
                if(dfs(depth+1,max_depth)) return true;
                memcpy(a,temp,sizeof temp);
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int f=0;
    	int b[20];
    	memcpy(b,a,sizeof a);
        for(int i=0;i<=4;i++) {
        	memcpy(a,b,sizeof b);
            if(dfs(0,i)) {
                cout<<i<<endl;
                f=1;
                break;
            }
        }
        if(!f) cout<<"5 or more\n";
    }    
    return 0;
}