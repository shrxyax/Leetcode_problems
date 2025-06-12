class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        string s = \\;
        int f=1;
        for (int i = 1; i < n; i++)
        {
            f=f*i;
            num.push_back(i);
        }
        num.push_back(n);

        k--;
        while(true)
        {
            int index=k/f;
            s+=to_string(num[index]);
            num.erase(num.begin()+index);
            if(num.empty()) break;
            k=k%f;
            f=f/num.size();
        }
        return s;
    }
};

//s += (num[index] + '0');
//This is shorthand for:

//s = s + (char)(num[index] + '0');