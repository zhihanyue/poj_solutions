#include <cstdio>
#include <cstring>
#include <cstdlib>
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
using namespace std;
int n;
int A[3][3][31][31],B[3][3][31][31],temp[3][3][31][31];

void Apower(unsigned int __n)
{
    if(__n%2)
        memcpy(B,A,sizeof(A));
    else fromto(1,2,i) fromto(1,n,j) B[i][i][j][j]=1;
    while (__n >>= 1) {
        memset(temp,0,sizeof(temp));
        fromto(1,2,i) fromto(1,2,j) fromto(1,2,k) fromto(1,n,x) fromto(1,n,y) fromto(1,n,z)
            temp[i][j][x][y]+=A[i][k][x][z]*A[k][j][z][y];
        //A*=A;
        memcpy(A,temp,sizeof(temp));
        if (__n % 2) {
            memset(temp,0,sizeof(temp));
            fromto(1,2,i) fromto(1,2,j) fromto(1,2,k) fromto(1,n,x) fromto(1,n,y) fromto(1,n,z)
                temp[i][j][x][y]+=A[i][k][x][z]*B[k][j][z][y];
            //B*=A;
            memcpy(B,temp,sizeof(temp));
        }
    }
}

int main()
{
    int k,M;
    scanf("%d%d%d",&n,&k,&M);
    fromto(1,n,i) fromto(1,n,j) {
        scanf("%d",&A[1][1][i][j]);
        A[1][2][i][j]=A[1][1][i][j];
        A[2][1][i][j]=0;
        A[2][2][i][j]=(i==j);
    }
    Apower(k);
    fromto(1,n,i) fromto(1,n,j)
        printf(j==n?"%d\n":"%d ",B[1][2][i][j]);
    //system("pause");
    return 0;
}
