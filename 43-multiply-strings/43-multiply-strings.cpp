class Solution {
public:
    string CharMultiply(string s, char ch){
        string p="";
        int carry=0;
        //cout<<"string=> "<<s<<" char=> "<<ch<<endl;
        for(int i=s.length()-1;i>=0;i--){
            int pro=((s.at(i)-48)*(ch-48))+carry;
            carry=(pro/10);
            int sum=pro%10;
            p=to_string(sum)+p;
            //cout<<"pro=> "<<pro<<" "<<carry<<" "<<p<<endl;
        }
        if(carry!=0){
            p=to_string(carry)+p;
        }
        return p;
    }
    string Add(string a, string b){
        string ans="";
        //cout<<"addition-> of=>"<<a<<" and=> "<<b<<endl;
        reverse(a.begin(), a.end());
        reverse(b. begin(), b.end());
        int carry=0;
        for(int i=0;i<max(a.size(), b.size());i++){
            int sum=carry;
            if(i<a.size()){
                sum=sum+a.at(i)-48;
            }
            if(i<b.size()){
                sum=sum+b.at(i)-48;
            }
            carry=sum/10;
            sum=sum%10;
            ans=ans+to_string(sum);
        }
        if(carry!=0)
        ans=ans+to_string(carry);
        reverse(ans.begin(), ans.end());
        //cout<<"addition=> "<< ans<<endl;
        return ans;
    }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        vector<string> vec;
        reverse(num1.begin(), num1.end());
        string space="";
        for(int i=0;i<=num1.length()-1 ;i++){
        string product=CharMultiply(num2, num1.at(i));  
            product=product+space;
            vec.push_back(product);
          //  cout<<"product=> "<<product<<endl;
            space=space+"0";
        }
        string ans=vec[vec.size()-1];
        for(int i=0;i<vec.size()-1;i++){
            ans=Add(ans, vec[i]);
        }
        return ans;
        
    }
    
};