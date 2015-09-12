/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-12-15.41
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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

/** O(n)内求出所有回文串
 *原串 :abaaba
 *Ma串 :.,a,b,a,a,b,a,
 *Mp[i]:Ma串中，以字符Ma[i]为中心的最长回文子串的半径长度(包括Ma[i],也就是把回文串对折后的长度).
 ****经过对原串扩展处理后，将奇数串的情况也合并到了偶数的情况(不需要考虑奇数串)
 */
const int MAXN=1050;
char Ma[MAXN*2],s[MAXN];
int Mp[MAXN*2],Mplen;
void Manacher(char s[],int len)
{
      int le=0;
      Ma[le++]='.';
      Ma[le++]=',';
      for(int i=0;i<len;++i)
      {
            Ma[le++]=s[i];
            Ma[le++]=',';
      }
      Mplen=le;
      Ma[le]=0;
      int pnow=0,pid=0;
      for(int i=1;i<le;++i)
      {
            if(pnow>i)
                  Mp[i]=min(Mp[2*pid-i],pnow-i);
            else
                  Mp[i]=1;
            for(;Ma[i-Mp[i]]==Ma[i+Mp[i]];++Mp[i]);
            if(i+Mp[i]>pnow)
            {
                  pnow=i+Mp[i];
                  pid=i;
            }
      }
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%s",s))
      {
            Manacher(s,strlen(s));
            int maxLen=1,idx=0;
            for(int i=0;i<Mplen;++i)
            {
                  if(Mp[i]>maxLen)
                        maxLen=Mp[i],idx=i;
            }
            for(int i=(idx-maxLen+1)/2,j=0;j<maxLen-1;++i,++j)
                  printf("%c",s[i]);
            puts("");
//            cout<<maxLen-1<<endl;
      }
      return 0;
}
