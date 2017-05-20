#include <iostream>
#include <set>
using namespace std;

struct Node { int K,P; };
struct cmp
{
    bool operator()(Node a,Node b)
    {
        return a.P<b.P;
    }
};
multiset<Node,cmp> myset;

int main()
{
    while(true)
    {
        int N;
        cin >> N;
        if(N==0)
            break;
        else if(N==1)
        {
            int K,P;
            cin >> K >> P;
            myset.insert((Node){K,P});
        }
        else if(N==2)
        {
            if(myset.size()!=0)
            {
                set<Node>::iterator it=myset.end();
                --it;
                cout << (it->K) << endl;
                myset.erase(it);
            }
            else cout << 0 << endl;
        }
        else if(N==3)
        {
            if(myset.size()!=0)
            {
                set<Node>::iterator it=myset.begin();
                cout << (it->K) << endl;
                myset.erase(it);
            }
            else cout << 0 << endl;
        }
    }
    return 0;
}
