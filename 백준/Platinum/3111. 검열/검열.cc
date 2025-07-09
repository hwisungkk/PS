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
#include <map>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 1e9+7;
        
    bool flag=0; 
    long long a, b, c, d;
    long long n, m, t, k;
    long long ans = 0;
    
    string s, sub;
    cin >> sub;
    cin >> s;

    // if(sub.size()==1){
    //     while(s.find(sub)<s.size()){
    //         s.erase(s.find(sub), 1);
    //     }
    //     cout << s;
    //     return 0;
    // }

    deque<char> dq;

    for(int i=0;i<s.size();i++){
        dq.push_back(s[i]);
    }

    deque<char> s_front, s_back;
    int idx=0;
    deque<char> temp;

    while(!dq.empty()){
        if(!flag){
            s_front.push_back(dq.front());
            dq.pop_front();
            idx=sub.size()-1;
            if(s_front.size()>=sub.size()){
                while(s_front.empty() || idx==-1 || s_front.back()==sub[idx]){
                    if(idx==-1){
                        while(!temp.empty())temp.pop_back(); // 지우기
                        flag=1;
                        break;
                    }
                    temp.push_back(s_front.back());
                    s_front.pop_back();
                    idx--;
                }
                if(!flag){
                    while(!temp.empty()){
                        s_front.push_back(temp.back());
                        temp.pop_back();
                    }
                }
            }
        }
        else{
            s_back.push_front(dq.back());
            dq.pop_back();
            idx=0;
            if(s_back.size()>=sub.size()){
                while(s_back.empty() || idx==sub.size() || s_back.front()==sub[idx]){
                    if(idx==sub.size()){
                        while(!temp.empty())temp.pop_back(); // 지우기
                        flag=0;
                        break;
                    }
                    temp.push_back(s_back.front());
                    s_back.pop_front();
                    idx++;
                }
                if(flag){
                    while(!temp.empty()){
                        s_back.push_front(temp.back());
                        temp.pop_back();
                    }
                }
            }
        }
    }
    // for(auto at:s_front)cout << at;
    // cout << '\n';
    // for(auto at:s_back)cout << at;
    // cout << '\n';

    string ans_s="";

    for(auto at:s_front){
        flag=0;
        idx=sub.size()-1;
        ans_s.push_back(at);
        if(ans_s.size()>=sub.size()){
            while(ans_s.empty() || idx==-1 || ans_s.back()==sub[idx]){
                if(idx==-1){
                    while(!temp.empty())temp.pop_back(); // 지우기
                    flag=1;
                    break;
                }
                temp.push_back(ans_s.back());
                ans_s.pop_back();
                idx--;
            }
            if(!flag){
                while(!temp.empty()){
                    ans_s.push_back(temp.back());
                    temp.pop_back();
                }
            }
        }
    }
    for(auto at:s_back){
        flag=0;
        idx=sub.size()-1;
        ans_s.push_back(at);
        if(ans_s.size()>=sub.size()){
            while(ans_s.empty() || idx==-1 || ans_s.back()==sub[idx]){
                if(idx==-1){
                    while(!temp.empty())temp.pop_back(); // 지우기
                    flag=1;
                    break;
                }
                temp.push_back(ans_s.back());
                ans_s.pop_back();
                idx--;
            }
            if(!flag){
                while(!temp.empty()){
                    ans_s.push_back(temp.back());
                    temp.pop_back();
                }
            }
        }
    }
    if(ans_s!="") cout << ans_s;
    
    return 0;
}
/*
babababananana

baba

bana

nana
*/