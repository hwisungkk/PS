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

    string s;
    int n, m;
    cin >> s >> m;
    n = stoi(s); //문자열로 받고 숫자로 ㄱㄱㄱ
    vector<int> broke(m);
    for(int i=0;i<m;i++){
        cin >> broke[i];
    }
    vector<int> button;
    for(int i=0;i<=9;i++){
        int bu=0;
        for(int j=0;j<broke.size();j++){
            if(i == broke[j])bu++;
        }
        if(bu==0)button.push_back(i);
    }
    int mi = 1e9;
    int cmp=0;
    function <void(int)> back = [&](int k){
        if(k>=s.size()+1){
            return;
        }
        for(int i=0;i<button.size();i++){
            cmp += (button[i] * pow(10, k));
            mi = min(mi, abs(n-cmp) + k + 1);
            back(k+1);
            cmp -= (button[i] * pow(10, k));
        }
    };
    back(0);
    mi = min(mi, abs(n-100));
    cout << mi;
    return 0;
}