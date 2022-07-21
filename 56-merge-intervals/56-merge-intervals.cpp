class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int , int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            pq.push({intervals[i][0], intervals[i][1]});
        }
        
        while(pq.empty()==false){
            int start=pq.top().first;
            int end=pq.top().second;
            pq.pop();
            while(pq.empty()==false && pq.top().first<=end){
                end=max(pq.top().second, end);
                pq.pop();
            }
            vector<int> vv;
            vv.push_back(start);
            vv.push_back(end);
            ans.push_back(vv);
        }
        return ans;
    }
};