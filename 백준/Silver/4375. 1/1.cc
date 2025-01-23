#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;
    int n, m, x, y;
    int mi = 1e9;
    while(1){
        int k = 1;
        int count=0;
        cin >> n;
        if(cin.eof()){
            break;
        }
        while(1){
            k%=n;
            count++;
            if(k==0)break;
            k = k*10+1;
        }
        cout << count << '\n';
    }
    
    return 0;
}