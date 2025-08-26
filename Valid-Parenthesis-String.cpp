class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int low = 0, high = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                low++;
                high++;
            }
            else if(s[i] == ')'){
                if(low > 0) low--;  // use one '(' if possible
                high--;
            }
            else { // '*'
                if(low > 0) low--;  // treat as ')'
                high++;             // or treat as '('
            }
            if(high < 0) return false;  // too many ')'
        }
        return low == 0;
    }
};