class Solution {
public:
    int minOperations(int n) {
        vector<int> vec;
        int ans=0;
        for(int i=0;i<n;i++){
            vec.push_back(i*2+1);
            if(vec[i]>=n){
                ans=ans+(vec[i]-n);
            }
        }
        return ans;
    }
};