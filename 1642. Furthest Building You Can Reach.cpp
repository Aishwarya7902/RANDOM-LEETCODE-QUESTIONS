/*
 BRUTE FORCE (gives tle)
 USING RECURSION
*/


class Solution {
public:
    int n;
    int solve(vector<int>& height,int indx, int brick, int ladder){
       if(indx==n-1)return 0;
       
       if(height[indx+1]<=height[indx]){
           return 1+solve(height,indx+1,brick,ladder);
       }

       else{ // we explore by brick or ladder
             int byBrick=0;
             int byLadder=0;

             int diff=height[indx+1]-height[indx];

             if(brick>=diff){
                 byBrick=1+solve(height,indx+1,brick-diff,ladder);
             }

             if(ladder>0){
                 byLadder=1+solve(height,indx+1,brick,ladder-1);
             }

             return max(byBrick,byLadder);
       }

       return -1;

    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
     n=heights.size();
     return solve(heights,0,bricks,ladders);    
    }
};

/*
MEMOIZATION
GIVES (MLE)
*/

class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(vector<int>& height,int indx, int brick, int ladder){
       if(indx==n-1)return 0;
       if(dp[brick][ladder]!=-1)return dp[brick][ladder];
       
       if(height[indx+1]<=height[indx]){
           return dp[brick][ladder]=1+solve(height,indx+1,brick,ladder);
       }

       else{ // we explore by brick or ladder
             int byBrick=0;
             int byLadder=0;


             int diff=height[indx+1]-height[indx];

             if(brick>=diff){
                 byBrick=1+solve(height,indx+1,brick-diff,ladder);
             }

             if(ladder>0){
                 byLadder=1+solve(height,indx+1,brick,ladder-1);
             }

             return dp[brick][ladder]=max(byBrick,byLadder);
       }

       return -1;

    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
     n=heights.size();
     dp=vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1));
     return solve(heights,0,bricks,ladders);    
    }
};
