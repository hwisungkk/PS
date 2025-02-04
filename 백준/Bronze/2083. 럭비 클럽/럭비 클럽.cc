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

    string s;
    int n, m;
    while(1){
        cin >> s >> n >> m;
        if(s=="#")break;
        if(n>17 || m >= 80){
            cout << s << ' ' << "Senior\n";
        }
        else{
            cout << s << ' ' << "Junior\n";
        }
    }
    return 0;
}
