class Solution {
public:
    bool check(int mid, vector<int> A, int B){
    if(mid==0){
        return false;
    }
    int total=0;
    int days=1;
    for(int i=0;i<A.size();i++){
        if(A[i]>mid){
            return false;
        }
        if(total+A[i]<=mid){
            total=total+A[i];
        }
        else{
            total=A[i];
            days++;
        }
    }
    if(days<=B){
        return true;
    }
    return false;
}
    
    
    int shipWithinDays(vector<int>& A, int B) {
        int l=1;
    int r=0;
    for(int i=0;i<A.size();i++){
        r=r+A[i];
    }
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid, A, B)==true && check(mid-1, A, B)==false){
            return mid;
        }
        else if(check(mid, A, B)==true){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return l;
    }
};