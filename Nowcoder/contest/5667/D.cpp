#include<bits/stdc++.h>
using namespace std;
char a[10],b[10];
int get(char c) {
    return c-'0';
}
int main() {
    scanf("%s%s",a,b);
    int ha=get(a[0])*10+get(a[1]),hb=get(b[0])*10+get(b[1]);
    int ma=get(a[3])*10+get(a[4]),mb=get(b[3])*10+get(b[4]);
    int sa=get(a[6])*10+get(a[7]),sb=get(b[6])*10+get(b[7]);
    printf("%d\n",abs(ha*3600+ma*60+sa-hb*3600-mb*60-sb));
    return 0;
}