#include <cstdio>
#include <cstring>
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
        Node res={x+ano.x,y+ano.y};
        return res;
    }
    Node rotate(double a)
    {
        Node res={cos(a)*x+sin(a)*y,-sin(a)*x+cos(a)*y};
        return res;
        //return (Node){cos(a)*x-sin(a)*y,sin(a)*x+cos(a)*y};
    }
} vec[40008];
double add[40008],prv[10008];

void init(int o,int L,int r)
{
    add[o]=0;
    if(L+1==r)
    {
        vec[o].x=0;
        vec[o].y=a[L];
    }
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
