class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int i=0, j= v[0].size()-1;
        while(i<v.size() && j>=0){
            if(v[i][j]>target){
                j--;
            }
            else if(v[i][j]<target){
                i++;
            }
            else{
                return true;
            }  
        }

        return false;
    }
};