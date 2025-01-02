#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
long long maxi=0;
int n;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, m, k;
    int t;

    cin >> n;
    string s;
    for(int i=0;i<n;i++){
        int count=0;
        int che=0;
        cin >> s;
        s+=' ';
        s+=' ';
        for(int j=0;j<s.size();j++){
            if(s[j]=='@'){
                s[j]='a';
                count++;
            }
            else if(s[j]=='['){
                s[j]='c';
                count++;
            }
            else if(s[j]=='!'){
                s[j]='i';
                count++;
            }
            else if(s[j]==';'){
                s[j]='j';
                count++;
            }
            else if(s[j]=='^'){
                s[j]='n';
                count++;
            }
            else if(s[j]=='0'){
                s[j]='o';
                count++;
            }
            else if(s[j]=='7'){
                s[j]='t';
                count++;
            }
            else if(s[j]=='\\'){
                if(s[j+1]=='\''){
                    s[j]='v';
                    s[j+1]=' ';
                    j++;
                    count++;
                }
                else if(s[j+1]=='\\'){
                    if(s[j+2]=='\''){
                        s[j]='w';
                        s[j+1]=' ';
                        s[j+2]=' ';
                        j+=2;
                        count++;
                    }
                }
            }
            else if(s[j]==' ')continue;
            else che++;
        }
        if(che<=count) cout << "I don't understand\n";
        else {
            for(int j=0;j<s.size();j++){
                if(s[j]==' ')continue;
                else cout << s[j];
            }cout<<'\n';
        }
    }
    return 0;
}
