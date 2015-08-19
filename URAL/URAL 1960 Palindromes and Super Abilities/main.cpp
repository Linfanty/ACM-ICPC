/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-18-16.52
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

int a[500][500];

int main()
{
      int n, m;
      while(cin >> n >> m)
      {
            int sum = 0;
            for(int i = 1; i <= n; ++i)
                  for(int j = 1; j <= m; ++j)
                  {
                        scanf("%d", &a[i][j]);
                        sum += a[i][j];
                  }
            if((n & 1) || (m & 1))
            {
                  printf("%d\n", sum);
                  if(n & 1)
                  {
                        for(int i = 1; i <= n; ++i)
                        {
                              for(int j = 1; j < m; ++j)
                              {
                                    if(i & 1)
                                          putchar('R');
                                    else
                                          putchar('L');
                              }
                              if(i < n)
                                    putchar('D');
                        }
                  }
                  else
                  {
                        for(int i = 1; i <= m; ++i)
                        {
                              for(int j = 1; j < n; ++j)
                              {
                                    if(i & 1)
                                          putchar('D');
                                    else
                                          putchar('U');
                              }
                              if(i < m)
                                    putchar('R');
                        }
                  }
                  puts("");
                  continue;
            }
            int x, y;
            int mn = 1e5;
            for(int i = 1; i <= n; ++i)
            {
                  for(int j = 1; j <= m; ++j)
                  {
                        if((i + j) % 2 == 0)
                              continue;
                        if(a[i][j] < mn)
                        {
                              mn = a[i][j];
                              x = i;
                              y = j;
                        }
                  }
            }
            cout << sum - mn << endl;
            if(y & 1)
            {
                  for(int i = 1; i < x - 1; ++i)
                  {
                        for(int j = 1; j < m; ++j)
                        {
                              if(i & 1)
                                    putchar('R');
                              else
                                    putchar('L');
                        }
                        putchar('D');
                  }
                  int p = 1;
                  for(int i = 1; i <= m; ++i)
                  {
                        if(i == y)
                        {
                              putchar('R');
                              p = 0;
                              continue;
                        }
                        if((i + p) & 1)
                              putchar('U');
                        else
                              putchar('D');
                        if(i < m)
                              putchar('R');
                  }
                  if(x < n)
                        putchar('D');
                  for(int i = x + 1; i <= n; ++i)
                  {
                        for(int j = 1; j < m; ++j)
                        {
                              if(i & 1)
                                    putchar('L');
                              else
                                    putchar('R');
                        }
                        if(i < n)
                              putchar('D');
                  }
            }
            else if(x & 1)
            {
                  for(int i = 1; i < y - 1; ++i)
                  {
                        for(int j = 1; j < n; ++j)
                        {
                              if(i & 1)
                                    putchar('D');
                              else
                                    putchar('U');
                        }
                        putchar('R');
                  }
                  int p = 1;
                  for(int i = 1; i <= n; ++i)
                  {
                        if(i == x)
                        {
                              putchar('D');
                              p = 0;
                              continue;
                        }
                        if((i + p) & 1)
                              putchar('L');
                        else
                              putchar('R');
                        if(i < n)
                              putchar('D');
                  }
                  if(y < m)
                        putchar('R');
                  for(int i = y + 1; i <= m; ++i)
                  {
                        for(int j = 1; j < n; ++j)
                        {
                              if(i & 1)
                                    putchar('U');
                              else
                                    putchar('D');
                        }
                        if(i < m)
                              putchar('R');
                  }
            }
            puts("");
      }
      return 0;
}
