class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m= maze.size();
        int n =maze[0].size();

        queue<pair<int,int>>q;

        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';

        int steps=0;
        int dr[4]={-1,+1,0,0};
        int dc[4]={0,0,-1,+1};

        while (!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();

                int r=curr.first;
                int c=curr.second;

                if((r==0||r==m-1||c==0||c==n-1)&&!(r==entrance[0]&& c==entrance[1])){
                    return steps;
                }

                for(int i=0; i<4; i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];

                    if(nr>=0&& nc>=0 && nr<m &&nc<n && maze[nr][nc]=='.'){
                        maze[nr][nc]='+';
                        q.push({nr,nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
