class Solution {
public:
    int dis(vector<int> p1, vector<int> p2)
    {
        return (((p2[0] - p1[0]) * (p2[0] - p1[0])) + ((p2[1] - p1[1]) * (p2[1] - p1[1])));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
         vector<vector<int>> v = {p1, p2, p3, p4};
        set<int> st;
        for(int i = 0 ; i < 4; i++)
        {
            for(int j = i + 1; j < 4; j++)
            {
             
                if(dis(v[i], v[j]) != 0)st.insert(dis(v[i], v[j]));
                else return false;
            }
        }
        return st.size() == 2;
    }
};
