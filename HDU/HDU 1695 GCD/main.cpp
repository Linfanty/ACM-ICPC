/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-08-21.45
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

const int NN=101000;
bool v[NN];
int p[NN];
void makePrime()
{
      int num=-1,i,j;
      for(i=2; i<NN; ++i)
      {
            if(!v[i]) { p[++num]=i; }
            for(j=0; j<=num && i*p[j]<NN; ++j)
            {
                  v[i*p[j]]=true;
                  if(i%p[j]==0) { break; }
            }
      }
      cout<<num<<endl;
}


vector<int> pf[NN];
vector<pair<int,int> > pa[NN];

void pre()
{
      int i,j,a;
      for(i=1; i<=100000; ++i)
      {
            a=i;
            for(j=0; j<=9672; ++j)
            {
                  if(!(a%p[j]))
                  {
                        pf[i].push_back(p[j]);
                        while(!(a%p[j]))
                              a/=p[j];
                  }
                  if(!a) break;
            }
      }
      int si;
      pa[1].push_back(make_pair(1,0));
      for(int i=2; i<=100000; ++i)
      {
            for(auto p:pf[i])
            {
                  pa[i].push_back(make_pair(p,0));
                  si=pa[i].size();
                  for(int j=0; j<si-1; ++j)
                        pa[i].push_back(make_pair(pa[i][si-1].first*pa[i][j].first,pa[i][j].second+1));
            }
      }
      puts("-----------------------------------------------------------------");
      for(int i=1; i<=3; ++i)
      {
            cout<<"i="<<i<<endl;
            for(auto p:pa[i])
            {
                  cout<<p.first<<" "<<p.second<<endl;
            }
      }
      puts("-----------------------------------------------------------------");
}


int main()
{
      makePrime();
      pre();
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      for(int Cas=1; Cas<=t; ++Cas)
      {
            int a,b,c,d,k,si;
            scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
            a=b/k;
            b=d/k;
            if(a>b) swap(a,b);
            LL ans=b;
            for(int i=2; i<=a; ++i)
            {
                  si=pa[i].size();
                  for(int j=0; j<si; ++j)
                  {
                        if(!(pa[i][j].second&1))
                              ans+=((b-i+1)-b/pa[i][j].first);
                        else
                              ans-=((b-i+1)-b/pa[i][j].first);
                  }
            }
            printf("%lld\n",ans);
      }
      return 0;
}
/*

*/
