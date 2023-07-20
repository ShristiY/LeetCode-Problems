class Solution {
public:
    void func(vector<vector<string>>&ans,vector<string>&board,int n, int col,vector<int>&left,vector<int>&upDiagonal,vector<int>&downDiagonal)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(left[row]==0 && upDiagonal[row+col]==0 && downDiagonal[n-1+(col-row)]==0)
            {
                board[row][col]='Q';
                left[row]=1;
                upDiagonal[row+col]=1;
                downDiagonal[(n-1)+(col-row)]=1;
                func(ans,board,n,col+1,left,upDiagonal,downDiagonal);
                board[row][col]='.';
                left[row]=0;
                upDiagonal[row+col]=0;
                downDiagonal[(n-1)+(col-row)]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        vector<int>left(n,0);
        vector<int>upDiagonal(2*n-1,0);
        vector<int>downDiagonal(2*n-1,0);
        for(int i=0;i<n;i++)
            board[i]=s;
        func(ans,board,n,0,left,upDiagonal,downDiagonal);
        return ans;
    }
};