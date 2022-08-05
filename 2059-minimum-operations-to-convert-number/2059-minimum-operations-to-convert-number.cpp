class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        unordered_map<int, int> mp;
        queue<int> q;
        q.push(start);
        int ans=0;
        
        while(q.empty()==false){
            int count=q.size();
            while(count--){
                int v=q.front();
                q.pop();
                if(v==goal)return ans;
                if(v<0 || v>1000 || mp.find(v)!=mp.end()){
                    continue;
                }
                mp[v]++;
                for(int i=0;i<nums.size();i++){
                    int a=nums[i]+v;
                    int b=v-nums[i];
                    int c=nums[i]^v;
                    q.push(a);
                    q.push(b);
                    q.push(c);
                }
            }
            ans++;
        }
        return -1;
    }
};