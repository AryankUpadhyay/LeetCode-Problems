class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>>mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }
        for(auto x:mp){
            for( int dia=mp[x.first].size()-1;dia>=0;dia--){
                ans.push_back(mp[x.first][dia]);
            }
        }
        return ans;
    }
};