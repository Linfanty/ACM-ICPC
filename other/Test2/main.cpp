#include<iostream>
#include<cstdio>
#include<climits>
typedef long long LL;
using namespace std;

const int MAXN=50010;
LL a[MAXN];

LL fen(int l,int r)
{
      if(l==r) return max(a[l],0LL);
      else
      {
            int mid=(l+r)/2;
            LL fl=fen(l,mid);
            LL fr=fen(mid+1,r);
            LL ll=INT_MIN,rr=INT_MIN;
            LL s=0;
            for(int i=mid;i>=l;--i)
            {
                  s+=a[i];
                  ll=max(ll,s);
            }
            s=0;
            for(int i=mid+1;i<=r;++i)
            {
                  s+=a[i];
                  rr=max(rr,s);
            }
            return max(max(fl,fr),ll+rr);
      }
}
int main()
{
      int n;
      while(~scanf("%d",&n))
      {
            for(int i=0;i<n;++i) scanf("%I64d",&a[i]);
            printf("%I64d\n",fen(0,n-1));
      }
      return 0;
}
