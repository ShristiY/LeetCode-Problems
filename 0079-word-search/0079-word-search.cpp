class Solution {
public:
    bool func(vector<vector<char>>&board, string word, int i, int j, int n, int m, int index)
    {
        if(index==word.size())
            return true;
        if(i<0 || i>n-1 || j<0 || j>m-1) return false;
        if(board[i][j]!=word[index]) return false;
        
        char temp=board[i][j];
        board[i][j]='*';
        bool found= func(board,word,i+1,j,n,m,index+1) ||func(board,word,i-1,j,n,m,index+1) ||func(board,word,i,j+1,n,m,index+1) ||func(board,word,i,j-1,n,m,index+1);
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(func(board,word,i,j,n,m,0))
                    return true;
            }
        }
        return false;
    }
};