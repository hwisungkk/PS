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
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    int t;

    int n, m;
    cin >> t;
    int i=0;
    vector<int> ans(31);
    ans[1]=6;
    ans[2]=28;
    for(int i=3;i<=30;i++){
        ans[i] = (6*ans[i-1]-4*ans[i-2])%1000;
        if(ans[i]<0)ans[i]+=1000;
    }
    while(t-->0){
        cin >> m;
        i++;
        cout << "Case #" << i << ": " << setw(3) << setfill('0') << ans[m]-1%1000 <<'\n';
    }
    return 0;
}
/*
3+r5

27 15
*/