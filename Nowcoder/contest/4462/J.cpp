#include<bits/stdc++.h>
using namespace std;
const int N=10005;
struct bign {
    int len=1;
    int num[N]={0};
};
bign get(string s) {
    bign res;
    res.len=s.length();
    for(int i=1;i<=res.len;i++) res.num[i]=s[res.len-i]-'0';
    return res;
}
bign operator + (bign a,bign b) {
    bign res;
    res.len=max(a.len,b.len);
    int x=0;
    for(int i=1;i<=res.len;i++) {
        res.num[i]+=x+a.num[i]+b.num[i];
        x=res.num[i]/10;
        res.num[i]%=10;
    }
    if(x) res.num[++res.len]=x;
    return res;
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        string s;
        cin>>s;
        string a="",b="";
        int f=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='+'){f++;continue;}
            if(!f) a+=s[i];
            else b+=s[i];
        }
        if(a==""|b==""||f>1) cout<<"skipped"<<endl;
        else {
            bign c=get(a)+get(b);
            for(int i=c.len;i;i--) cout<<c.num[i];
            cout<<endl;
        }
    }
    return 0;
}