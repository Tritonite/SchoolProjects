#include <iostream>
#include <list>
#include <queue>
using namespace std;
/*
Project 5:
	The Goal of this project is to create a graph by making two classes. These two classes are the AdjacencyMatrix, and the 
	AdjacencyList class. They are the representation for the graph we will make. We will be linking nodes with our add edge method 
	and preform breadth first search on a particular vertex. 

@author Triston Luzanta

@verstion 4/29/19




*/

class AdjacencyMatrix
{
protected:
	bool** adjacencyMatrix;

	int vertex; // Size of the matrix 
public:
	AdjacencyMatrix(); // Empty constructor 
	AdjacencyMatrix(int numVertex); // Non empty constructor 
	void addEdge(int a, int b); // Connects the 2 nodes 
	// Ostream operator for displaying the Adjacency Matrix representation 
	friend ostream& operator<<(ostream& os, const AdjacencyMatrix & M)
	{
		int count = 1; 
		int count2 = 0; 

		for (int i = 0; i < M.vertex; i++)
		{
			for (int j = 0; j < M.vertex; j++)
			{
				if (j > i)
				{
					if (M.adjacencyMatrix[i][j] == true)
					{
						if (count < M.vertex - 1)
						{
							cout << "(" << i << "," << j << ")" << ",";
							
						}

						else if (count2 > M.vertex)
						{
							cout << "(" << i << "," << j << ")"; 
							
						}

						 
					}
					count2++;
					
				}
				
			}

			count++;
		}

		return os;

	};

	void BFS(int u); // Breadfirst Search method 
	bool isEdge(int i, int j); // Checks if there is an edge between the nodes 
	AdjacencyMatrix(AdjacencyMatrix & M); // Copy Constructor 
	void operator=(AdjacencyMatrix& Mt); // = operator 
	~AdjacencyMatrix(); 
	void DFSR(int t, bool visit[]);
	void DFS(int i);
	
	



};

class AdjacencyList
{
protected:
	int vertices; // Size of the List 
	list<int> * adjacencyList; // List pointer 
	
public:
	AdjacencyList(); // Empty constructor 
	AdjacencyList(int numVertices); // Nonempty constructor 
	void addEdge(int c, int d); // Add edge method 
	// Ostream operator for displaying the adjacency list representation 
	friend ostream& operator<<(ostream& os, const AdjacencyList & M)
	{

		int count = 0; 
		for (int i = 0; i < M.vertices; i++)
		{

			for (auto& it : M.adjacencyList[i])
			{

				if (count <= M.vertices + 1)
				{
					cout << "(" << i << "," << it << ")" << ",";

				}
				else
				{
					cout << "(" << i << "," << it << ")";
				}
				count++;

			}

		}
				return os;

	}; 

	void BFS(int k); // Breadth first search method 
	bool isEdge(int i, int j); // Checks if there is an edge between the nodes
	AdjacencyList(AdjacencyList & M); // Copy Constructor 
	void operator=(AdjacencyList & Mt); // = operator 
	~AdjacencyList(); 
	void DFSR(int q, bool visited[]);
	void DFS(int i);
	


	}; 


AdjacencyMatrix::AdjacencyMatrix()
{

}

// Creates/Sets up the matrix 
AdjacencyMatrix::AdjacencyMatrix(int numVertex)
{
	// Size of the index 
	vertex = numVertex;

	adjacencyMatrix = new bool*[vertex];

	
	for (int i = 0; i < vertex; i++)
	{
		adjacencyMatrix[i] = new bool[vertex];
		for (int j = 0; j < vertex; j++)
		{
			adjacencyMatrix[i][j] = false;
		}
	}

}

// Links/Adds an edge to the nodes 
void AdjacencyMatrix::addEdge(int a, int b)
{

	adjacencyMatrix[a][b] = true;
	adjacencyMatrix[b][a] = true;



}

