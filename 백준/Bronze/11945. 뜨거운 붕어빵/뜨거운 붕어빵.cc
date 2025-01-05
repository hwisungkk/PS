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
    
    long long n, m, k;
    int a, b, c;

    cin >> a >> b;
    for(int i=0;i<a;i++){
        string s;
        cin >> s;
        for(int j=b-1;j>=0;j--){
            cout << s[j];
        }cout << '\n';
    }
    return 0;
}