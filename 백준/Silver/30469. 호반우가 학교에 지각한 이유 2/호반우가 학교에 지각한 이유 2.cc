#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;
    long long ans;
    long long cnt = 0;
    int n, m, t;
    cin >> n >> m >> t;
    
    if(m/10==1 || m/10==3 || m/10==7 || m/10==9){
        cout << n;
        if(n%10==9){
            cout <<"7";
            t--;
        }
        for(int i=0;i<t-4;i++){
            cout << "1";
        }
        cout << m;
    }
    else cout << "-1";
    return 0;
    // A는 무조건 1,3,7,9로 끝남., N은 7보다 크다는 조건도 있었네..
    // 0,2,4,5,6,8로 끝나면 다 불가능
    // 1로 시작하면 1,3,7,9 무조건 가능
    // 3으로 시작하면 31, 11~가능
    // 7로 시작하면 71, 11, 11 ~가능
    // 9로 시작하면 97 71 가능~
}
/*
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97
*/