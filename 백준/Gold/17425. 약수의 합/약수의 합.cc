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
    long long a, b, c;
    int t;

    string s;
    int n, m;
    cin >> t;
    while(t-->0){
        long long ans=0;
        cin >> n;
        for(int i=1;i<=sqrt(n);i++){
            a = (int)n/i;
            b = (int)n/(i+1);
            b++;
            if(b<sqrt(n))b=int(sqrt(n))+1;
            c = (a+b) * (a-b+1)/2;
            ans += c*i;
        }
        for(int i=1;i<sqrt(n);i++){
            ans += n/i * i;
        }
        
        cout << ans << '\n';
    }
    //1 1
    //2 1 2
    //3 1 3
    //4 1 2 4
    //5 1 5
    //6 1 2 3 6
    //7 1 7
    //8 1 2 4 8
    //9 1 3 9
    //10 1 2 5 10
    
    return 0;
}