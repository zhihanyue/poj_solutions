#include <cstdio>
#include <set>
using namespace std;

struct Node { int K,P; };
struct cmp
{
    bool operator()(Node a,Node b)
    {
        return a.P<b.P;
    }
};
multiset<Node,cmp> myset;

int main()
{
    while(true)
    {
        int N;
        scanf("%d",&N);
        if(N==0)
            break;
        else if(N==1)
        {
            int K,P;
            scanf("%d%d",&K,&P);
            myset.insert((Node){K,P});
        }
        else if(N==2)
        {
            if(myset.size()!=0)
            {
                set<Node>::iterator it=myset.end();
                --it;
                printf("%d\n",it->K);
                myset.erase(it);
            }
            else printf("0\n");
        }
        else if(N==3)
        {
            if(myset.size()!=0)
            {
                set<Node>::iterator it=myset.begin();
                printf("%d\n",it->K);
                myset.erase(it);
            }
            else printf("0\n");
        }
    }
    return 0;
}
