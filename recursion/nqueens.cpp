class Solution {
public:
 
    bool safe(vector<int> &v,int row,int col){
        for(int i=0;i<row;i++){        //check if queen exists in that column
            if(v[i]==col){
                return false;
            }
        }
        for ( int i=1; i<=row; i++ )  //check if queen exists diagonally
             if (v[row-i] == col-i  )
                return false;
         for ( int i=1; i<=row; i++ ) // //check if queen exists antidiagonally
             if (v[row-i] == col+i  )
                return false;
        return true;
                
    }
    void solve(vector<int> &v,int row,int &cnt){
        int n=v.size();
        for(int i=0;i<n;i++){
            if(safe(v,row,i)){
                v[row]=i;
                if ( row+1 == n ) cnt++;
                else solve(v,row+1,cnt);
            }   
        }
            
        
        
    }
    int totalNQueens(int n) {
        vector<int> v(n,-1);
        int cnt=0;
        solve(v,0,cnt);
        return cnt;
    }
};
