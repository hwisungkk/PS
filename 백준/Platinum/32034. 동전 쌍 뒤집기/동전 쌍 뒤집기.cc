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
    long long ans;
    string s;
    
    cin >> t;
    while (t-->0) {
        vector<int> v;
        cin >> n;
        cin >> s;
        ans = 0;
        for (int i=0;i<s.length();i++) {
            if (s[i] == 'T') { //뒷면이 나온 위치를 저장
                v.push_back(i);
            }
        }

        if (v.size()%2!=0) { //뒷면이 홀수개면 불가능
            cout << "-1\n";
        }
        else if (v.size()==0) {
            cout << "0\n";
        }
        else { //뒷면 짝수
            stack<int> st;
            for (int i=0;i<v.size();i++) {
                if (st.empty()) { //비었으면 일단 넣고
                    st.push(i);
                    continue;
                }
                int k = st.top();
                if ((v[i]-v[k])%2==0) { //사이의 동전 개수가 홀수개면 또 넣고
                    st.push(i);
                }
                else {
                    ans += (v[i]-v[k]);
                    st.pop();
                }
            }

            if (!st.size()) cout << ans << '\n';
            else cout << "-1\n";
        }
    }
    return 0;
}
/*
THHT -> 3
THHHHT -> 5
THHHHHHT -> 7


THTTHHTTHT


THTHTTHHTTHTHT

1
6
THTTHT

HTHHTTTTHHT


THTTTTHT
*/