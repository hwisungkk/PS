#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c;
    int t;

    int n, m;
    string s;
    cin >> s;
    if(s.size()<=2){
        cout<<s.size();
        return 0;
    }
    int ssize=s.size();
    s+="xy"; //오류 안나게 길이 조정정
    int ans=0;
    string s2="";
    for(int i=0;i<ssize;i++){
        if(s[i]!=s[i+1] && s[i+2]==s[i+1]){
            s2+=s[i];
            s2+=s[i+1];
            break;
        }
        else{
            s2+=s[i];
        }
    }
    s2+="x";
    string s3 = "";
    for(int i=0;i<s2.size()-1;i++){
        if(s2[i]!=s2[i+1]){
            s3+=s2[i];
        }
        else{
            continue;
        }
    }
    cout << s3.size();
    return 0;
}