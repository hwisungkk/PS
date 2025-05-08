#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int a, b, c, d;
    long long n, m, t;
    bool flag=1; 
    
    cin >> n >> m;
    vector<pair<long long, long long>> v;
    a=0;
    for(int i=0;i<n;i++){
        cin >> b;
        v.push_back({a, a+b-1});
        a+=(b-1);
        a++;
    }

    for(int i=0;i<m;i++){ //쿼리
        cin >> b;
        int l=-1;
        int r = v.size();
        int mid = (l+r)>>1;
        while(1){
            mid = (l+r)>>1;
            if(v[mid].first <= b && b<=v[mid].second){
                cout << mid+1 << '\n';
                break;
            }
            else if(v[mid].first > b)r = mid;
            else l = mid;
        }
    }

    return 0;
}