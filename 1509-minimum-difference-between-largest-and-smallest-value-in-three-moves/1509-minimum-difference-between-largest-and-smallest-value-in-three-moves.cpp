class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int k=nums.size()-4;
        int ans =nums[k]-nums[0];
        for(int i=0;i<nums.size()-k;i++){
            ans=min(ans, nums[i+k]-nums[i]);
        }
        return ans;
    }
};