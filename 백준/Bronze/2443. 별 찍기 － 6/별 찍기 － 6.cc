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

    int a, b, c;
    int n, m, t;
    cin >> n;
    for(int i=n;i>0;i--){
        for(int j=i;j<n;j++){
            cout << ' ';
        }
        for(int j=2*i-1;j>0;j--){
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}