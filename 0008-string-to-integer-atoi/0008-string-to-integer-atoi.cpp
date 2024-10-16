class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]==' ') i++;
        bool pos=true;
        if(s[i]=='-'){
            pos=false;
            i++;
        }else if(s[i]=='+'){
            i++;
        }
        int ans=0;
        while(i<n && s[i]>='0' && s[i]<='9'){
              int dig=s[i]-'0';
              if(ans>INT_MAX/10 || (ans==INT_MAX/10 && dig>INT_MAX%10)){
                return (pos==true)?INT_MAX:INT_MIN;
              }
              ans=ans*10+dig;
              i++;
        }
        
        return (pos==true)?ans:-ans;
    }
};