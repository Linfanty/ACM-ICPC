/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-27-21.10
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;

const int MAXN=100010;
char s[MAXN];
int Next[MAXN];
void getNext()
{
      Next[0]=0;
      int s_len=strlen(s);
      for(int i=1,k=0;i<s_len;++i)
      {
            while(s[i]!=s[k]&&k) k=Next[k-1];
            if(s[i]==s[k]) ++k;
            Next[i]=k;
      }
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%s",s);
            getNext();
            int s_len=strlen(s);
            int min_cycle=s_len-Next[s_len-1];
            if(min_cycle!=s_len && s_len%min_cycle==0)
            {
                  puts("0");
            }
            else
            {
                  int need_add=min_cycle-Next[s_len-1]%min_cycle;
                  printf("%d\n",need_add);
            }
      }
      return 0;
}
/*

*/
