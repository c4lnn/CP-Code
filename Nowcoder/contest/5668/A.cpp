#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
char s[N];
int n;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int res=0,cnt=0,t=0;
        scanf("%d%s",&n,s+1);
        for(int i=1;i<=n;i++) {
            if(s[i]=='1') {
                if(cnt) res++,cnt--,t++;
                else cnt++;
            }
            else if(s[i]=='0') {
                if(cnt) cnt--,res++;
                else if(t) t--,cnt++;
            }
            else if(s[i]=='2') res++;
            else if(s[i]=='3') res++;
        }
        printf("%d\n",res);
    }
    return 0;
}