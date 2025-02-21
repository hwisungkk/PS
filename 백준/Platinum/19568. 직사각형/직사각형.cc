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
    
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++){
          if(i<15&&j==15)cout << 1 << ' ';
          else if(i>15&&j==15)cout << 15 << ' ';
          else if(i==15&&j<15)cout << 225 << ' ';
          else if(i==15&&j>15)cout << 3375 << ' ';
          else cout << 0 << ' ';
        }
        cout << '\n';
    }

    return 0;
}