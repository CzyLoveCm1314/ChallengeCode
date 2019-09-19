#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

set<string> hashSets;

struct elem
{
	int steps;
	string state;
};
queue<elem> bfsq;

string finalState = "11121314151617++21222324252627++31323334353637++41424344454647++";

string firstState = "";
int minSteps;

int findNumPos(const string &state, const string &num)
{
	for (int i = 0; i < 32; i++)
	{
		if (state[i * 2] == num[0] && state[i * 2 + 1] == num[1])
			return i * 2;
	}
	return -1;
}

void bfs()
{
	hashSets.clear();
	hashSets.insert(firstState);
	while (!bfsq.empty()) bfsq.pop();
	elem curelem, newelem;
	curelem.steps = 0;
	curelem.state = firstState;
	bfsq.push(curelem);

	string curstate, newstate, num1, num2;
	int p1, p2, cursteps, i;
	while (!bfsq.empty())
	{
		curelem = bfsq.front();
		bfsq.pop();
		cursteps = curelem.steps;
		curstate = curelem.state;


		if (curstate == finalState)
		{
			minSteps = cursteps;
			return;
		}
		int startPos = 0;

		for (i = 0; i < 4; i++)
		{
			p1 = curstate.find_first_of('+', startPos);

			num1 = curstate[p1 - 2];
			num1 += curstate[p1 - 1];

			if (num1[0] != '+' && num1[1] != '7')
			{
				num2 = num1;
				num2[1]++;

				p2 = findNumPos(curstate, num2);
				newstate = curstate;

				newstate[p1] = curstate[p2];
				newstate[p1 + 1] = curstate[p2 + 1];
				newstate[p2] = newstate[p2 + 1] = '+';

				if (hashSets.find(newstate) == hashSets.end() && cursteps + 1 < minSteps)
				{
					hashSets.insert(newstate);
					newelem.steps = cursteps + 1;
					newelem.state = newstate;
					bfsq.push(newelem);
				}


			}
			startPos = p1 + 2;
		}
	}
}
int main()
{
	int caseN, i, j;
	string temp;
	cin >> caseN;
	while (caseN--)
	{

		minSteps = INT_MAX;
		firstState = finalState;
		firstState[0] = firstState[1] = firstState[16] = firstState[17] = firstState[32] = firstState[33] = firstState[48] = firstState[49] = '+';
		for (i = 0; i < 4; i++)
		{
			for (j = 1; j <= 7; j++)
			{
				cin >> temp;
			
				if (temp[1] == '1')
				{
					int pos = (int(temp[0] - '0') - 1) * 16;
					firstState[pos] = temp[0];
					firstState[pos + 1] = temp[1];
					firstState[i * 16 + j * 2] = firstState[i * 16 + j * 2 + 1] = '+';
				}
				else
				{
					firstState[i * 16 + j * 2] = temp[0];
					firstState[i * 16 + j * 2 + 1] = temp[1];
				}
			}
		}
		bfs();
		if (minSteps == INT_MAX) cout << "-1" << endl;
		else cout << minSteps << endl;
	}
	return 0;
}
