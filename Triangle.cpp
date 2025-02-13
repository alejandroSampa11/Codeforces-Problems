class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1){
            return triangle[0][0];
        }
        for(int i = 1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0){
                    triangle[i][j]+=triangle[i-1][j];
                }
                else if(j==triangle[i].size()-1){
                    triangle[i][j]+=triangle[i-1][triangle[i-1].size()-1];
                }else{
                    triangle[i][j]+=min(triangle[i-1][j-1], triangle[i-1][j]);
                }
            }
        }

        for(int i = 0;i<triangle.size();i++){
            for(int j= 0;j<triangle[i].size();j++){
                cout<<triangle[i][j]<<" ";
            }
            cout<<""<<endl;
        }
        int minimo = *min_element(triangle[triangle.size()-1].begin(),triangle[triangle.size()-1].end());
        return minimo;
    }
};