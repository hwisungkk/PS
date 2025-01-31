#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;\
int main() {
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    while(1){
        cin >> n >> m;
        if(!n && !m)return 0;
        cout << n+m << '\n';
    }
    return 0;
}
