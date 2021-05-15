#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a[51]={0,1,2};
    for(int i=3;i<51;i++)
            a[i]=a[i-1]+a[i-2];
    int n;
    while(cin>>n)    
        cout<<a[n]<<endl;
    return 0;
} 