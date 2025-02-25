#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;
    int n, m, t;
    int total=0;
    vector<int> v(501, 0);
    v[1]=1;
    v[2]=3;
    v[3]=5;
    v[6]=6;
    v[7]=10;
    v[14]=11;
    v[17]=20;
    v[19]=22;
    v[23]=26;
    v[29]=32;
    v[47]=50;
    v[59]=62;
    v[61]=64;
    v[97]=100;
    v[109]=112;
    v[113]=116;
    v[131]=134;
    v[149]=152;
    v[167]=170;
    v[179]=182;
    v[181]=184;
    v[193]=196;
    v[223]=226;
    v[229]=232;
    v[233]=236;
    v[257]=260;
    v[263]=266;
    v[269]=272;
    v[289]=276;
    v[313]=316;
    v[337]=340;
    v[361]=346;
    v[367]=370;
    v[379]=382;
    v[383]=386;
    v[389]=392;
    v[419]=422;
    v[433]=436;
    v[461]=464;
    v[487]=490;
    v[491]=494;
    v[499]=502;
    for(int i=1;i<=500;i++){
        if(v[i]==0)v[i]=v[i-1];
    }
    //https://oeis.org/A051626/b051626.txt
    while(1){
        cin >> n;
        if(n==0)break;
        cout << v[n] << '\n';
    }
    

    return 0;
}