
#include <bits/stdc++.h>
using namespace std;

void addEdge(int x, int y, vector<vector<int> >& adj)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}

void printParents(int node, vector<vector<int> >& adj,
				int parent)
{

	if (parent == 0)
		cout << node << "->Root" << endl;
	else
		cout << node << "->" << parent << endl;
	// Using DFS
	for (auto cur : adj[node])
		if (cur != parent)
			printParents(cur, adj, node);
}

void printChildren(int Root, vector<vector<int> >& adj)
{
	
	queue<int> q;

	q.push(Root);
	

	int vis[adj.size()] = { 0 };

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		vis[node] = 1;
		cout << node << "-> ";
		for (auto cur : adj[node])
			if (vis[cur] == 0) {
				cout << cur << " ";
				q.push(cur);
			}
		cout << endl;
	}
}

void printLeafNodes(int Root, vector<vector<int> >& adj)
{
	
	for (int i = 1; i < adj.size(); i++)
		if (adj[i].size() == 1 && i != Root)
			cout << i << " ";
	cout << endl;
}

void printDegrees(int Root, vector<vector<int> >& adj)
{
	for (int i = 1; i < adj.size(); i++) {
		cout << i << ": ";

		if (i == Root)
			cout << adj[i].size() << endl;
		else
			cout << adj[i].size() - 1 << endl;
	}
}

int main()
{

	int N = 7, Root = 1;

	vector<vector<int> > adj(N + 1, vector<int>());

	addEdge(1, 2, adj);
	addEdge(1, 3, adj);
	addEdge(1, 4, adj);
	addEdge(2, 5, adj);
	addEdge(2, 6, adj);
	addEdge(4, 7, adj);

	cout << "The parents of each node are:" << endl;
	printParents(Root, adj, 0);


	cout << "The children of each node are:" << endl;
	printChildren(Root, adj);


	cout << "The leaf nodes of the tree are:" << endl;
	printLeafNodes(Root, adj);


	cout << "The degrees of each node are:" << endl;
	printDegrees(Root, adj);

	return 0;
}
