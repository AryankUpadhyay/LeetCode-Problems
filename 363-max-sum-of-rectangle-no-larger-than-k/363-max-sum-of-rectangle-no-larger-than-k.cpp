class Solution {
public:
    int maxPresum(int a[], int n, int mx_sum){
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int presum=0;
            for(int j=i;j<n;j++){
                presum+=a[j];
                if(presum<=mx_sum){
                    ans=max(ans, presum);
                }
            }
        }
        return ans;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M, int mx_sum) {
        // code here
        for(int i=0;i<R;i++){
            for(int j=1;j<C;j++){
                M[i][j]=M[i][j-1]+M[i][j];
            }
        }
        int sum=INT_MIN;
        for(int i=0;i<C;i++){
            int a[R];
            for(int j=0;j<R;j++){
                a[j]=M[j][i];
            }
            sum=max(sum, maxPresum(a, R, mx_sum));
            for(int k=0;k<i;k++){
            for(int j=0;j<R;j++){
                a[j]=M[j][i]-M[j][k];
            }
            sum=max(sum, maxPresum(a, R, mx_sum));
            }
        }
        return sum;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r=matrix.size();
        int c=matrix[0].size();
        return maximumSumRectangle(r, c, matrix, k);
    }
};