#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
#define fromdownto(from,to,i) for(int i=(from);i>=(to);--i)
#define fromgoto(from,to,i) for(int i=(from),__size=(to);i<=__size;++i)
#define foreach(v,p,type) for(type::iterator p=v.begin();p!=v.end();++p)
#define INF INT_MAX
#define MAXN 30008
list<int> L[MAXN];
int L_size[MAXN];
int inL[MAXN];
int main()
{
    while(true) {
        int n,m;scanf("%d%d",&n,&m);
        if(n==0 && m==0) break;
        fromto(0,n,i){inL[i]=i;L[i].clear();L[i].push_back(i);L_size[i]=1;}
        while(m--) {
            int k;scanf("%d",&k);
            if(k==0) continue;
            int s;scanf("%d",&s);s=inL[s];
            fromto(2,k,j) {
                int stu;scanf("%d",&stu);stu=inL[stu];
                if(s==stu) continue;
                if(L_size[s]<L_size[stu]) {//s->stu
                    foreach(L[s],p,list<int>) inL[*p]=stu;
                    L[stu].splice(L[stu].end(),L[s]);
                    L_size[stu]+=L_size[s];L_size[s]=0;
                } else {//stu->s
                    foreach(L[stu],p,list<int>) inL[*p]=s;
                    L[s].splice(L[s].end(),L[stu]);
                    L_size[s]+=L_size[stu];L_size[stu]=0;
                }
            }
        }
        printf("%d\n",L_size[inL[0]]);
    }
    return 0;
}
