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
string s;
int pellen(int l, int r){
    while(l<r){
        if(s[l]!=s[r]){
            return 2;
        }
        l++;
        r--;
    }
    return 1;
}
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, k, t;

    cin >> t;
    while(t-->0){
        cin >> s;
        int l = 0;
        int r = s.size()-1;
        int s_l=0;
        int s_r=0;
        int check=0;
        while(l<r){
            if(s[l]!=s[r] && check==0){
                check=min(pellen(l+1, r), pellen(l, r-1));
                break;
            }
            l++;
            r--;
        }
        cout << check << '\n';
    }

    return 0;
}