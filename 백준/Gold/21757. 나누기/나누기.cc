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
        long long total=0;
        vector<long long>v(n); // 분할 정복으로 풀리려나
        for(int i=0;i<n;i++){
            cin >> v[i];
            total+=v[i];
        }
        long long res=0;
        if(total%4==0){
            res = total/4;
        }
        else{
            cout << 0;
            return 0;
        }
        vector<int> middle; // 얘가 total/2를 찾는 좌표임.
        vector<int> qu_front; // 얘가 앞에서 total/4를 찾는 좌표임.
        vector<int> qu_back; // 얘가 뒤에서 total/4를 찾는 좌표임.
        long long at = v[0];
        for(int i=1;i<n-2;i++){
            at+=v[i];
            if(at==res*2){
                middle.push_back(i);
            }
        }
        at=0;
        for(int i=0;i<n-3;i++){
            at+=v[i];
            if(at==res){
                qu_front.push_back(i);
            }
        }
        at=0;
        for(int i=n-1;i>=3;i--){
            at+=v[i];
            if(at==res){
                qu_back.push_back(i);
            }
        }

        // for(int i=0;i<middle.size();i++){
        //     cout << middle[i] << ' ';
        // }cout << '\n';
        
        // for(int i=0;i<qu_front.size();i++){
        //     cout << qu_front[i] << ' ';
        // }cout << '\n';
        
        // for(int i=0;i<qu_back.size();i++){
        //     cout << qu_back[i] << ' ';
        // }cout << '\n';
        // 앞에서 total/4, 뒤에서 total/4를 찾으면 되는거 아닌가? 투포인터가 더 빠른가
        long long ans=0;
        int f_l=0;
        int b_l=0;
        for(int i=0;i<middle.size();i++){
            if(middle[i]>qu_front[f_l]){
                f_l++;
            }
            if(middle[i]>qu_back[b_l]){
                b_l++;
                if(b_l==qu_back.size())break;
            }

            ans+= f_l*(qu_back.size() - b_l);
        }
        cout << ans;
        return 0;
    }