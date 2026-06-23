class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> mpp;
        int n = nums.size();
        for(int i =0;i<n;i++ ){
            int num= nums[i];
            int moreNeed= target-num;
            if(mpp.find(moreNeed) != mpp.end()){
                return {mpp[moreNeed] , i};
            }
            mpp[num] =i;
        }
        return {-1,-1};
        
        
    }
};