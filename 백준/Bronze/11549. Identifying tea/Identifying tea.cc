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
        int cnt=0;
        vector<int>v(5);
        for(int i=0;i<5;i++){
            cin >> v[i];
            if(n==v[i])cnt++;
        }
        cout << cnt;
        return 0;
    }