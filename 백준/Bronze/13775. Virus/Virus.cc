#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    char ch;
    
    string s;
    cin >> n;
    getline(cin, s);
    getline(cin, s);

    int key = n;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ' || s[i]< 'a' || s[i] > 'z'){
            cout << s[i];
            continue;
        }
        s[i]-=key;
        if(s[i]<'a'){
            cout << char(s[i]+26);
        }
        else cout << s[i];
        key++;
        if(key==26)key=1;
    }
    return 0;
}