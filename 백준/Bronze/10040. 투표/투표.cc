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

    cin >> a >> b;
    vector<int>ar(a+1);
    vector<int>vote(a+1, 0);
    for(int i=1;i<=a;i++){
        cin >> ar[i];
    }
    for(int i=0;i<b;i++){
        cin >> c;
        for(int j=1;j<=a;j++){
            if(c>=ar[j]){
                vote[j]++;
                break;
            }
        }
    }
    int ma=-1;
    for(int i=1;i<=a;i++){
        if(ma<vote[i]){
            ma=vote[i];
            m=i;
        }
    }cout<<m;
    return 0;
}
