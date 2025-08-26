class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
        int max_area=1;
        int max_diagonal=1;
        for(auto dim:dimensions)
        {
            int diagonal= dim[0]*dim[0] + dim[1]*dim[1];
            if(diagonal>max_diagonal)
            {
                max_diagonal=diagonal;
                max_area=dim[0]*dim[1];
            }
            else if(diagonal==max_diagonal)
            {
                if(dim[0]*dim[1]>max_area)
                {
                    max_area=dim[0]*dim[1];
                }
            }
        }
        return max_area;
    }
};