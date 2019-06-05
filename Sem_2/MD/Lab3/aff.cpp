#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


#define V 8// numarul de virfuri N+1

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
	//Se creaza o matrice, cu virfuri vizitate
	bool visited[V];
	memset(visited, 0, sizeof(visited));
	queue <int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int v = 0; v<V; v++)
		{
			if (visited[v] == false && rGraph[u][v] > 0)
			{
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	// Daca am ajuns la virful final atunci  true, else false
	return (visited[t] == true);
}

// Functia va returna fluxul maxim al grafului dat
int fordFulkerson(int graph[V][V], int s, int t)
{
	int u, v;
	int rGraph[V][V]; //Graful cu virful xi,xj

	for (u = 0; u < V; u++)
		for (v = 0; v < V; v++)
			rGraph[u][v] = graph[u][v];

	int parent[V];  //Virful final

	int max_flow = 0;  //Stabilirea fluxului null

	//Functioneaza pina la parcuregrea virfului final [V]
	while (bfs(rGraph, s, t, parent))
	{
		// Cautarea capacitatilor
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		// Update p/u drum &&
		// Cautarea drumului
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		//Adaugarea valorii minime la flux
		max_flow += path_flow;
	}

	// Fluxl maxim [return]
	return max_flow;
}

int main()
{
	//Exemplul din caiet
	system("color 9");
	int graph[V][V] = {
	{ 0, 12, 15, 23, 0,  0,  0, 0  },
	{ 0, 0,  0,  13, 16, 0,  0, 0  },
	{ 0, 4,  0,  9,  0,  10, 8, 0  },
	{ 0, 0,  0,  0,  0,  19, 0, 0  },
	{ 0, 0,  0,  0,  0,  0,  0, 15 },
	{ 0, 7,  0,  0,  14, 0,  0, 16 },
	{ 0, 0,  0,  0,  0,  0,  0, 27 },
	{ 0, 0,  0,  0,  0,  0,  0, 0  },
	};

	cout<<"Pentru graful cu ponderile:"<<endl;
	cout<<" 0, 12, 15, 23, 0,  0,  0, 0  "<<endl;
	cout<<" 0, 0,  0,  13, 16, 0,  0, 0  "<<endl;
	cout<<" 0, 4,  0,  9,  0,  10, 8, 0  "<<endl;
	cout<<" 0, 0,  0,  0,  0,  19, 0, 0  "<<endl;
	cout<<" 0, 0,  0,  0,  0,  0,  0, 15 "<<endl;
	cout<<" 0, 7,  0,  0,  14, 0,  0, 16 "<<endl;
	cout<<" 0, 0,  0,  0,  0,  0,  0, 27 "<<endl;
	cout<<" 0, 0,  0,  0,  0,  0,  0, 0  "<<endl;
	cout<<"avem:"<<endl;

	cout << "Fluxul maxim este: " << fordFulkerson(graph, 0, V-1);
	getch();
	return 0;
}
