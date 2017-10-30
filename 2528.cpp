#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define fromto(from,to,i) for(int i=(from);i<=(to);++i)
#define fromdownto(from,to,i) for(int i=(from);i>=(to);--i)
#define fromgoto(from,to,i) for(int i=(from),__to=(to);i<=__to;++i)
#define watchArr(A,from,to) printf(#A" : ");\
                            for(int i=(from);i<=(to);++i) { \
                                printf("\t[%d]=%d ",i,A[i]);\
                                if((i-(from)+1) % 8 == 0) printf("\n");\
                            }\
                            printf("\n");
#define watch(A,type) printf(#A" = " type "\n",A);
#define MAXN 10005

int xdtree[100008];

inline void push_down(int o,int L,int r) {
    if(L + 1 != r && xdtree[o] != 0) {
        xdtree[o * 2] = xdtree[o];
        xdtree[o * 2 + 1] = xdtree[o];
        xdtree[o] = 0;
    }
}

set<int> hb;
void query(int o,int L,int r) {
    if(L>=r) return;
    if(xdtree[o] != 0) {
        //printf("hb:%d\n",xdtree[o]);
        hb.insert(xdtree[o]);
        return;
    }
    push_down(o, L, r);
    int M = L + (r - L) / 2;
    query(o * 2, L, M);
    query(o * 2 + 1, M, r);
}

int up_L,up_r,up_set;
void update(int o,int L,int r) { 
    if(L >= up_r || r <= up_L) return;
    if(up_L <= L && r <= up_r) {
        xdtree[o] = up_set;
        //printf("xdtree[%d]=%d\n",o,xdtree[o]);
        return;
    }
    push_down(o, L, r);
    int M = L + (r - L) / 2;
    update(o * 2, L, M);
    update(o * 2 + 1, M, r);
}

int L[MAXN],r[MAXN];

void solve() {
    hb.clear();
    map<int,int> ls;
    vector<int> vec;
    int n;
    scanf("%d",&n);
    fromto(1,n,i) {
        scanf("%d%d",&L[i],&r[i]);
        ++r[i];
        vec.push_back(L[i]);
        vec.push_back(r[i]);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    fromgoto(0, vec.size() - 1, i) {
        ls[vec[i]] = i + 1;
        //printf("%d->%d\n",vec[i],i + 1);
    }
    fromto(1,n,i) {
        L[i] = ls[L[i]];
        r[i] = ls[r[i]];
        //printf("[%d,%d]\n",L[i],R[i]);
    }
    int xd_r = vec.size();
    //watch(xd_r,"%d");
    memset(xdtree,0,sizeof(xdtree));
    fromto(1,n,i) {
        up_L = L[i];
        up_r = r[i];
        //printf("up_L=%d\tup_r=%d\n",up_L,up_r);
        up_set = i;
        update(1, 1, xd_r);
    }
    query(1, 1, xd_r);
    printf("%d\n", hb.size());
}

int main()
{
    int case_cnt;
    scanf("%d",&case_cnt);
    while(case_cnt--) solve();
    return 0;
}
