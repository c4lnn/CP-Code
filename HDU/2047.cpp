#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a[40]={0,3,8};
    for(int i=3;i<40;i++)
        a[i]=a[i-2]*2+a[i-1]*2;
    int n;
    while(cin>>n)
        cout<<a[n]<<endl;
    return 0;
}