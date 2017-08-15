#include<iostream>
#include"stack.h"
using namespace std;

int main() 
{
	int num,i;
	bool check=true;


	cout << "�Է�" << endl << endl;
	while (1) {
		cin >> num;
		if (num < 1 && num>100)  // ���� �����ȿ� �ȵ����� ��� ��� �� �ٽ� �Է�
		{
			cout << "1�̻� 100������ ������ �ٽ� �Է��Ͻÿ�" << endl;
		}
		else
			break;
	}

	//stack �ϳ��� ���� num ���� ��ŭ�� ���� �ݴ�� push ���� 
	Stack first;
	for (i = num; i >0; i--)
	{
		first.push(i);
	}

	// �迭 �ϳ��� ���� ���� �Է��� ������ �־��� 
	int *arr = new int[num];
	for (i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	//pop�� ���� ������ stack�� ����� �ش�.
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
	

	cout << endl << endl << "���" << endl << endl;;
	if (check == true)
	{
		cout << endl << "YES" << endl;
	}
	else
		cout << endl << "NO" << endl;

	return 0;
}