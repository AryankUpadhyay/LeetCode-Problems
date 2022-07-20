class Solution {
public:
    
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int mx=INT_MIN;
        int total_sum=0;
        for(int i=0;i<nums.size();i++){
            mx=max(mx, nums[i]);
            total_sum=total_sum+nums[i];
        }
        int arr[mx+1], presum[mx+1];
        memset(arr, 0, sizeof(arr));
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        presum[0]=0;
        int total=0;
        int res[mx+1];
        res[0]=0;
        for(int i=1;i<mx+1;i++){
            presum[i]=presum[i-1]+arr[i]*i;
            total=total+arr[i];
            res[i]=total*i-presum[i] + (total_sum-presum[i])-(nums.size()-total)*i;
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(res[nums[i]]);
        }
        return ans;
    }
};