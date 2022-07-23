#define front top
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> st;
        for(int i=0;i<points.size();i++){
            st.push(make_pair(points[i][0], points[i][1]));
        }
        int count=1;
        int start=st.top().first;
        int end=st.front().second;
        st.pop();
        while(st.empty()==false){
            if(st.front().first<=end){
                end=min(end, st.front().second);
            }
            else{
                start=st.front().first;
                end=st.front().second;
                count++;
            }
            st.pop();
        }
        return count;
    }
};