#include<bits/stdc++.h>

using namespace std;

const string p="XiaoQiao",q="XiaoHuiHui";

int main() {
    string s;
    cin>>s;
    int x=0,y=0;
    for(int i=0;i<s.length();i++) {
        if(x<=7&&s[i]==p[x]) x++;
        if(y<=9&&s[i]==q[y]) y++;
    }
    if(x==8&&y==10) cout<<"Happy"<<endl;
    else cout<<"emm"<<endl;
    return 0;
}