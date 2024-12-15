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
int k, n;
bool compare(pair<string, string> a, pair<string, string> b){
    if(a.first==b.first){
        return a.second > b.second;
    }
    return a.first < b.first;

}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b, c;
    int t;
    cin >> m;

    while(m-->0){
        cin >> a >> b >> c;
        int ans = 0;
        while(1){
            if(a<=b*c){
                ans+=1;
                break;
            }
            else{
                a -= b*c;
                a+=1;
                ans+=2;
            }
            if(a>1 && b*c == 1){
                ans=-1;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
//8 2 9 1 4 6 7 10
