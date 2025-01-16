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
    
    int a, b, c, d;
    long long ans;
    long long cnt = 0;
    string s;
    int n, m, t;
    cin >> n >> m;
    vector<int> cc(n);
    vector<int> tt(n);
    vector<int> time(n);
    for(int i=0;i<n;i++){
        cin >> cc[i];
    }
    for(int i=0;i<n;i++){
        cin >> tt[i];
        time[i] = cc[i]-tt[i]; //해야하는 시간.
    }
    sort(time.begin(), time.end());
    for(int i=0;i<m;i++){
        cin >> a >> b;
        int l = 0;
        int r = n+1;
        int mid = 0;
        while(l+1<r){
            mid = (l+r)/2;
            if(b >= time[mid]) l=mid;
            else r = mid;
        }
        //cout << n-r << '\n';
        //-1 3 4 4 6
        if(n-r >= a)cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}