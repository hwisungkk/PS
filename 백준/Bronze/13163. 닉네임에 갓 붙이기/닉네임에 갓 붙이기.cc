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
int k, n;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    int a, b, c;
    int t;
    cin >> m;
    string s;
    cin >> s;
    for(int i=0;i<m;i++){
        t=0;
        getline(cin, s);
        for(int j=0;j<s.size();j++){
            if(t==0 && s[j]==' '){
                t=1;
                cout << "god";
            }
            else if(t==0 && s[j]!=' '){
                continue;
            }
            else if(t==1 && s[j]==' '){
                continue;
            }
            else{
                cout << s[j];
            }
        }
        cout << '\n';
    }
    return 0;
}
//8 2 9 1 4 6 7 10