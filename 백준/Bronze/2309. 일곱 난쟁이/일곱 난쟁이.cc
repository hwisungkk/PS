#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    int n, m, t;
    int total=0;
    vector<int> v(9);
    for(int i=0;i<9;i++){
        cin >> v[i];
        total+=v[i];
    }
    sort(v.begin(), v.end());
    for(int i=0;i<=7;i++){
        for(int j = i+1;j<9;j++){
            if(total-v[i]-v[j]==100){
                for(int k=0;k<9;k++){
                    if(k!=i && k!=j){
                        cout << v[k] << '\n';
                    }
                }
                return 0;
            }
        }
    }

    return 0;
}