stack<int> sortStack(stack<int> data)
{
    stack<int>temp;
    int initialSize = data.size();
    int counter = 0;
    while(initialSize - counter)
    {
        int top = data.top(); data.pop();
        int size = data.size();
        for(int i =0; i < size-counter; i++)
        {

            if(top > data.top())
            {
                temp.push(data.top()); data.pop();
            }
            else
            {
                temp.push(top);
                top = data.top();
                data.pop();
            }
        }
        data.push(top);
        counter++;
        while(!temp.empty())
        {
            data.push(temp.top()); temp.pop();
        }
    }
    return data;
}
