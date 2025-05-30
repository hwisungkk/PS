#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int a, b, c, d;
    long long n, m, t, k;
    bool flag=0; 

    vector<int> x(20000), y(20000);

    while (1) {
        cin >> a >> b >> c;
        if (a==0 && b==0 && c==0) break;

        vector<int> garo(a, 0);       
        vector<int> sero(b, 0);         
        vector<int> d1(a+b, 0);     
        vector<int> d2(a+b, 0);      

        for (int i=0; i<c; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;

            garo[x] = 1;
            sero[y] = 1;
            d1[x+y] = 1;
            d2[x-y+(b-1)] = 1; 
        }

        int block=0;
        for (int x=0; x<a; x++) {
            for (int y=0; y<b; y++) {
                if (garo[x] || sero[y] || d1[x+y] || d2[x-y+(b-1)]) {
                    block++;
                }
            }
        }

        cout << a*b-block<<'\n';
    }
    

    return 0;
}
