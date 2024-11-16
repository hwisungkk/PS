#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ar[40][2];
int fib(int n){
    ar[n][0] = ar[n-1][0] + ar[n-2][0];
    ar[n][1] = ar[n-1][1] + ar[n-2][1];
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    ar[0][0]=1;
    ar[0][1]=0;
    ar[1][0]=0;
    ar[1][1]=1;
    for (int i = 2; i <= 40; i++)
    {
        fib(i);
    }
    for(int i=0;i<n;i++){  
        cin >> m;
        cout << ar[m][0] << ' ' << ar[m][1] << '\n';
    }
}