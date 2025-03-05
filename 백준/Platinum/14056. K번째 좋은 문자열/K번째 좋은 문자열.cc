#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
string s;
bool good_chk(string s1, string s2){ //s2에 원하는 문자열이 있는지 확인
    int l = 0;
    int r = 0;
    while(1){ 
        if(l>s1.size()){ //있음
            return 1;
        }
        if(r>s2.size()){ //없음
            return 0;
        }
        if(s1[l]==s2[r]){
            l++;
            r++;
        }
        else{
            r++;
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d;
    int n, m, t;
    vector<string> v;

    cin >> s >> n;

    if(good_chk("()", s)){
        v.push_back("()");
    }
    for(int i=0;i<v.size();i++){
        int num = 1;
        while(1){
            string ch_s = "(";
            for(int j=0;j<num;j++){
                ch_s += v[i];
            }
            ch_s += ")";
            
            if(good_chk(ch_s, s)){
                v.push_back(ch_s);
            }
            else break;
            num++;
        }
    }


    sort(v.begin(), v.end());

    if(n>v.size()){
        cout << -1;
    }
    else{
        cout << v[n-1];
    }
    
    
    return 0;
}