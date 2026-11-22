class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& c) {
        int i = 0, j = 0;
        for(int k = 0; k < c.size(); k++){
            if(c[k]=="RIGHT") j++;
            else if(c[k]=="LEFT") j--;
            else if(c[k]=="DOWN") i++;
            else i--;
        }
        return i*n + j;
    }
};