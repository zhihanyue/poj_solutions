#include <cstdio>
#include <set>
using namespace std;

int SG(int W,int H)
{
    set<int> S;
    for(int i=2;W-i>=2;++i) S.insert(SG(i,H)^SG(W-i,H));
    for(int i=2;H-i>=2;++i) S.insert(SG(W,i)^SG(W,H-i));
    int k=0;
    while(S.find(k)!=S.end()) ++k;
    return k;
}

int main()
{
    int W,H;
    while(scanf("%d%d",&W,&H)==2)
        printf(SG(W,H)?"WIN\n":"LOSE\n");
    return 0;
}
