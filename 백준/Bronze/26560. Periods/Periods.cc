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

    cin >> a;
    string s2;
    getline(cin,s2);
    for(int i=0;i<a;i++){
        string s;
        getline(cin, s);
        if(s[s.size()-1]!='.'){
            cout << s;
            cout << '.';
        }
        else{
            cout << s;
        }
        cout << '\n';
    }
    return 0;
}