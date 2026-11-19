class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, mid = 0, high = matrix.size() - 1;
        int lowc = 0, midc = 0, highc = matrix[0].size() - 1;
        while (low <= high) {
            mid = (high + low) / 2;
            if (matrix[mid][lowc] <= target && matrix[mid][highc] >= target) {
                while (lowc <= highc) {
                    midc = (highc + lowc) / 2;
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
