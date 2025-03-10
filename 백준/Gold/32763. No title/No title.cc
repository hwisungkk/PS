#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    char ch;
    cin >> n;
    vector<char> result(n, 0);
    vector<char> ans(n+1, 0);
    for(int i=1;i<n;i++){
        cout << "? " << i << " * " << i+1 << endl;
        cin >> result[i];
    }
    if(result[1]=='+'){
        cout << "? " << 1 << " + " << 2 << endl;
        cin >> ch;
        ans[1] = ch;
    }
    else if(result[1]=='-' && result[2]=='-'){
        cout << "? " << 1 << " + " << 3 << endl;
        cin >> ch;
        ans[1] = ch;
    }
    else{ //-, +일 때
        cout << "? " << 2 << " + " << 3 << endl;
        cin >> ch;
        if(ch=='+')ans[1]='-';
        else ans[1]='+';
    }

    for(int i=2;i<=n;i++){
        if(result[i-1]=='-'){
            if(ans[i-1]=='+')ans[i]='-';
            else ans[i] = '+';
        }
        else{
            ans[i]=ans[i-1];
        }
    }
    cout << "! ";
    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }cout << endl;
    

    return 0;
}