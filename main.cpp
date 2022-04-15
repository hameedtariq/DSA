#include <iostream>
#include <string>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;


bool isValid(string ex)
{
    Stack<char> brackets;
    for(auto a:ex)
    {
        if(a == '(' || a == '{' || a == '[')
        {
            brackets.push(a);
        }
        else if (a == ')' || a == '}' || a == ']')
        {
            if(!brackets.isEmpty())
            {
                if((brackets.stackTop() == '(' && a == ')') || (brackets.stackTop() == '{' && a == '}') || (brackets.stackTop() == '[' && a == ']'))
                {
                    brackets.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }

        }
        else
        {
            return false;
        }
    }
    if(brackets.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }

}

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



int main() {
    string brack = "";
    cout << bracketsToAdd(brack);

    return 0;
}
