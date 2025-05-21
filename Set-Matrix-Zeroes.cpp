class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Flags to remember if first row or first col had 0
        bool firstRow = false, firstCol = false;

        // Step 1: Check if first col needs to be zero
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) firstCol = true;
        }

        // Step 2: Check if first row needs to be zero
        for(int j = 0; j < n; j++) {
            if(matrix[0][j] == 0) firstRow = true;
        }

        // Step 3: Mark rows and cols (excluding first row and col)
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 4: Set 0 based on markers
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Set first row to 0 if needed
        if(firstRow) {
            for(int j = 0; j < n; j++) matrix[0][j] = 0;
        }

        // Step 6: Set first col to 0 if needed
        if(firstCol) {
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};
