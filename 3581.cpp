#include <cstdio>
#include <algorithm>
#define MAXN 200008
#define fromto(from,to,i) for(int (i)=(from);(i)<=(to);++(i))
using namespace std;
typedef pair<int,int> sta;
int A[MAXN],A_len;
int B[MAXN],B_len;

int sa[MAXN],rank[2*MAXN],k_len;

bool cmp(int a,int b)
{
    return sta(rank[a],rank[a+k_len])<sta(rank[b],rank[b+k_len]);
}

void getsa(int arr[],int n)
{
    memset(sa,0,sizeof(sa)); 
    memset(rank,-1,sizeof(rank));
    fromto(1,n,i) {sa[i]=i;rank[i]=arr[i];}
    for(k_len=1;k_len<=n;k_len*=2) {
        stable_sort(sa+1,sa+n+1,cmp);
        static int newrank[2*MAXN];
        newrank[sa[1]]=1;
        fromto(2,n,i) newrank[sa[i]]=newrank[sa[i-1]]+cmp(sa[i-1],sa[i]);
        fromto(1,n,i) rank[i]=newrank[i];
    }
}

int main()
{
    scanf("%d",&A_len);
    fromto(1,A_len,i) scanf("%d",&A[i]);
    reverse_copy(A+1,A+A_len+1,B+1);
    B_len=A_len;
    getsa(B,B_len);
    
    fromto(1,B_len,i) if(sa[i]>2) {
        fromto(sa[i],B_len,j) printf("%d\n",B[j]);
        B_len=sa[i]-1;
        break;
    }
    fromto(1,B_len,i) B[i+B_len]=B[i];
    B_len*=2;
    getsa(B,B_len);
    
    //fromto(1,B_len,i) printf("%d\n",sa[i]);
    
    fromto(1,B_len,i) if(sa[i]>1 && sa[i]<=B_len/2) {
        fromto(sa[i],sa[i]+B_len/2-1,j) printf("%d\n",B[j]);
        break;
    }
    return 0;
}
