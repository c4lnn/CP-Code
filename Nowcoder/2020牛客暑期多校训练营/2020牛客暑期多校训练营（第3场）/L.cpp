#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    string t1="lovely",t2="LOVELY";
        int f=0;
        for(int i=0;i<6;i++) {
            if(s[i]!=t1[i]&&s[i]!=t2[i]) {
                f=1;
                break;
            }
        }
        if(f) puts("ugly");
        else puts("lovely");
    return 0;
}