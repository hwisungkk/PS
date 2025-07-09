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

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;

    cin >> n;
    vector<int> v(n);
    vector<int> cnt(1000001, 0); // 나온 횟수 배열
    for(int i=0;i<n;i++){
        cin >> v[i];
        cnt[v[i]]++;
    }

    vector<int> ansv(n);
    deque<int> dq;
    for(int i=n-1;i>=0;i--){
        if(dq.size()==0){
            ansv[i]=-1;
            dq.push_back(v[i]);
        }
        else{
            while(dq.size()&&cnt[v[i]]>=cnt[dq.front()]){
                dq.pop_front();
            }
            if(dq.size()==0){
                ansv[i]=-1;
                dq.push_back(v[i]);
            }
            else{
                ansv[i]=dq.front();
                dq.push_front(v[i]);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << ansv[i] << ' ';
    }


    return 0;
}