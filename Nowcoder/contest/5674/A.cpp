#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
stack<char> b;
char s[20005];
struct bign {
    int len;
    int num[1005];
    bign() {
        len=1;
        memset(num,0,sizeof num);
    }
    bool operator == (const bign &a) const {
        for(int i=1;i<=len;i++) if(num[i]!=a.num[i]) return false;
        return true;
    }
    bool operator > (const bign &a) const {
        if(len>a.len) return true;
        else if(len<a.len) return false;
        else {
            for(int i=len;i>=1;i--) {
                if(num[i]>a.num[i]) return true;
                else if(num[i]<a.num[i]) return false;
            }
        }
        return false;
    }
    bool operator < (const bign &a) const {
        if(len>a.len) return false;
        else if(len<a.len) return true;
        else {
            for(int i=len;i>=1;i--) {
                if(num[i]>a.num[i]) return false;
                else if(num[i]<a.num[i]) return true;
            }
        }
        return false;
    }
    bool operator >= (const bign &a) const {
        if(len>a.len) return true;
        else if(len<a.len) return false;
        else {
            for(int i=len;i>=1;i--) {
                if(num[i]>a.num[i]) return true;
                else if(num[i]<a.num[i]) return false;
            }
        }
        return true;
    }
    bool operator <= (const bign &a) const {
        if(len>a.len) return false;
        else if(len<a.len) return true;
        else {
            for(int i=len;i>=1;i--) {
                if(num[i]>a.num[i]) return false;
                else if(num[i]<a.num[i]) return true;
            }
        }
        return true;
    }
};
bign get(char *s) {
    bign res;
    res.len=strlen(s);
    for(int i=1;i<=res.len;i++) res.num[i]=s[res.len-i]-'0';
    return res;
}
bign get(int n) {
    bign res;
    while(n) {
        res.num[res.len++]=n%10;
        n/=10;
    }
    if(res.len>1) res.len--;
    return res;
}
void print(bign a) {
    for(int i=a.len;i;i--) printf("%d",a.num[i]);
    puts("");
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
bign operator - (bign a,bign b) {  //a>b
    bign res;
    res.len=max(a.len,b.len);
    for(int i=1;i<=res.len;i++) {
        if(a.num[i]<b.num[i]) {
            a.num[i+1]--;
            a.num[i]+=10;
        }
        res.num[i]=a.num[i]-b.num[i];
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign operator * (bign a,int b) {
    bign res;
    int x=0;
    for(int i=1;i<=a.len;i++) {
        x+=a.num[i]*b;
        res.num[res.len++]=x%10;
        x/=10;
    }
    while(x) {
        res.num[res.len++]=x%10;
        x/=10;
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign operator * (bign a,bign b) {
    bign res;
    res.len=a.len+b.len;
    for(int i=1;i<=a.len;i++) {
        int x=0;
        for(int j=1;j<=b.len;j++) {
            res.num[i+j-1]+=a.num[i]*b.num[j]+x;
            x=res.num[i+j-1]/10;
            res.num[i+j-1]%=10;
        }
        res.num[i+b.len]+=x;
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign operator / (bign a,int b) {
    bign res;
    res.len=a.len;
    for(int i=a.len,t=0;i>=1;i--) {
        t=t*10+a.num[i];
        if(t>=b) res.num[i]=t/b,t%=b;
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign operator / (bign a,bign b) {
    bign res,x;
    res.len=a.len;
    for(int i=a.len;i>=1;i--) {
        x=x*10;//bign * int
        x.num[1]=a.num[i];
        while(x>b||x==b) {
            x=x-b;//bign - bign
            res.num[i]++;
        }
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign operator % (bign a,bign b) {
    bign res;
    for(int i=a.len;i>=1;i--) {
        res=res*10;//bign * int
        res.num[1]=a.num[i];
        while(res>b||res==b) res=res-b;//bign - bign
    }
    while(res.len>1&&res.num[res.len]==0) res.len--;
    return res;
}
bign gcd(bign a,bign b) {
    bign c;
    return !(b==c)?gcd(b,a%b):a;
}
bign qpow(bign a,bign b) {
    bign ret=get(1);
    while(b>get(0)) {
        if(b.num[1]&1) ret=ret*a;
        a=a*a;
        b=b/2;
    }
    return ret;
}
stack<bign> a;
int main() {
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='2'||s[i]=='0') a.push(get(s[i]-'0'));
        else if(s[i]=='(') b.push('(');
        else if(s[i]=='+') b.push('+');
        else if(s[i]==')') {
            bign t=a.top();
            a.pop();
            if(b.size()&&b.top()=='+') t=t+a.top(),a.pop(),b.pop();
            t=qpow(a.top(),t);
            a.pop();
            b.pop();
            if(b.size()&&b.top()=='+') t=t+a.top(),a.pop(),b.pop();
            a.push(t);
        }
    }
    bign sum=get(0);
    while(a.size()) sum=sum+a.top(),a.pop();
    print(sum);
    return 0;
}