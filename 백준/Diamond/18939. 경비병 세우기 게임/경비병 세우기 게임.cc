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
long long maxi=0;
int n;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, m, k;
    int t;

    cin >> t;
    while(t-->0){
        cin >> n >> m >> k;
        //서로 다른 2개가 있으면 n*m-2*k*k가 짝수인지 홀수인지에 따라.
        //아니면 무조건 yuto가 이기는거 아님?
        if(m/2 < k){
            cout << "Yuto\n";
        }
        else{
            if((n*m-2*k*k)%2==1)cout << "Yuto\n";
            else cout << "Platina\n";
        }
    }
    return 0;
}
