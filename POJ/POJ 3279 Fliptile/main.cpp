/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-15-20.59
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

int n,m;

vector<pair<int,string> >ans;
bool Mp[20][20],tMp[20][20];
int flip[20][20];
char tmps[400];
int dx[]={0,1,0,-1, 0};
int dy[]={0,0,1, 0,-1};
bool get(int x,int y)
{
      int cnt=0;
      for(int i=0;i<5;++i)
      {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if((xx>=0 && xx<n)&&(yy>=0 && yy<m)) cnt+=(tMp[xx][yy]?1:0);
      }
      return cnt&1;
}
void work(int x)
{
      memset(flip,0,sizeof flip);
      int cnt=0,num=0;
      for(int i=0; i<m; ++i)
            flip[0][i]=(x>>i)&1;
      for(int i=1; i<n; ++i)
      {
            for(int j=0; j<m; ++j)
            {
                  if(get(i-1,j)) flip[i][j]=1;
            }
      }
      for(int i=0;i<m;++i)
      {
            if(get(n-1,i)) return ;
      }
      for(int i=0;i<n;++i)
      {
            for(int j=0;j<m;++j)
            {
                  if(flip[i][j])
                  {
                        num++;
                        tmps[cnt++]='1';
                  }
                  else tmps[cnt++]='0';
            }
      }
      ans.push_back(make_pair(num,string(tmps)));
}


int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
//      freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tmp;
      while(cin>>n>>m)
      {
            for(int i=0; i<n; ++i)
            {
                  for(int j=0; j<m; ++j)
                  {
                        cin>>tmp;
                        Mp[i][j]=(tmp==1?true:false);
                  }
            }
            ans.clear();
            int cnt=1<<m;
            for(int i=0; i<cnt; ++i)
            {
                  work(i);
            }
            if(ans.size()<=0)
            {
                  cout<<"IMPOSSIBLE"<<endl;
                  continue;
            }
            sort(ans.begin(),ans.end());
            for(auto ptr:ans)
            {
                  cout<<ptr.first<<" "<<ptr.second<<endl;
            }
            vector<pair<int,string> > ::iterator pt=ans.begin();
            string str(pt->second);
            int ct=0;
            for(int i=0;i<n;++i)
            {
                  for(int j=0;j<m;++j)
                  {
                        if(j==m-1)
                        {
                              cout<<str[ct++]<<endl;
                        }
                        else cout<<str[ct++]<<" ";
                  }
            }
      }
      return 0;
}
/*

*/
