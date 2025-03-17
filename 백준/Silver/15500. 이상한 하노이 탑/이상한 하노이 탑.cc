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
    bool flag=0;
    
    cin >> n;
    vector<bool> s1_ch(n+1,0);
    stack <int> s1, s2;
    for(int i=0;i<n;i++){
        cin >> a;
        s1.push(a);
        s1_ch[a]=1;
    }
    int cnt=0;
    vector<string> vs;
    while(n){
        if(s1_ch[n]){ //s1스택에 있으면
            if(s1.top()==n){
                s1_ch[s1.top()]=0;
                s1.pop();
                vs.push_back("1 3");
                n--;
            }
            else{
                s2.push(s1.top());
                s1_ch[s1.top()]=0;
                s1.pop();
                vs.push_back("1 2");
            }
        }
        else{
            if(s2.top()==n){
                s2.pop();
                vs.push_back("2 3");
                n--;
            }
            else{
                s1.push(s2.top());
                s1_ch[s2.top()]=1;
                s2.pop();
                vs.push_back("2 1");
            }
        }
    }
    cout << vs.size() << '\n';
    for(int i=0;i<vs.size();i++){
        cout << vs[i] << '\n';
    }
    return 0;
}