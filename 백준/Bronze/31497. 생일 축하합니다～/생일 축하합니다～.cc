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

    int t = 0;
    cin >> t;
    vector<string> s(t);
    for(int i=0;i<t;i++){
        cin >> s[i];
    }
    for(int i=0;i<t;i++){
        cout << "? " << s[i] << endl;
        cin >> b;
        cout << "? " << s[i] << endl;
        cin >> c;
        if(b!=c ||(b==1&&c==1)){
            cout << "! " << s[i] << endl;
            return 0;
        }
    }
    return 0;
}