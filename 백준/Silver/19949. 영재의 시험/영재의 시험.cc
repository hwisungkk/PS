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

        long long ans=0;
        vector<int> score(10);
        for(int i=0;i<10;i++){
            cin >> score[i];
        }
        vector<int> jjik(10, 0);
        function <void(int, int)> back=[&](int k, int sc){
            if(k==10){
                if(sc>=5)ans++;
                return;
            }
            for(int i=1;i<=5;i++){
                jjik[k]=i;
                if(score[k]==i)sc++;
                if(!(k>=2 && jjik[k] == jjik[k-1] && jjik[k-1]==jjik[k-2]))
                    back(k+1, sc);
                if(score[k]==i)sc--;
                jjik[k]=0;
            }
        };
        back(0, 0);
        cout << ans;

        return 0;
    }