#include <iostream>

using namespace std;

int numbers[4], sequence[4];
int operators[3]; // Operators: 0 - add, 1 - subtract, 2 - multiply, 3 - divide
bool visited[4];

void number_dfs(int t);
void operator_dfs(int t);
void caculate();

int main()
{
	for (int i = 0; i < 4; i++)
		cin >> numbers[i];

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
		if (!visited[i])
		{
			sequence[t] = numbers[i];
			visited[i] = true;
			number_dfs(t + 1);
			visited[i] = false;
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
		operators[t] = i;
		operator_dfs(t + 1);
	}
}

void caculate()
{
	int res = sequence[0];
	for (int i = 0; i < 3; i++)
	{
		switch (operators[i])
		{
		case 0:
			res += sequence[i + 1];
			break;
		case 1:
			res -= sequence[i + 1];
			break;
		case 2:
			res *= sequence[i + 1];
			break;
		case 3:
			res /= sequence[i + 1];
			break;
		}
	}
	if (res == 24)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << sequence[i] << " ";
			switch (operators[i])
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
		cout << sequence[3] << endl;
	}
	return;
}
