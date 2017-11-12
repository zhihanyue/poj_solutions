#include <cstdio>
#include <algorithm>
#include <cmath>
#define g 10.0
using namespace std;
int N,R;
double H;
double y[108];

double f(int T)
{
    if(T<=0)
        return H;
    double t=sqrt(2.0*H/g);
    int n=(int)(T/t);
    double k=T-n*t,y;
    if(n%2==0)
        return H-k*k*g/2;
    else return g*t*k-k*k*g/2;
}

int main()
{
    int casecnt;
    scanf("%d",&casecnt);
    while(casecnt--)
    {
        int T;
        scanf("%d%lf%d%d",&N,&H,&R,&T);
        for(int i=0;i<N;++i)
        {
            y[i]=f(T-i);
            H+=2*R/100.0;
        }
        sort(y,y+N);
        for(int i=0;i<N;++i)
            if(i==N-1)
                printf("%.2lf\n",y[i]);
            else printf("%.2lf ",y[i]);
    }
    //system("pause");
    return 0;
}
