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

        long long l1=0, l2;

        cin >> n >> l2;
        long long cnt=0;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        l1=v[0];
        int l=0, r=1;
        while(r<=n){
            if(l1==l2){
                cnt++;
                l1-=v[l];
                l++;
            }
            else if(l1>l2){
                l1-=v[l];
                l++;
            }
            else if(l1<l2){
                if(r==n)break;
                l1+=v[r];
                r++;
            }
        }
        cout << cnt;

        return 0;
    }