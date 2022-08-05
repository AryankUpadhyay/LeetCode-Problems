class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        unsigned long long dp[target+1][n+1];
        for(int i=0;i<n+1;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<target+1;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<target+1;i++){
            for(int j=1;j<n+1;j++){
                //cout<<i<<" "<<j<<endl;
                dp[i][j]=dp[i][j-1];
                if(nums[j-1]<=i){
                    dp[i][j]=dp[i][j] + dp[i-nums[j-1]][n];
                }
            }
        }
        return dp[target][n];
    }
};