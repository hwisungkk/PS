#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=1;j<=i;j++){
            cout << ' ';
        }
        cout << '*';
        for(int j=0;j<n-2;j++){
            if(i==0)cout << '*';
            else cout << ' ';
        }
        cout << '*';
        for(int j=0;j<(n-2-i)*2+1;j++){
            cout << ' ';
        }
        if(i!=n-1) cout << '*';
        for(int j=0;j<n-2;j++){
            if(i==0)cout << '*';
            else cout << ' ';
        }
        cout << '*';
        cout << '\n';
    }
    for(int i=n-1;i>0;i--){
        for(int j=1;j<i;j++){
            cout << ' ';
        }
        cout << '*';
        for(int j=0;j<n-2;j++){
            if(i==1)cout << '*';
            else cout << ' ';
        }
        cout << '*';
        for(int j=0;j<(n-1-i)*2+1;j++){
            cout << ' ';
        }
        cout << '*';
        for(int j=0;j<n-2;j++){
            if(i==1)cout << '*';
            else cout << ' ';
        }
        cout << '*';
        cout << '\n';
    }

    return 0;
}