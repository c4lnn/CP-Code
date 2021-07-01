#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N],p[N];
int n,nxt[N][30];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s+1;
    int len=strlen(s+1);
    for(int i=len;i>=1;i--) {
    	for(int j=0;j<26;j++) nxt[i-1][j]=nxt[i][j];
    	nxt[i-1][s[i]-'a']=i;
    }
    cin>>n;
    for(int i=1;i<=n;i++) {
    	cin>>p;
    	int l=strlen(p);
    	int x=0;
    	int f=0;
        for(int i=0;i<l;i++) {
            if(nxt[x][p[i]-'a']) x=nxt[x][p[i]-'a'];
            else {
                f=1;
                break;
            }
    	}
    	if(f) cout<<"No"<<endl;
    	else cout<<"Yes"<<endl;
    }
    return 0;
}