class Solution {
public:

    void solve(int col, 
               vector<string> board,
               vector<vector<string>>& ans,
               vector<int>& lrow,
               vector<int>&updigonal,
               vector<int>&lrdigonal,
               int n){

                if (col==n){
                    ans.push_back(board);
                    return;

                }
                for(int row=0; row<n; row++){
                    if(lrow[row]==0&&lrdigonal[n-1+col-row]==0&& updigonal[row+col]==0){
                        board[row][col]='Q';

                        lrow[row]=1;
                        lrdigonal[n-1+col-row]=1;
                        updigonal[row+col]=1;


                        solve(col+1,board,ans,lrow,updigonal,lrdigonal,n);

                        board[row][col]='.';
                        lrow[row]=0;
                        lrdigonal[n-1+col-row]=0;
                        updigonal[row+col]=0;
                    }
                }

               }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n,'.');

        for(int i=0; i<n; i++)
            board[i]=s;

       vector<int> lrow(n,0);
       vector<int> updigonal(2*n-1,0);
       vector<int>  lrdigonal(2*n-1,0);  
       solve(0,board,ans,lrow,updigonal,lrdigonal,n);
       
       return ans;
    }
};