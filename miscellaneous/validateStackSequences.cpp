bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> temp;
        for(int i =0, j=0; i < popped.size();)
        {
            while(temp.empty() || temp.top() != popped[i])
            {
                if(!(j < pushed.size()))
                {
                    return false;
                }
                temp.push(pushed[j++]);
            }
            temp.pop();
            i++;
        }
        return true;
    }