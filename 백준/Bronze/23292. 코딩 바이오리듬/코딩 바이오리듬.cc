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
        string s, s1;
        a=0;
        cin >> s;
        cin >> n;
        string ans;
        int ma = -1;
        for(int i=0;i<n;i++){
            a=b=c=0;
            cin >> s1;
            for(int i=6;i<=7;i++){
                m = int(s[i]-48);
                t = int(s1[i]-48);
                a+=(m-t)*(m-t);
            }
            for(int i=4;i<=5;i++){
                m = int(s[i]-48);
                t = int(s1[i]-48);
                b+=(m-t)*(m-t);
            }
            for(int i=0;i<=3;i++){
                m = int(s[i]-48);
                t = int(s1[i]-48);
                c+=(m-t)*(m-t);
            }

            if(ma<a*b*c){
                ma = a*b*c;
                ans = s1;
            }
            if(ma==a*b*c){
                if(ans>s1)ans=s1;
            }
        }
        cout << ans;
        return 0;
    }