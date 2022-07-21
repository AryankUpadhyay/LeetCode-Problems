class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k==0 || k==1){
            return s.length();
        }
        if(k>s.length()){
            return 0;
        }
        unordered_map<char, int> counts;
        for(int i=0;i<s.length();i++){
            counts[s.at(i)]++;
        }
        for(int i=0;i<s.length();i++){
            if(counts[s.at(i)]<k){
                string s1=s.substr(0, i);
                string s2=s.substr(i+1);
                return max(longestSubstring(s1, k), longestSubstring(s2, k));
            }
        }
        return s.length();
    }
};