// Breadthfirst search method for a particular vertex
void AdjacencyMatrix::BFS(int u)
{
	bool *visited = new bool[vertex];

	for (int i = 0; i < vertex; i++)
	{
		visited[i] = false; 
	}

	int *parent = new int[vertex]; 
	

	queue<int> Q; 

	Q.push(u); 

	visited[u] = true; 

	parent[u] = -1; 

	while (Q.size() > 0)
	{
		int k = Q.front(); 
		Q.pop(); 
		
		for (int i = 0; i < vertex; i++)
		{
			if (isEdge(i, k) && !visited[i])
			{
				parent[i] = k; 
				visited[i] = true; 
				Q.push(i); 
			}
		}
	}

	// Prints out the parent  and child
	for (int i = 0; i < vertex; i++)
	{
		cout << i << ":" << parent[i] << " "; 
	}

	cout << endl; 

	delete[] parent; 

}

// Matrix version of checking if there is an edge between the node 
bool AdjacencyMatrix::isEdge(int i, int j)
{
	return adjacencyMatrix[i][j];
}

// Copy Constructor 
AdjacencyMatrix::AdjacencyMatrix(AdjacencyMatrix & M)
{
	vertex = M.vertex; 
	adjacencyMatrix = M.adjacencyMatrix; 

}

// = operator 
void AdjacencyMatrix::operator=(AdjacencyMatrix & Mt)
{
	adjacencyMatrix = Mt.adjacencyMatrix; 
	vertex = Mt.vertex; 
}
// AdjacencyMatrix destructor 
AdjacencyMatrix::~AdjacencyMatrix()
{
	if (adjacencyMatrix != NULL)
	{
		delete adjacencyMatrix; 
	}
}

void AdjacencyMatrix::DFSR(int t, bool visit[])
{
	visit[t] = true;

	for (int i = 0; i < vertex; i++)
	{
		adjacencyMatrix[i] = new bool[vertex]; 
		for (int j = 0; j < vertex; j++)
		{
			adjacencyMatrix[i][j] = visit[t]; 

			if (!visit[i])
			{
				DFSR(i, visit);

				cout << i << ":" << t << "\t"; 
			}
		}
	}
}

void AdjacencyMatrix::DFS(int i)
{

	bool* visited = new bool[vertex];
	for (int i = 0; i < vertex; i++)
	{
		visited[i] = false;
	}

			DFSR(i, visited);



}

// Breadth First Search method for a particular vertex
void AdjacencyList::BFS(int v)
{

	bool * visited = new bool[vertices];


	for (int i = 0; i < vertices; i++)
	{
		visited[i] = false; 
	}

	int* parent = new int[vertices]; 
	queue<int> Q; 

	Q.push(v); 
	visited[v] = true; 
	parent[v] = -1; 

	while (Q.size() > 0)
	{
		int k = Q.front(); 
		Q.pop(); 
		
		for (list<int>::iterator it = adjacencyList[k].begin(); it != adjacencyList[k].end(); ++it)
		{
			
			if (!visited[*it])
			{
				parent[*it] = k; 
				visited[*it] = true; 
				Q.push(*it); 
				
			}
		}
	}
	// Prints out parent and child 
	for (int i = 0; i < vertices; i++)
	{
		cout << i << ":" << parent[i] << " "; 
	}
	cout << endl; 

	delete[] parent; 
	
}

// List version for checking if there is an edge between nodes 
bool AdjacencyList::isEdge(int a, int b)
{
	for (list<int>::iterator it = adjacencyList[a].begin(); it != adjacencyList[a].end(); ++it)
	{
		int ez = *it;

		if (ez == b)
		{

			return true;

		}
	}

	return false;
}

// Copy Constructor 
AdjacencyList::AdjacencyList(AdjacencyList & M)
{
	vertices = M.vertices; 

	adjacencyList = M.adjacencyList; 
}

// = operator 
void AdjacencyList::operator=(AdjacencyList & Mt)
{
	vertices = Mt.vertices; 
	adjacencyList = Mt.adjacencyList; 
}
// Adjacency List Destructor 
AdjacencyList::~AdjacencyList()
{
	// Goes through each iteration and deletes it 
	for (int i = 0; i < vertices; i++)
	{
		adjacencyList[i].clear(); 
	}

	// Delete the list 
	delete[] adjacencyList; 

}

