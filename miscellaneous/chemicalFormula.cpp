#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    // tokenizing the string and pushing it onto the stack;
    stack<string> atoms;
    string formula = "C2(HOOH)2";
    for(int i = 0; i < formula.length();i++)
    {
        string temp = "";
        if(isupper(formula[i]))
        {
            temp += formula[i];
            if(i != formula.length()-1)
            {
                while(islower(formula[i+1]))
                {
                    temp += formula[++i];
                }
            }
            atoms.push(temp);
            if(!isdigit(formula[i+1]))
            {
                atoms.push("1");
            }
        }
        else if (isdigit(formula[i]))
        {
            temp += formula[i];
            if(i != formula.length()-1)
            {
                while(isdigit(formula[i+1]))
                {
                    temp += formula[++i];
                }
            }
            atoms.push(temp);
        }
        else
        {
            temp += formula[i];
            atoms.push(temp);
        }
//        atoms.push(temp);
    }

    // reversing the tokenized string stack to parse it;
    stack<string> reverse;
    while(!atoms.empty())
    {
        reverse.push(atoms.top());atoms.pop();
    }

    // dividing the string across two different stacks. One for symbols and other for number of atoms
    stack<string> symbol;
    stack<int> count;

    while(!reverse.empty())
    {
        if(isdigit(reverse.top()[0]))
        {
            count.push(stoi(reverse.top())); reverse.pop();
        }
        else if(reverse.top() == ")")   // in-case a closing bracket occurs. It means that there is going to be a
                                        // multiplier after it, and thus we would look for an opening and update the
                                        //count of atoms by multiplying them by multiplier
        {
            stack<string> inter1; stack<int> inter2;
            reverse.pop();
            int multiplier = stoi(reverse.top()); reverse.pop();
            while(symbol.top()!="(")
            {

                inter1.push(symbol.top());
                inter2.push((count.top() * multiplier));
                symbol.pop();
                count.pop();
            }
            symbol.pop();
            while(!inter1.empty())
            {
                symbol.push(inter1.top()); inter1.pop();
            }
            while(!inter2.empty())
            {
                count.push(inter2.top()); inter2.pop();
            }
        }
        else
        {
            symbol.push(reverse.top()); reverse.pop();
        }
    }



    string result = "";

    while(!symbol.empty() && !count.empty())
    {
        result.insert(0, symbol.top() +to_string(count.top())  );
        symbol.pop();count.pop();
    }


    cout<<result;








    return 0;
}



