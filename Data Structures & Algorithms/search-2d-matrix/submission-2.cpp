class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1;
        int lowc = 0, highc = matrix[0].size() - 1;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (matrix[mid][lowc] <= target && matrix[mid][highc] >= target) {
                while (lowc <= highc) {
                    int midc = (highc + lowc) / 2;
                    if (matrix[mid][midc] == target)
                        return true;
                    if (matrix[mid][midc] > target)
                        highc = midc - 1;
                    if (matrix[mid][midc] < target)
                        lowc = midc + 1;
                }
            }
            if (matrix[mid][lowc] < target && matrix[mid][highc] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
