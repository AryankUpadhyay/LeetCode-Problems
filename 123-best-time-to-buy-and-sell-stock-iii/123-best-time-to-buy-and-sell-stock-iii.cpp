class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
       int FirstBuy[n];
        int SecondBuy[n];
        int res=0;
        int mn=INT_MAX;
        int mx=0;
        for(int i=0;i<n;i++){
            mn=min(mn, prices[i]);
            res=max(res, prices[i]-mn);
            FirstBuy[i]=res;
            //cout<<res<<" ";
        }
        //cout<<endl;
        res=0;
        for(int i=n-1;i>=0;i--){
            mx=max(mx, prices[i]);
            res=max(res, mx-prices[i]);
            SecondBuy[i]=res;
        }
        // for(int i=0;i<n;i++){
        //     cout<<SecondBuy[i]<<" ";
        // }
        // cout<<endl;
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans, FirstBuy[i]+SecondBuy[i]);
        }
        return ans;
    }
};