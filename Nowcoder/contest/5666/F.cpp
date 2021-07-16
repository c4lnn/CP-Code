#include<bits/stdc++.h>
using namespace std;
string a,b;
int main() {
    while(cin>>a>>b) {
        string c=a+b,d=b+a;
        if(c>d) puts(">");
        else if(c<d) puts("<");
        else puts("=");
    }
    return 0;
}