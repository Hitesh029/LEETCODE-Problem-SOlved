class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
          stack<int> st;
          for(int a: asteroids){
            bool alive=true;
            while(alive && !st.empty() && st.top()>0 && a<0){
                if(abs(a)>st.top()){
                    st.pop();
                }

                else if(abs(a)==st.top())
                {
                    st.pop();
                    alive=false;
                }
                else{
                    alive=false;
                }
            }
            if(alive){
                st.push(a);
            }
          }


          vector<int> ans(st.size());
          for(int i =st.size()-1; i>=0; i--){
            ans[i]=st.top();
            st.pop();
          } 
          return ans;
    }
};