// Recursive DFSR
void AdjacencyList::DFSR(int q, bool visited[])
{

	visited[q] = true; 
	
	list<int>::iterator i; 
	for (i = adjacencyList[q].begin(); i != adjacencyList[q].end(); ++i)
	{
		if (!visited[*i])
		{
			DFSR(*i, visited); 

			cout << *i << ":" << q << "\t"; 
		}
	
	}


}
// Depth Search Method 
void AdjacencyList::DFS(int i)
{
	bool* visited = new bool[vertices]; 
	for (int j = 0; j < vertices; j++)
	{
		visited[j] = false; 
	}

	cout << i << ":" << -1 << "\t"; 
		DFSR(i, visited);

}


// Empty Constructor 
AdjacencyList::AdjacencyList()
{
	vertices = NULL;
}


// Non Empty Construtor that sets up the adjacency list 
AdjacencyList::AdjacencyList(int numVertices)
{
	vertices = numVertices;

	bool* visited = new bool[vertices]; 

	adjacencyList = new list<int>[vertices];

}

// List version for adding an edge between nodes 
void AdjacencyList::addEdge(int c, int d)
{
	if (c < d)
	{
		adjacencyList[c].push_back(d);
	}
	else
	{
		adjacencyList[d].push_back(c);
	}
}


// Controls operation of the program 
int main()
{
	// inputs 
	int noVertices;
	int x;
	int y;

	cin >> noVertices;

	// Objects created for our outputs 
	AdjacencyMatrix* myMatrix = new AdjacencyMatrix(noVertices);
	AdjacencyList* myList = new AdjacencyList(noVertices); 


	
	cin >> x >> y; 
	while (!cin.eof())
	{
		// While not the end of the file, add edge will keep going
		(*myMatrix).addEdge(x, y);
		(*myList).addEdge(x, y);

		cin >> x >> y;
	}
	// Adjacency Matrix output 
	cout << "Adjacency Matrix" << endl;
	cout << (*myMatrix) << endl;

	// Adjacency List output 
	cout << "Adjacency List " << endl;
	cout << (*myList) << endl;


	// Copy Constructor Objects created for testing 
	AdjacencyMatrix* newMatrix = new AdjacencyMatrix(*myMatrix); 
	AdjacencyList* newList = new AdjacencyList(*myList); 

	// Copy Constructor of Adjacency Matrix 
	cout << "Copy Adjacency Matrix" << endl; 
	cout << (*newMatrix) << endl; 

	// Copy Constructor of Adjacency List
	cout << "Copy Adjacency List" << endl; 
	cout << (*newList) << endl; 


	// = operator objcets created for testing 
	AdjacencyMatrix* newMatrix2 = new AdjacencyMatrix(); 
	AdjacencyList* newList2 = new AdjacencyList();

	// = operator for Adjacency Matrix 
	(*newMatrix2) = (*myMatrix); 
	cout << "= Adjacency Matrix" << endl; 
	cout << (*newMatrix2) << endl; 

	// = operator for Adjacency List 
	(*newList2) = (*myList);
	cout << "= Adjacency List" << endl;
	cout << (*newList2) << endl;



	// BreadthFirst method display for Adjacency Matrix 
	cout << "Matrix BFS" << endl; 
	(*myMatrix).BFS(0); 

	// BreadthFirst method display for Adjacency List 
	cout << "List BFS" << endl; 
	(*myList).BFS(0); 


	// Depth first search graph 
	cout << "Matrix DFS" << endl;
	(*myMatrix).DFS(0);


	// Depth first search graph 
	cout << "List DFS" << endl; 
	(*myList).DFS(0); 


	

	// Deleting pointers after execution
	delete myMatrix; 
	delete myList; 
	delete newMatrix; 
	delete newList; 
	delete newMatrix2; 
	delete newList2; 

	system("pause");
	return 0;

}



