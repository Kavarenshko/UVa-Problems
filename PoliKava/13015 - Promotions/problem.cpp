#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_EMPLOYEES 5005
#define UNVISITED -1

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> prev_v(MAX_EMPLOYEES);
int visited_prev_v[MAX_EMPLOYEES];
vector<vi> succ_v(MAX_EMPLOYEES);
int visited_succ_v[MAX_EMPLOYEES]; // get relative depth

int getPrevCount(int index)
{
	int new_nodes = 0;
	//visited_succ_v[index] = 0; // mark it as visited

	//printf("\nVisiting node %d...", index);

	for(int i=0; i < prev_v[index].size(); i++)
	{
		int curr_neighbor = prev_v[index][i];

		//printf("\n    > %d from %d...", curr_neighbor, index);

		if (visited_prev_v[curr_neighbor] == UNVISITED)
		{
			//printf("unvisited");
			visited_prev_v[curr_neighbor] = visited_prev_v[index] + 1;
			new_nodes += 1 + getPrevCount(curr_neighbor);
		}
		else if (visited_prev_v[curr_neighbor] <= visited_prev_v[index]) // already visited
		{
			//printf("visited, %d <= %d ", visited_prev_v[curr_neighbor], visited_prev_v[index]);
			continue;
		}
		else if (visited_prev_v[curr_neighbor] >= visited_prev_v[index] + 1)
		{
			//printf("visited, %d >= %d+1", visited_prev_v[curr_neighbor], visited_prev_v[index]);
			continue;
		}
		else
			*(int*)0 = 0;
	}

	//printf("\nFinished DFS with node %d, new nodes: %d", index, new_nodes);
	return new_nodes;
}

int getSuccCount(int index)
{
	int new_nodes = 0;
	//visited_succ_v[index] = 0; // mark it as visited

	//printf("\nVisiting node %d...", index);

	for(int i=0; i < succ_v[index].size(); i++)
	{
		int curr_neighbor = succ_v[index][i];

		//printf("\n    > %d from %d...", curr_neighbor, index);

		if (visited_succ_v[curr_neighbor] == UNVISITED)
		{
			//printf("unvisited");
			visited_succ_v[curr_neighbor] = visited_succ_v[index] + 1;
			new_nodes += 1 + getSuccCount(curr_neighbor);
		}
		else if (visited_succ_v[curr_neighbor] <= visited_succ_v[index]) // already visited
		{
			//printf("visited, %d <= %d ", visited_succ_v[curr_neighbor], visited_succ_v[index]);
			continue;
		}
		else if (visited_succ_v[curr_neighbor] >= visited_succ_v[index] + 1)
		{
			//printf("visited, %d >= %d+1", visited_succ_v[curr_neighbor], visited_succ_v[index]);
			continue;
		}
		else
			*(int*)0 = 0;
	}

	//printf("\nFinished DFS with node %d, new nodes: %d", index, new_nodes);
	return new_nodes;
}

int main()
{
	int a, b, e, p;
	while (scanf("%d %d %d %d", &a, &b, &e, &p) == 4)
	{
		int tot_a = 0, tot_b = 0, tot_c = 0;

		for(int i=0; i < MAX_EMPLOYEES; i++)
		{
			prev_v[i].clear();
			succ_v[i].clear();
		}

		fill(visited_prev_v, visited_prev_v+MAX_EMPLOYEES, UNVISITED);
		fill(visited_succ_v, visited_succ_v+MAX_EMPLOYEES, UNVISITED);

		for(int i=0; i < p; i++)
		{
			int x,y;

			cin >> x >> y;

			prev_v[y].push_back(x);
			succ_v[x].push_back(y);
		}

		for(int i=0; i < e; i++)
		{
			visited_succ_v[i] = 0; // relative depth 0
			visited_prev_v[i] = 0; 
			
			int pcount = getPrevCount(i);
			int scount = getSuccCount(i);

			if (scount >= e-a)
				tot_a++;
			if (scount >= e-b)
				tot_b++;
			if (pcount >= b)
				tot_c++;

			fill(visited_prev_v, visited_prev_v+MAX_EMPLOYEES, UNVISITED);
			fill(visited_succ_v, visited_succ_v+MAX_EMPLOYEES, UNVISITED);
		}

		printf("%d\n%d\n%d\n", tot_a, tot_b, tot_c);
	}

	return EXIT_SUCCESS;
}