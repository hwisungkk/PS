#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long mod = 998'244'353;

    bool flag = 0;
    long long a, b, c, d;
    long long n, m, t, k = 0;
    long long ans = 0;

    cin >> t;
    while(t-->0){
        string s;
        cin >> s;
        stack<int> st;
        ans=1;

        string s1="";
        string s2="";
        int x, y;
        for(int i=0;i<s.size();i++){
            if(s[i]=='/'){
                flag=1;
                continue;
            }
            if(!flag)s1+=s[i];
            else s2+=s[i];
        }
        flag=0;
        x=stoi(s1);
        y=stoi(s2);

        while(x!=y){
            if(x>y){
                x-=y;
                st.push(2);//이게 r
            }
            else{
                y-=x;
                st.push(1);
            }
        }
        while(!st.empty()){
            if(st.top()==1){
                ans*=2;
            }
            else ans=ans*2+1;
            st.pop();
        }
        cout << ans << '\n';
    }

    return 0;
}