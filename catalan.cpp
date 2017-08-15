#include<iostream>
#include"stack.h"
using namespace std;

int main() 
{
	int num,i;
	bool check=true;


	cout << "입력" << endl << endl;
	while (1) {
		cin >> num;
		if (num < 1 && num>100)  // 만약 범위안에 안들어오면 경고 출력 후 다시 입력
		{
			cout << "1이상 100이하의 정수를 다시 입력하시오" << endl;
		}
		else
			break;
	}

	//stack 하나를 만들어서 num 개수 만큼의 수를 반대로 push 해줌 
	Stack first;
	for (i = num; i >0; i--)
	{
		first.push(i);
	}

	// 배열 하나를 만들어서 내가 입력한 수들을 넣어줌 
	int *arr = new int[num];
	for (i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	//pop한 것을 저장할 stack을 만들어 준다.
	Stack pop;
	int index = 0;

	for (i = 0; i < num; i++)
	{
		if (pop.isEmpty() && first.isEmpty())
		{
			check = false;
			break;
		}
		else if (first.isEmpty())
		{
			if (arr[i] != pop.top())
			{
				check = false;
				break;
			}
			else
			{
				pop.pop();
			}
		}
		else if (arr[i] == first.top())
		{
			first.pop();
		}
		else if (arr[i] != first.top())
		{
			if (!pop.isEmpty())
			{
				if (arr[i] != pop.top())
				{

					while (arr[i] != first.top())
					{
						if (first.isEmpty())
						{
							check = false;
							break;
						}
						pop.push(first.pop());
					}
					if (check == false) break;
					first.pop();
				}
				else if(arr[i] == pop.top())
					pop.pop();
		
			}
			else
			{
				while (arr[i] != first.top())
				{
					if (first.isEmpty())
					{
						check = false;
						break;
					}
					pop.push(first.pop());
				}
				if (check == false) break;
				first.pop();
			}
		}
	}
	

	cout << endl << endl << "출력" << endl << endl;;
	if (check == true)
	{
		cout << endl << "YES" << endl;
	}
	else
		cout << endl << "NO" << endl;

	return 0;
}