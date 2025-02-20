#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int n, m, t;
    
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    t=0;
    int s_n = n;
    for(int i=0;i<s_n-1;i++){
        if(v[i]+1 == v[i+1]){
            for(int j=i+1;j<s_n;j++){
                if(v[i+1]!=v[j]){
                    swap(v[i+1], v[j]);
                    i=-1;
                    break;
                }
                if(j==s_n-1){
                    swap(v[i], v[j]);
                    i=-1;
                    s_n--;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << v[i] << ' ';
    }

    return 0;
}