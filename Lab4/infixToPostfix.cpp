string infixToPostfix(string exp)
{
    string postfix;
    Stack<char> operators;
    for(auto a: exp)
    {
        if(a > 64 && a< 91 || a >96 && a < 123)
        {
            postfix += a;
        }
        else if(a == '{' || a == '(' || a == '[')
        {
            operators.push(a);
        }
        else if(a == ']' || a == ')' || a == '}')
        {
            if(a == ']')
            {
                while(operators.stackTop() != '[')
                {
                    postfix += operators.pop();
                }
                operators.pop();
            }
            else if(a == ')')
            {
                while(operators.stackTop() != '(')
                {
                    postfix += operators.pop();
                }
                operators.pop();
            }
            else if(a == '}')
            {
                while(operators.stackTop() != '{')
                {
                    postfix += operators.pop();
                }
                operators.pop();
            }

        }
        else
        {
            if(operators.isEmpty() || precedence(operators.stackTop()) < precedence(a))
            {
                operators.push(a);
            }
            else
            {
                while(!(operators.isEmpty() || precedence(operators.stackTop()) < precedence(a)))
                {
                    postfix += operators.pop();
                }
                operators.push(a);
            }
        }
    }
    while(!operators.isEmpty())
    {
        postfix+=operators.pop();
    }
    return postfix;
}
