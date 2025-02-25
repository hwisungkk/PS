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

    long long a, b, c;
    int n, m, t;
    int total=0;
    cin >> t;
    while(t-->0){
        cin >> n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int chk = 1;
        int com=1;
        pair<int, int> st1 = {0,0}; //스택1
        pair<int, int> st2 = {0,0}; //스택2
        for(int i=0;i<n;i++){
            if(com==v[i]){
                com++;
            }
            else{
                if(st1.second == v[i]-1){
                    st1.second = v[i];
                }
                else if(st2.second == v[i]-1){
                    st2.second = v[i];
                }
                else if(st1.second==0){
                    st1.first = v[i];
                    st1.second = v[i];
                }
                else if(st2.second==0){
                    st2.first = v[i];
                    st2.second = v[i];
                }
                else {
                    chk = 0; //불가능
                    break;
                }
            }
            if(com == st1.first){
                com = st1.second+1;
                st1.first = st1.second = 0;
            }
            if(com == st2.first){
                com = st2.second+1;
                st2.first = st2.second = 0;
            }
            if(com == st1.first){
                com = st1.second+1;
                st1.first = st1.second = 0;
            }
        }
        if(chk)cout<<"YES\n";
        else cout << "NO\n";
    }

    return 0;
}