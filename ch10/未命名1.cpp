#include <bits/stdc++.h>
const int maxn=100005;
int p[maxn];
int prim[maxn];
int len=0;
void prime(int m)
{
	memset(p,0,sizeof(p));
	int k=sqrt(m+0.5);
	p[1]=1; 
	for(int i=2;i<=k;i++)
	{
		if(!p[i])
	    for(int j=i*i;j<=m;j+=i)
	       p[j]=1;
    }
    len=0;
    for(int i=1;i<=m;i++)   //将质数p[i]->prim[i] 
    {
    	if(!p[i])  //质数
		   prim[len++]=i;  //保存这些质数 
	}
}
bool is_ping(int k)//是否是平凡因子 
{
	for(int i=0;i<len;i++)
	   if(k%(prim[i]*prim[i])==0)  //是平方因子
	       return false;
    printf("%d ",k);
    return true; 
}
int main()
{
	int n,m,cnt=0;
	scanf("%d%d",&n,&m);
	prime(m);
	for(int i=n;i<=m;i++)
	   if(is_ping(i))
	      cnt++;
    printf("\n%d\n",cnt);
	return 0;
 }
