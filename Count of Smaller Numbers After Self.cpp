PROBLEM :
VIDEO :

/*
  BRUTE FORCE
  TC:O(N^2)
  SC:
*/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j])cnt++;
            }
            result[i]=cnt;
        }

        return result;
    }
};
