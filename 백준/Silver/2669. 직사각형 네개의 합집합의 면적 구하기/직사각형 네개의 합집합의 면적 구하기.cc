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

        int page[100][100]={0};

        for(int i=0;i<4;i++){
            cin >> a >> b >> c >> d;
            for(int j=a;j<c;j++){
                for(int k=b;k<d;k++){
                    page[j][k]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                if(page[i][j]>0)ans++;
            }
        }
        cout << ans;

        return 0;
    }