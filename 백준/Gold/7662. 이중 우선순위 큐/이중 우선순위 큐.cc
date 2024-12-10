#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
long long mi = 1e16;
int total=0;
int check[50][50]={0};
int n;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int m, k;
    long long a, b;

    cin >> n;
    while(n--){
        multiset <int> ms;
        cin >> m;
        for(int i=0;i<m;i++){
            char c;
            cin >> c >> k;
            if(c=='I')ms.insert(k);
            else {
                if(!ms.empty()){
                    if(k==1){
                        ms.erase(prev(ms.end()));
                    }
                    else{
                        ms.erase(ms.begin());
                    }
                }
                else continue;
            }
        }
        if(ms.empty())cout<<"EMPTY\n";
        else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }
    return 0;
}