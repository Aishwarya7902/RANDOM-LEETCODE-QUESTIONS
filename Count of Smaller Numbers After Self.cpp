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

/*

OPTIMISATION
USING MERGE SORT
*/

class Solution {
public:
    void merge(vector<int>&count,vector<pair<int,int>>&v,int left,int mid,int right){
     vector<pair<int,int>>temp(right-left+1);
      int i=left;
      int j=mid+1;
      int k=0;
        while(i<=mid && j<=right){
            if(v[i].first<=v[j].first){
                temp[k++]=v[j++];
            }
            else{
                count[v[i].second]+=right-j+1;
                temp[k++]=v[i++];
            }
            
        }
        while(i<=mid){
          temp[k++]=v[i++];  
        }
        while(j<=right){
          temp[k++]=v[j++];  
        }
        for(int a=0,b=left;a<right-left+1;b++,a++){
            v[b]=temp[a];
        }
    }
    
    
    void mergeSort(vector<int>&count,vector<pair<int,int>>&v,int left,int right){
        if(left>=right)
            return;
        int mid=left+(right-left)/2;
        mergeSort(count,v,left,mid);
        mergeSort(count,v,mid+1,right);
        merge(count,v,left,mid,right);
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
     vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            pair<int,int>p;
            p.first=nums[i];
            p.second=i;
            v[i]=p;
        }
        vector<int>count(n,0);
        mergeSort(count,v,0,n-1);
        return count;
            
    }
};
