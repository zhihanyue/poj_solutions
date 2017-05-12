#include <cstdio>
#include <cmath>
#include <algorithm>
#define PI 3.1415926535
using namespace std;

int a[10008];
struct Node
{
    double x,y;
    Node operator+(Node ano)const
    {
        return (Node){x+ano.x,y+ano.y};
    }
    Node rotate(double a)
    {
        return (Node){cos(a)*x+sin(a)*y,-sin(a)*x+cos(a)*y};
        //return (Node){cos(a)*x-sin(a)*y,sin(a)*x+cos(a)*y};
    }
} vec[20008];
double add[20008],prv[10008];

void init(int o,int L,int r)
{
    if(L+1==r)
        vec[o]=(Node){0,a[L]};
    else
    {
        int M=L+(r-L)/2;
        init(o*2,L,M);
        init(o*2+1,M,r);
        vec[o]=vec[o*2]+vec[o*2+1];
    }
}

int up_L,up_r;
double delta;
void update(int o,int L,int r)
{
    if(r<=up_L || L>=up_r)
        return;
    else if(up_L<=L && r<=up_r)
        add[o]+=delta;
    else if(L+1==r)
        return;
    else
    {
        int M=L+(r-L)/2;
        update(o*2,L,M);
        update(o*2+1,M,r);
        //printf("(%.2lf %.2lf) %.2lf (%.2lf %.2lf)\n",vec[o*2+1].x,vec[o*2+1].y,add[o*2+1],vec[o*2+1].rotate(add[o*2+1]).x,vec[o*2+1].rotate(add[o*2+1]).y);
        vec[o]=vec[o*2].rotate(add[o*2])+vec[o*2+1].rotate(add[o*2+1]);
    }
        //printf("vec:%d[%d,%d) %lf %lf\n",o,L,r,vec[o].x,vec[o].y);
}

int main()
{
    int n,c;
    while(scanf("%d%d",&n,&c))
    {
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        memset(add,0,sizeof(add));
        fill(prv+1,prv+n,PI);
        init(1,1,n+1);
        for(int i=1;i<=c;++i)
        {
            int which,tmp;
            scanf("%d%d",&which,&tmp);
            double angle=tmp/180.0*PI;
            delta=prv[which]-angle;
            up_L=which+1;
            up_r=n+1;
            update(1,1,n+1);
            prv[which]=angle;
            printf("%.2lf %.2lf\n",vec[1].x,vec[1].y);
        }
        printf("\n");
    }
    return 0;
}
