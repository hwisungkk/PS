#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
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
    
    long long a, b, c, d;
    long long ans;
    long long cnt = 0;
    string s;
    int n, m, t;
    cin >> t;

    int idx=0;
    while(t-->0){
        vector <pair<int, int>> v;
        int cnt=0;
        idx++;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a >> b;
            v.push_back({a,b});
        }
        sort(v.begin(), v.end());
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(v[i].second > v[j].second)cnt++;
            }
        }

        cout << "Case #" << idx << ": " << cnt << '\n';
    }
    
    return 0;
}