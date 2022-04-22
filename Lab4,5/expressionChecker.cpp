
bool checkExpression(string exp)
{
    Stack<char> brackets;
    for(auto letter:exp)
    {
        if(letter == '(' || letter == '[' || letter == '{')
        {
            brackets.push(letter);
        }
        else if (letter == ')' || letter == '}' || letter == ']')
        {
            if((letter == ')' && brackets.stackTop() == '(' )|| (letter == '}' && brackets.stackTop() == '{' )|| (letter == ']' && brackets.stackTop() == '[' ) )
            {
                brackets.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if(!brackets.isEmpty())
    {
        return false;
    }
    else
    {
        return true;
    }
}l