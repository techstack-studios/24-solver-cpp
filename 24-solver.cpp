#include <iostream>
using namespace std;

int input[4], process[4], cnt = 0;
int op[3]; // Operators: 0 - add, 1 - subtract, 2 - multiply, 3 - divide
bool visit[4];

void number_dfs(int t);
void operator_dfs(int t);
void caculate();

int main()
{
	for (int i = 0; i < 4; i++)
		cin >> input[i];
	number_dfs(0);
	return 0;
}

void number_dfs(int t)
{
	if (t == 4)
	{
		operator_dfs(0);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (!visit[i])
		{
			process[t] = input[i];
			visit[i] = true;
			number_dfs(t + 1);
			visit[i] = false;
		}
	}
}

void operator_dfs(int t)
{
	if (t == 3)
	{
		caculate();
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		op[t] = i;
		operator_dfs(t + 1);
	}
}

void caculate()
{
	int res = process[0];
	for (int i = 0; i < 3; i++)
	{
		switch (op[i])
		{
		case 0:
			res += process[i + 1];
			break;
		case 1:
			res -= process[i + 1];
			break;
		case 2:
			res *= process[i + 1];
			break;
		case 3:
			res /= process[i + 1];
			break;
		}
	}
	if (res == 24)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << process[i] << " ";
			switch (op[i])
			{
			case 0:
				cout << "+ ";
				break;
			case 1:
				cout << "- ";
				break;
			case 2:
				cout << "* ";
				break;
			case 3:
				cout << "/ ";
				break;
			}
		}
		cout << process[3] << endl;
	}
	return;
}
