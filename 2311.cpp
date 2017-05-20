#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

int mem[201][201];

int SG(int W,int H)
{
    int &ans=mem[W][H];
    if(ans!=-1) return ans;
    set<int> S;
    for(int i=2;W-i>=2;++i) S.insert(SG(i,H)^SG(W-i,H));
    for(int i=2;H-i>=2;++i) S.insert(SG(W,i)^SG(W,H-i));
    int k=0;
    while(S.find(k)!=S.end()) ++k;
    return ans=k;
}

int main()
{
    memset(mem,-1,sizeof(mem));
    int W,H;
    while(scanf("%d%d",&W,&H)==2)
        printf(SG(W,H)?"WIN\n":"LOSE\n");
    return 0;
}
