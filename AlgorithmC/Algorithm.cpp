#include <iostream>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
#if 0
stack<int> sorting(stack<int> myStack);

int main(){
	
	return 0;
}

stack<int> sorting(stack<int> myStack)
{
	stack<int> ret;   //ret����˷���ֵ����Ϊ���ջ
	if (myStack.empty())
		return ret;

	//temp��¼������һ��Ҫ���뵽retջ�е�Ԫ��
	int temp = myStack.top();

	myStack.pop();  
	
	while (!myStack.empty() || (!ret.empty() && ret.top()>temp))
	{
		if (ret.empty() || ret.top() <= temp)
		{
			ret.push(temp);
			temp = myStack.top;
			myStack.pop();
		}
		else {
			myStack.push(ret.top);
			ret.pop();
		}
	}
	ret.push(temp);
	return ret;
}
#endif

int main(char *argv, char** args)
{
	vector<int> vi;
	vi.push_back(12);
	vi.push_back(12);
	vi.push_back(12);
	vi.push_back(12);
	vi.push_back(12);
	char p[] = { '2','c' };
}