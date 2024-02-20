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


/*

MOST OPTIMISED AND ACCEPTED SOLUTION
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
     int n=heights.size();

     priority_queue<int>pq;
     int i=0;
     for(;i<n-1;i++){
         if(heights[i+1]<heights[i])continue;

         int diff=heights[i+1]-heights[i];

         if(bricks>=diff){ //agar brick hai to use kar lo ....aage apni galti sudhar sakte ho
           bricks-=diff;
           pq.push(diff);
         }

         else if(ladders>0){
             if(!pq.empty()){
                 int max_brick_past=pq.top();
                 if(max_brick_past>diff){
                     pq.pop();
                     bricks+=max_brick_past;
                     bricks-=diff;
                     pq.push(diff);
                     ladders--;
                 }
                 else{
                     ladders--;
                 }
             }

             else{
                 ladders--;
             }
         }
         else{
             break;
         }
     }
       return i;
    }
};
