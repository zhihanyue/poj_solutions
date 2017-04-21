#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define EPS 1e-6
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
#define MAXN 208
#define MAXM 208
#define CAP(i) (i)
#define FEQ(i) (m+(i)-1)
#define FEQ2(i) (m+n-2+(i)-1)
double A[MAXM+2*MAXN-4][MAXM];
int main()
{
    srand((int)"orz WJMZBMR!!RP++");
    int n,m;
    while(scanf("%d%d",&m,&n)==2) {
        memset(A,0,sizeof(A));
        fromto(1,m,i) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            //目标函数 
            if(u==1) A[0][i]=1;
            //容量限制 
            A[CAP(i)][0]=w;A[CAP(i)][i]=-1;
            //流量守恒 
            if(u!=1){A[FEQ(u)][i]=-1;A[FEQ2(u)][i]=1;}
            if(v!=n){A[FEQ(v)][i]=1;A[FEQ2(v)][i]=-1;}
        }
        int lline=m+2*n-4;
        bool isOK=false;
        while(true) {
            int mrow_i=1;
            fromto(1,m,i) if(A[0][mrow_i]<A[0][i]){mrow_i=i;}
            if(A[0][mrow_i]<EPS){isOK=true;break;}
            double mline=1e30,temp;int mline_i;
            fromto(1,lline,i)//A[i][mrow_i]<-EPS!!!!!!!!!!!!!!!!!!
                if(A[i][mrow_i]<-EPS && (mline>(temp=A[i][0]/-A[i][mrow_i]) || (mline==temp && rand()%2==0))) {
                    mline=temp;
                    mline_i=i;
                }
            if(mline==1e30){isOK=false;break;}
            double k=-A[mline_i][mrow_i];
            A[mline_i][mrow_i]=-1;
            fromto(0,m,i) A[mline_i][i]/=k;
            fromto(0,lline,i) if(i!=mline_i && A[i][mrow_i]!=0) {
                k=A[i][mrow_i];
                A[i][mrow_i]=0;
                fromto(0,m,j) A[i][j]+=A[mline_i][j]*k;
            }
        }
        if(isOK) printf("%d\n",(int)A[0][0]);
        else printf("-1\n");
    }
    return 0;
}
