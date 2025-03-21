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
        cin >> n >> m;
        stack<int> back;
        stack<int> back2;
        stack<int> front;
        int cur=0;
        for(int i=0;i<m;i++){
            cin >> ch;
            if(ch=='B'){
                if(!back.empty()){
                    front.push(cur);
                    cur = back.top();
                    back.pop();
                }
            }
            else if(ch=='F'){
                if(!front.empty()){
                    back.push(cur);
                    cur = front.top();
                    front.pop();
                }
            }
            else if(ch=='A'){
                cin >> t;
                if(cur!=0){
                    back.push(cur);
                }
                cur=t; 
                while(!front.empty()){
                    front.pop();
                }
            }
            else if(ch=='C'){
                while(!back.empty()){
                    a = back.top();
                    back.pop();
                    if(back2.empty())back2.push(a);
                    else {
                        if(back2.top()!=a){
                            back2.push(a);
                        }
                    }
                }
                while(!back2.empty()){
                    a = back2.top();
                    back2.pop();
                    back.push(a);
                }
            }
        }
        cout << cur << '\n';
        if(back.empty())cout << "-1\n";
        else{
            while(!back.empty()){
                if(back.size()==1) cout << back.top() << '\n';
                else cout << back.top() << ' ';
                back.pop();
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