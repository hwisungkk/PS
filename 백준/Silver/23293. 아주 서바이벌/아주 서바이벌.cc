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
        char ch;
        string s, s1;
        vector<int> log;
        set<int> cut;
        cin >> n >> m; //로그, 플레이어
        vector<int> place(m+1, 1);
        vector<vector<int>> item(m+1, vector<int>(54,0));

        for(int i=0;i<n;i++){
            cin >> a >> b; //로그번호, 실행
            cin >> ch;
            if(ch=='M'){ //이동
                cin >> c;
                place[b]=c;
            }
            else if(ch=='F'){ //찾기
                cin >> c;
                item[b][c]++;
                if(c!=place[b]){
                    log.push_back(a);
                }
            }
            else if(ch=='A'){ //공격
                cin >> c;
                if(place[c]!=place[b]){
                    log.push_back(a);
                    cut.insert(b);
                }
            }
            else if(ch=='C'){ //조합
                bool flag = 0;
                cin >> c >> d;
                if(item[b][c]>0)item[b][c]--;
                else flag=1;
                if(item[b][d]>0)item[b][d]--;
                else flag=1;
                if(flag)log.push_back(a);
                
            }
        }
        sort(log.begin(), log.end());
        cout << log.size() << '\n';
        for(int i=0;i<log.size();i++){
            if(i==log.size()-1)cout << log[i] << '\n';
            else cout << log[i] << ' ';
        }
        cout << cut.size() << '\n';
        if(cut.size()!=0){
            for(int ff:cut){
                cout << ff << ' ';
            }
        }

        return 0;
    }