#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
#define fromdownto(from,to,i) for(int i=(from);i>=(to);--i)
#define fromgoto(from,to,i) for(int i=(from),__size=(to);i<=__size;++i)
#define foreach(v,p,type) for(type::iterator p=(v).begin();p!=(v).end();++p)
#define MP make_pair
#define INF INT_MAX
#define MAXN 2008

struct uset {
    int fa[MAXN];
    bool same[MAXN];
    uset(){for(int i=0;i<MAXN;++i){fa[i]=i;same[i]=true;}}
    inline bool g(bool x,bool y){return x==y;}
    int root(int v) {
        if(fa[v]!=v) {
            int t=root(fa[v]);
            same[v]=g(same[v],same[fa[v]]);
            fa[v]=t;
        }
        return fa[v];
    }
    bool merge(int x,int y,int k) {
        int u=root(x),v=root(y);
        if(u==v) return g(same[x],same[y])==k;
        fa[v]=u;same[v]=g(g(same[x],k),same[y]);
        return true;
    }
};

int main()
{
    int case_cnt;scanf("%d",&case_cnt);
    fromto(1,case_cnt,case_num) {
        uset S;
        int n,m;scanf("%d%d",&n,&m);
        bool ok=true;
        while(m--) {
            int x,y;scanf("%d%d",&x,&y);
            if(!S.merge(x,y,false)) ok=false;
        }
        printf(ok?"Scenario #%d:\nNo suspicious bugs found!\n\n":
            "Scenario #%d:\nSuspicious bugs found!\n\n",case_num);
    }
    return 0;
}
