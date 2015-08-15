/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-15-12.09
* Time: 0MS
* Memory: 137KB
*/
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define  LL __int64
#define  ULL unsigned long long
using namespace std;
const LL MAXN=200010;
struct node
{
      LL val,fla;
      bool operator <(const node&a) const{
            return val>a.val;
      }
} a[MAXN];
LL dp[MAXN][10];

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL Cas;
      scanf("%d",&Cas);
      while(Cas--)
      {
            LL n,k;
            scanf("%I64d %I64d",&n,&k);
            for(LL i=1;i<=n;++i)
            {
                  scanf("%I64d %I64d",&a[i].val,&a[i].fla);
            }
            sort(a+1,a+n+1);
            LL ans=0;
            memset(dp,0,sizeof dp);
            for(LL i=1;i<=n;++i)
            {
                  dp[i][0]=dp[i-1][0]>a[i].val-a[i].fla?dp[i-1][0]:a[i].val-a[i].fla;
                  for(LL j=1;j<=k;++j)
                  {
                        dp[i][j]=max(dp[i-1][j],min(dp[i-1][j-1]-a[i].fla,a[i].val-a[i].fla));
                  }
                  ans=ans>dp[i][k]?ans:dp[i][k];
            }
            printf("%I64d\n",ans);
      }
      return 0;
}
/*

*/
