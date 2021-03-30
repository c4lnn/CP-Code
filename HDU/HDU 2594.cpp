#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
const int N=50001;
char s1[2*N];
char s2[N];
int n[2*N];
int len1,len2;
void kmp()
{
    int i=0;
    int j=-1;
    n[0]=-1;
    int len=strlen(s1);
    while(i<len)
    {
        if(j==-1||s1[i]==s1[j])
            n[++i]=++j;
        else
            j=n[j];
    }
    if(j==0)
        printf("0\n");
    else
    {
        if(j>min(len1,len2))
            j=min(len1,len2);
        s1[j]=0;
        printf("%s %d\n",s1,j); 
    }
} 
int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        len1=strlen(s1);
        len2=strlen(s2);
        strcat(s1,s2);
        kmp();        
    }
    return 0;
} 