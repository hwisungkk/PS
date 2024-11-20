#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int m;
vector <int> v(1000000);
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    long long n, k = -1;
    string s1, s2;
    int j;
    cin >> n;
    while(n--){
        int a, b, L;
        cin >> a >> b >> L; //장애물 개수, 부스터 개수, 거리.
        int jump=1;

        vector <pair<int,int>> jang;
        vector <pair<int,int>> boost;
        for(int i=0;i<a;i++){
            int d, e;
            cin >> d >> e;
            jang.push_back({d,e-d+1});
        }
        for(int i=0;i<b;i++){
            int d, e;
            cin >> d >> e;
            boost.push_back({d,e});
        }
        boost.push_back({2000000000, 0});
        vector <int> sol;
        int j=0;
        int count = 0;
        for(auto p : jang){
            while(boost[j].first < p.first){
                sol.push_back(boost[j].second);
                j++;
            }
            sort(sol.begin(), sol.end());
            for(int i=sol.size()-1;i>=0;i--){
                if(jump <= p.second){
                    jump += sol[i];
                    sol.pop_back();
                    count++;
                }
            }
            if(jump <= p.second){
                count=-1;
                break;
            }
        }
        cout << count << '\n';
    }
    
    return 0;
}