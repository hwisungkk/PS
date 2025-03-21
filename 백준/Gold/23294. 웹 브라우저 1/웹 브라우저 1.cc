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
        int mx_cash;
        char ch;
        cin >> n >> m >> mx_cash;
        vector<int>cash(n+1);
        for(int i=1;i<=n;i++){
            cin >> cash[i];
        }
        deque<int> back;
        stack<int> back2;
        stack<int> front;
        int cur=0;
        for(int i=0;i<m;i++){
            cin >> ch;
            if(ch=='B'){
                if(!back.empty()){
                    front.push(cur);
                    cur = back.back();
                    back.pop_back();
                }
            }
            else if(ch=='F'){
                if(!front.empty()){
                    back.push_back(cur);
                    cur = front.top();
                    front.pop();
                }
            }
            else if(ch=='A'){
                cin >> t;
                if(cur!=0){
                    back.push_back(cur);
                }
                cur=t;
                mx_cash -= cash[t];
                while(!front.empty()){
                    mx_cash+=cash[front.top()];
                    front.pop();
                }
                while(mx_cash<0){
                    mx_cash += cash[back.front()];
                    back.pop_front();
                }
            }
            else if(ch=='C'){
                while(!back.empty()){
                    a = back.back();
                    back.pop_back();
                    if(back2.empty())back2.push(a);
                    else {
                        if(back2.top()!=a){
                            back2.push(a);
                        }
                        else{
                            mx_cash+=cash[a];
                        }
                    }
                }
                while(!back2.empty()){
                    a = back2.top();
                    back2.pop();
                    back.push_back(a);
                }
            }
        }
        cout << cur << '\n';
        if(back.empty())cout << "-1\n";
        else{
            while(!back.empty()){
                if(back.size()==1) cout << back.back() << '\n';
                else cout << back.back() << ' ';
                back.pop_back();
            }
        }
        if(front.empty())cout << "-1\n";
        else{
            while(!front.empty()){
                if(front.size()==1) cout << front.top() << '\n';
                else cout << front.top() << ' ';
                front.pop();
            }
        }

        return 0;
    }