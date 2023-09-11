class Solution {
public:
    
    
//     bool dfs(int i,int j,vector<vector<char>>&board,string &word,int k,vector<vector<int>>&dp){
        
        
//         if(k==word.size()){
//             //SIUU
//             return true;
//         }
        
//         if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[k] || dp[i][j]==1){
//             return false;
//         }
       
//         dp[i][j]=1; //Visited
        
//         bool x=dfs(i+1,j,board,word,k+1,dp);
//         bool y=dfs(i-1,j,board,word,k+1,dp);
//         bool z=dfs(i,j+1,board,word,k+1,dp);
//         bool a=dfs(i,j-1,board,word,k+1,dp);
        
//         if(x || y || z || a){
//             return true;
//         }
        
//         dp[j][j]=0;
        
//         return false;
        
       
//     }
    
    
bool dfs(int i,int j,vector<vector<char>>&board,string &word,int k,int n,int m,vector<vector<int>>&visited){
    if(k==word.size()){
        return true;
    }
    if(i<0 || i>=n || j<0 || j>=m || board[i][j]!=word[k] || visited[i][j]==1){
        return false;
    }

    //Check all 4 routes siu
    //I have to mark myself as Unvisited also OOH big brain
    //Try out all possibilities if doenst work then GG g bEck

    visited[i][j]=1;
    bool x=dfs(i-1,j,board,word,k+1,n,m,visited);
    bool y=dfs(i+1,j,board,word,k+1,n,m,visited);
    bool z=dfs(i,j-1,board,word,k+1,n,m,visited);
    bool b=dfs(i,j+1,board,word,k+1,n,m,visited);

    if(x || y || z || b){
        return true;
    }
    visited[i][j]=0;
    return false;

}
    
    bool exist(vector<vector<char>>& board, string word) {
        //So we have to make sure of the basic backtracking process do the possibilites then backtrack and undo it
        //Same char can be used in a different way in another dfs call so we have to big brain and unmark it siu
        
        //DFS + Backtracking
        int n=board.size();
        int m=board[0].size();
        
       
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==word[0]){
                    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
                    if(dfs(i,j,board,word,0,n,m,dp)==1){
                        return true;
                    }
                    
                }
            }
        }
        
        //sed 
        return false;
    }
};