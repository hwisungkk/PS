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
int n, m;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> n;
    vector<int> v(n);
    int ans=0;
    int x=1;

    for(int i=0;i<n;i++){
        cin >> t;
        if(t==1){
            ans +=x;
            x++;
        }
        else x=1;
    }
    cout << ans;
    
    return 0;
}