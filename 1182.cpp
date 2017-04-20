#include <stdio.h>

int p[150008],N;
int find(int x)
{
    return p[x]==x?x:(p[x]=find(p[x]));
}

int main()
{
    int K,ans=0,i;
    scanf("%d%d",&N,&K);
    for(i=0;i<=3*N;++i)
        p[i]=i;
    for(i=1;i<=K;++i)
    {
        int D,x,y;
        scanf("%d%d%d",&D,&x,&y);
        if(x>N || y>N)
            ++ans;
        else if(D==1)
        {
            if(find(x)==find(y+N) || find(x)==find(y+2*N))
                ++ans;
            else
            {
                p[find(x)]=find(y);
                p[find(x+N)]=find(y+N);
                p[find(x+2*N)]=find(y+2*N);
            }
        }
        else if(x==y)
            ++ans;
        else
        {
            if(find(x)==find(y) || find(x)==find(y+2*N))
                ++ans;
            else
            {
                p[find(x)]=find(y+N);
                p[find(x+N)]=find(y+2*N);
                p[find(x+2*N)]=find(y);
            }
        }
    }
    printf("%d\n",ans);
//  system("pause");
    return 0;
}
