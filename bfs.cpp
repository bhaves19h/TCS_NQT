#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char grid[21][21];
int n,m;

struct cell{
    int x , y;
};

bool isValid(int x, int y){
    return (x>=0 && x<n && y<m && y>=0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if(!(cin>>n>>m))return 0;
    int x ,y;
    cin>>x>>y;
    x--,y--;
    
    for(int i=0 ; i<n ; i++){
        for(int j = 0 ; j<n ;j++){
            cin>>grid[i][j];
            }
    }
    
    int dx[] = {-1,-1,-1,0 ,0, 1,1,1};
    int dy[] = {-1,0,1,-1,1, -1,0,1};
    
    queue<cell>q;
    
    grid[x][y] = 'X';
    q.push({x,y});
   
    int cnt = 0;
    
    while(!q.empty()){
        int lens = q.size();
        bool expand = false;
        for(int i = 0 ; i<lens ; i++){
            cell curr = q.front();
            q.pop();
            for(int d= 0 ; d<8 ;  d++){
                int nx=  curr.x + dx[d];
                int ny = curr.y + dy[d];
                
                if(isValid(nx,ny) && grid[nx][ny] =='T'){
                    grid[nx][ny] = 'X';
                    q.push({nx,ny});
                    expand = true;
                    }
                
                }
            }
        if(expand)cnt++;
        }
    
cout<<cnt;
    return 0;
    };

