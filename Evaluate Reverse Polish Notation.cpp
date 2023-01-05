class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            int x,y;
            if(tokens[i]=="/")
            {
              x=st.top();
              st.pop();
              y=st.top();
              st.pop();
              st.push(y/x);
            }
            else if(tokens[i]=="+")
            {
                x=st.top();
              st.pop();
              y=st.top();
              st.pop();
              st.push(y+x);
            }
            else if(tokens[i]=="-")
            {
                x=st.top();
              st.pop();
              y=st.top();
              st.pop();
              st.push(y-x);
            }
            else if(tokens[i]=="*")
            {
                x=st.top();
              st.pop();
              y=st.top();
              st.pop();
              st.push(y*x);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
