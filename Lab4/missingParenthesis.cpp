
int bracketsToAdd(string ex)
{
    int num = 0;
    Stack<char> brackets;
    for(auto a: ex)
    {
        if(a == '(')
        {
            brackets.push(a);
        }
        else if(a == ')')
        {
            if(!brackets.isEmpty())
            {
                brackets.pop();

            }
            else
            {
                num++;
            }
        }

    }
    while(!brackets.isEmpty())
    {
        num++;
        brackets.pop();

    }
    return num;
}