#include <cstdio>
#include <vector>
#include <cstring>
#include <cfloat>
#include <algorithm>
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
using namespace std;
int a,b,n,m,t[10];
vector< pair<int,int> > G[38];
double dp[38][1<<8+1];

double memdp(int v,int S)
{
    double &ans=dp[v][S];
    if(ans!=-1)
        return ans;
    if(v==a)
        return 0;
    ans=DBL_MAX/2;
    for(int u=0,size=G[v].size();u<size;++u) fromto(1,n,i)
        if(((S>>(i-1))&1)==0)
            ans=min(ans,memdp(G[v][u].first,S|(1<<(i-1)))+(double)G[v][u].second/t[i]);
    return ans;
}

int main()
{
    while(true)
    {
        fromto(0,37,i) G[i].clear();
        int p;
        scanf("%d%d%d%d%d",&n,&m,&p,&a,&b);
        if(n==0 && m==0 && p==0 && a==0 && b==0)
            break;
        fromto(1,n,i) scanf("%d",&t[i]);
        fromto(1,p,i) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            G[x].push_back(make_pair(y,z));
            G[y].push_back(make_pair(x,z));
        }
        fromto(0,37,i) fromto(0,1<<8,j)
            dp[i][j]=-1;
        double ans=memdp(b,0);
        if(ans==DBL_MAX/2)
            printf("Impossible\n");
        else printf("%lf\n",ans);
    }
    return 0;
}
