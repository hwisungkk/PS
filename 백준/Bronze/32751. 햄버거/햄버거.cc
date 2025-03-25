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
        bool flag=1;

        cin >> n;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;

        for(int i=0;i<s.size();i++){
            if(i==0 || i == s.size()-1){
                if(s[i]=='a'){
                    a--;
                    if(a<0)flag=0;
                }
                else flag=0;
            }
            else{
                if(s[i]!=s[i-1]){
                    if(s[i]=='a'){
                        a--;
                        if(a<0)flag=0;
                    }
                    if(s[i]=='b'){
                        b--;
                        if(b<0)flag=0;
                    }
                    if(s[i]=='c'){
                        c--;
                        if(c<0)flag=0;
                    }
                    if(s[i]=='d'){
                        d--;
                        if(d<0)flag=0;
                    }
                }
                else flag=0;
            }
        }
        if(s[s.size()-1] == s[s.size()-2])flag=0;

        if(flag)cout << "Yes";
        else cout << "No";

        return 0;
    }