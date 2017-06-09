#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define lowbit(i) ((i)&(-(i)))
using namespace std;

template <typename T,int maxn,int maxm>
struct BIT
{
    T bit[maxn][maxm],lenn,lenm;
    void init(int _lenn,int _lenm)
    {
        memset(bit,0,sizeof(bit));
        lenn=_lenn;
        lenm=_lenm;
    }
    T sum(int x,int y)
    {
        T result=0;
        for(int i=x;i>0;i-=lowbit(i))
            for(int j=y;j>0;j-=lowbit(j))
                result+=bit[i][j];
        return result;
    }
    void add(int x,int y,int v)
    {
        for(int i=x;i<=lenn;i+=lowbit(i))
            for(int j=y;j<=lenm;j+=lowbit(j))
                bit[i][j]+=v;
    }
};
BIT<int,1008,1008> BIT1;

int main()
{
    int casecnt;
    scanf("%d",&casecnt);
    while(casecnt--)
    {
        int N,T;
        scanf("%d%d",&N,&T);
        BIT1.init(N,N);
        while(T--)
        {
            char cmdch;
            scanf(" %c",&cmdch);
            if(cmdch=='C')
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                BIT1.add(x1,y1,1);
                BIT1.add(x2+1,y2+1,1);
                BIT1.add(x1,y2+1,-1);
                BIT1.add(x2+1,y1,-1);
            }
            else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",BIT1.sum(x,y)%2);
            }
        }
    }
    return 0;
}
