#include <cstdio>
#include <algorithm>
#include <cmath>
#define g 10.0
using namespace std;
int N,H,R;
double y[108];

double f(int T)
{
    if(T<0)
        return H;
    double t=sqrt(2.0*H/g);
    int n=(int)(T/t);
    double k=T-n*t,y;
    if(n%2==0)
        return H-k*k*g/2;
    else return H-(k-t)*(k-t)*g/2;
}


int main()
{
    int casecnt;
    scanf("%d",&casecnt);
    while(casecnt--)
    {
        int T;
        scanf("%d%d%d%d",&N,&H,&R,&T);
        for(int i=0;i<N;++i)
            y[i]=f(T-i);
        sort(y,y+N);
        for(int i=0;i<N;++i)
            if(i==N-1)
                printf("%.2lf\n",y[i]+2*R*i/100.0);
            else printf("%.2lf ",y[i]+2*R*i/100.0);
    }
    //system("pause");
    return 0;
}
