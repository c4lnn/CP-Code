#include<bits/stdc++.h>
using namespace std;
char s[1005];
char p[1005];
int n[1005];
void kmp()
{
    n[0]=-1;
    int k=-1;
    int j=0;
    while(j<strlen(p))
    {
        if(k==-1||p[j]==p[k])
        {
            j++;
            k++;            
            n[j]=p[j]!=p[k]?k:n[k];
        }
        else
            k=n[k];
    }
}
void kmpsearch()
{
    kmp();
    int i=0;
    int j=0;
    int ans=0;
    while(i<strlen(s))
    {
        if(j==-1||s[i]==p[j])
        {        
            i++;
            j++;
        }
        else
            j=n[j];
        if(j==strlen(p))
        {
            ans++;
            j=0;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    while(cin>>s&&strcmp(s,"#\0"))
    {
        cin>>p;
        memset(n,0,sizeof(n));
        kmpsearch();
    }
    return 0;
}