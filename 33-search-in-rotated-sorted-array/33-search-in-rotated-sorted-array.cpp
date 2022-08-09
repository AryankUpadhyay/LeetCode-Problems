class Solution {
public:
    
    int BinSearch(vector<int> A, int l , int r, int B){
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(A[mid]==B){
            return mid;
        }
        else if(A[mid]>B){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
    int BinSearch2(vector<int> A, int l , int r, int B){
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(A[mid]==B){
            return mid;
        }
        else if(A[mid]<B){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

    
    
    int search(vector<int>& A, int B) {
    int l=0;
    int r=A.size()-1;
    int ind=0;
        if(A.size()==2){
            if(A[0]==B){
                return 0;
            }
            if(A[1]==B){
                return 1;
            }
        }
    while(l<r){
        int mid=(l+r)/2;
        //cout<<mid<<" "<<A[mid]<<endl;
        if(mid!=0 && mid!=A.size()-1 && A[mid+1]>A[mid] && A[mid-1]>A[mid]){
            ind=mid;
            break;
        }
        else if(A[l]<A[mid]){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    if(A.size()!=1 && (A[A.size()-1]<A[A.size()-2])){
            ind=A.size()-1;
    }
    cout<<"ind=> "<<ind<<endl;
    int v1=BinSearch(A, 0, ind-1, B);
    int v2=BinSearch(A, ind, A.size()-1, B);
    int ans=max(v1, v2);
    return ans;
    }
};