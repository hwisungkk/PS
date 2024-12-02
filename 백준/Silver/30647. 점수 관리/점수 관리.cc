#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int al = 0;
int dis[51][51]={0};
int main()
{
    ios_base ::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    long long a, b, c, total = 0;
    long long n, k = -1;
    int m;
    int t;
    string s1, s2;
    cin >> n;
    vector <tuple<int, string, int>> v;
    for(int i=0;i<n;i++){
        cin >> s1;
        int j;
        for(j=0;s1[j]!=':';j++);
        string name = "";
        j+=2;
        for(j;s1[j]!=',';j++){
            name+=s1[j];
        }name.pop_back();

        for(j;s1[j]!=':';j++);
        j++;
        string temp="";
        int score;
        for(j;s1[j]!=',';j++){
            temp+=s1[j];
        }score=stoi(temp);

        for(j;s1[j]!=':';j++);
        j++;
        int hidden = s1[j]-48;

        v.push_back({score, name, hidden});
    }
    sort(v.begin(),v.end(), [](const tuple<int, string, int>& a, const tuple<int, string, int>& b){
        if (get<0>(a) == get<0>(b)) {
            return get<1>(a) < get<1>(b);
        }
        return get<0>(a) > get<0>(b);
    });
    for(int i=0;i<v.size();i++){
        int rank=1;
        for(int j=0;j<i;j++){
            if(get<0>(v[i])<get<0>(v[j]))rank++;
        }
        if(!get<2>(v[i]))
            cout << rank << ' ' << get<1>(v[i]) << ' ' << get<0>(v[i]) << '\n'; 
    }
    
    return 0;
}