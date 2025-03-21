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
        
        cin >> n >> m;
        cin >> a >> b; //킹 좌표
        int check[3][3]={0};

        for(int i=0;i<m;i++){
            cin >> c >> d;
            if(a-1<=c && c<=a+1){
                for(int j=0;j<=2;j++){
                    check[c-a+1][j]=1;
                }
            }
            if(b-1<=d && d<=b+1){
                for(int j=0;j<=2;j++){
                    check[j][d-b+1]=1;
                }
            }
            int dx[9]={-1,-1,-1,0,0,0,1,1,1};
            int dy[9]={-1,0,1,-1,0,1,-1,0,1};
            for(int j=0;j<9;j++){
                if((c-(a+dx[j]))==d-(b+dy[j])){
                    check[1+dx[j]][1+dy[j]]=1;
                }
                if((c-(a+dx[j]))==-1*(d-(b+dy[j]))){
                    check[1+dx[j]][1+dy[j]]=1;
                }
            }

        }
        for(int i=-1;i<=1;i++){ //끝자락 확인
            for(int j=-1;j<=1;j++){
                if(a+i<1 || a+i>n || b+j<1 || b+j>n)check[1+i][1+j]=1;
            }
        }
        
        bool flag=check[1][1];
        int cnt=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(check[i][j])cnt++;
                //cout << check[i][j] << ' ';
            }//cout << '\n';
        }
        if(flag){
            if(cnt==9)cout<<"CHECKMATE\n";
            else cout << "CHECK\n";
        }
        else{
            if(cnt==8)cout<<"STALEMATE\n";
            else cout << "NONE\n";
        }
        return 0;
    }