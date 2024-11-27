#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long n, k = -1;
    int m;
    string s1, s2;
    string ans="";
    cin >> s1;
    cin >> s2;
    stack <pair<char, int>> s;
    int count = 0;
    for(int i=0;i<s1.size();i++){
        ans+= s1[i];
        if(!s.empty())count = s.top().second+1;
        else count =0;
        if(s1[i]==s2[0]){
            count = 0;
            s.push({s1[i], count});
            count++;
            if(count==s2.size()){
                for(int j=0;j<s2.size();j++){
                    s.pop();
                    ans.pop_back();
                }
                count=0;
            }
        }
        else if(s1[i]==s2[count]){
            s.push({s1[i], count});
            count++;
            if(count==s2.size()){
                for(int j=0;j<s2.size();j++){
                    s.pop();
                    ans.pop_back();
                }
                count=0;
            }
        }
        else{
            while(!s.empty()){
                s.pop();
            }
        }
    }
    if(ans=="")cout<<"FRULA";
    else cout << ans;

    return 0;
}
/*
ABABCAABCBABABCCCBCAC
123423453456786420
ABC

ABBCAC
*/