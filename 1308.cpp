#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
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
#define MAXN 200

int fa[MAXN];
int getroot(int v){return fa[v]==v?v:(fa[v]=getroot(fa[v]));}
void sinit(){for(int i=0;i<MAXN;++i) fa[i]=i;}

int main() {
    for(int case_num=1;;++case_num) {
        unsigned int cnt=0;
        set<int> S,S_t;
        bool OK=true;
        while(true) {
            int a,b; scanf("%d%d",&a,&b);
            if(a==-1 && b==-1) return 0;
            if(a==0 && b==0) break;
            ++cnt;
            S.insert(a);S.insert(b);
            if(S_t.find(b)==S_t.end()) S_t.insert(b);
            else OK=false;
        }
        if((S.size()==cnt+1 && OK) || cnt==0) printf("Case %d is a tree.\n",case_num);
        else printf("Case %d is not a tree.\n",case_num);
    }
    return 0;
}
