#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
struct lamp{
    int v,k,c,l;
}a[maxn];
int n,v1,k1,c1,l1;
int s[maxn];
int d[maxn];
bool cmp(lamp a1,lamp a2){
    return a1.v<a2.v;
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        memset(s,0,sizeof(s));
        memset(d,0,sizeof(d));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&v1,&k1,&c1,&l1);
            a[i].v=v1;
            a[i].k=k1;
            a[i].c=c1;
            a[i].l=l1;
        }
        sort(a+1,a+n+1,cmp);
        s[0]=0;
        for(int i=1;i<=n;i++)
        {
            s[i]=s[i-1]+a[i].l;
        }
        d[0]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<i;j++)
        {
            if(j==-0) d[i]=(s[i])*a[i].c+a[i].k;
            else d[i]=min(d[j]+(s[i]-s[j])*a[i].c+a[i].k,d[i]);
        }
        printf("%d\n",d[n]);
    }
    return 0;
}