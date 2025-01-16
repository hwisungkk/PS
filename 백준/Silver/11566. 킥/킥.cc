#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;
    long long ans;
    long long cnt = 0;
    int n, m, t;
    cin >> n;
    vector<int> music(n);
    for (int i=0; i<n; i++){
        cin >> music[i];
    }
    cin >> m;
    vector<int> dream(m);
    for (int i = 0; i < m; i++){
        cin >> dream[i];
    }
    int mi=1e9, ma=-1;
    for (int i=1;i<=1000; i++){
        for (int p=0; p<=m; p++){
            cnt = 0;
            for (int j=p, k=0; j<m; j+=i){
                if (dream[j]==music[k]){
                    cnt++;
                    k++;
                }
                else{
                    cnt=0;
                    k=0;
                }
                if (cnt == n){
                    mi=min(mi, i-1);
                    ma=max(ma, i-1);
                    break;
                }
            }
        }
    }
    if (mi == 1e9 && ma == -1)
        cout << "-1\n";
    else
        cout << mi << ' ' << ma << '\n';
    return 0;
}