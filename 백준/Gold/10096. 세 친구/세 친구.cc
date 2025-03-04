#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    long long n, m, t;
    string s;
    cin >> n;
    cin >> s;

    if(n%2==0){
        cout << "NOT POSSIBLE\n";
        return 0;
    }
    string s1, s2;
    s1 = s.substr(0, n/2+1); //왼쪽 더 크게
    s2 = s.substr(n/2+1, n);
    int chk = 0;

    string ans1 = s2; // 답이 될 문자
    int l=0, r=0;
    while(r<n/2){
        if(s1[l]!=s2[r] && chk == 0){
            chk = 1;
            ans1 = s2;
            l++;
        }
        else if(s1[l]!=s2[r] && chk == 1){
            ans1 = "";
            break;
        }
        else{
            l++;
            r++;
        }
    }
    s1 = s.substr(0, n/2); //왼쪽 더 크게
    s2 = s.substr(n/2, n);
    chk = 0;
    string ans2 = s1; // 답이 될 문자
    l=0, r=0;
    while(l<n/2){   
        if(s1[l]!=s2[r] && chk == 0){
            chk = 1;
            r++;
        }
        else if(s1[l]!=s2[r] && chk == 1){
            ans2 = "";
            break;
        }
        else{
            l++;
            r++;
        }
    }
    if(ans1=="" && ans2=="")cout << "NOT POSSIBLE";
    else if(ans1==ans2) cout << ans1;
    else if(ans1=="" && ans2!="") cout << ans2;
    else if(ans1!="" && ans2=="") cout << ans1;
    else cout << "NOT UNIQUE";
    return 0;
}