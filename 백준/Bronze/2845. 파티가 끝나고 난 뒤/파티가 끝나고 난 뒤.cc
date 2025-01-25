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
    cin >> n >> m;

    vector<int> v(5);
    for(int i=0;i<5;i++){
        cin >> v[i];
    }
    for(int i=0;i<5;i++){
        cout << v[i]-n*m <<' ';
    }
    return 0;
}
