
class Solution {
public:
    int kthSmallest(vector<string> nums , int k){
        vector<pair<string, int>> vv;
        
        for(int i=0;i<nums.size();i++){
            vv.push_back(make_pair(nums[i],i));
            
        }
        sort(vv.begin(), vv.end());
        return vv[k-1].second;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            vector<string> pp;
            for(int j=0;j<nums.size();j++){
                pp.push_back(nums[j].substr(nums[j].length()-queries[i][1]));
            }
            ans[i]=kthSmallest(pp, queries[i][0]);
        }
        return ans;
    }
};