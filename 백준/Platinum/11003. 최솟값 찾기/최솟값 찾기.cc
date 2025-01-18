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
    
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    deque <int> dq;
    for(int i=0;i<n;i++){
        while(1){
            if(dq.empty()){
                dq.push_back(v[i]);
                break;
            }
            else{
                if(dq.back()>v[i]){
                    dq.pop_back();
                }
                else{
                    dq.push_back(v[i]);
                    break;
                }
            }
        }
        if(i-m>=0){
            if(dq.front() == v[i-m]){
                dq.pop_front();
            }
        }
        cout << dq.front() << ' ';
    }
    return 0;
}