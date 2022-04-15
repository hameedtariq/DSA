
void addLargeNumbers(string a = "", string b="")
{
    Stack<int> op1,op2,res;

    for(auto i : a)
    {
        int digit = i-'0';

        op1.push(digit);
    }
    for(auto i : b)
    {
        int digit = (int)i-48;
        op2.push(digit);
    }



    int carry = 0;
    while(!op1.isEmpty() && !op2.isEmpty())
    {
        int sum = op1.pop() + op2.pop() + carry;
        carry = sum/10;
        sum = sum% 10;

//        cout << sum;
        res.push(sum);
    }

    while(!op1.isEmpty())
    {
        res.push(op1.pop() + carry);
        carry = 0;
    }
    while(!op2.isEmpty())
    {
        res.push(op2.pop() + carry);
        carry = 0;
    }
	
	if(carry > 0)
	{
		res.push(carry);
	}
	
    while(!res.isEmpty())
    {
        cout << res.pop();
    }
}

