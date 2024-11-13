#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, total = 0;
    long long count = 0;
    int ma = 0;
    long long n, m, k = -1;
    string s1, s2;
    int j;
    cin >> n;
    for(int i=0;i<n;i++){
        count = 0;
        int x=0, y=0;
        cin >> a >> b >> c;
        cin >> s1;
        for(int k=0;k<=100;k++){
            for(int j=0;j<a;j++){
                if(s1[j]=='N')y++;
                else if(s1[j]=='E')x++;
                else if(s1[j]=='S')y--;
                else if(s1[j]=='W')x--;
                if(x==b && y==c){
                    count = 1;
                    break;
                }
            }
            if(count > 0)break;
        }
        if(count ==1){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    
    return 0;
}