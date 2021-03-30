#include<bits/stdc++.h>
using namespace std;
char p[200001];
int  v[200001];
int n;
void kmp()
{
    v[0]=-1;
    int i=0;
    int j=-1;
    while(i<n)
    {
        if(j==-1||p[i]==p[j])
        {
            i++;
            j++;
            v[i]=j;
        }
        else
            j=v[j];
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=n;
        scanf("%s",p);
        kmp();
        for(int i=1;i<=n;i++)
            if(v[i])
                ans++;
        printf("%d\n",ans%10007);
    }
    return 0;
}