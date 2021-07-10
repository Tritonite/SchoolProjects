#include <iostream>
using namespace std; 
/*
Project 4: 
	The Goal of this project is to create a n-nary tree from scratch. We will be calculating the root, level, least common ancestor, 
	and height of this tree. 

@author Triston Luzanta 

@verstion 4/12/19




*/

class Tree
{
protected:
	// Array for the parent array 
	int* parentArray;
	// size of the parent array 
	int size;
	// root 
	int root; 
	
public:


	Tree(); // Empty Constructor 
	Tree(int numNodes); // Nonempty Constructor 
	Tree(Tree & M); // Copy constructor 
	~Tree(); // Destructor 
	void setRoot(int rootNode); // Sets the root of the tree
	int Root(); // Gives the root of the tree 
	void setParent(int node, int parent); // Sets the parent array 
	int parentNode(int node); // Gives the parent
	int Children(int node); // Gives the child of the parent 
	int Sibling(int node); //  Gets the siblings of the child 
	int level(int node); // Gives the level of the node 
	int nodesAtLevel(int node); // Gives all the nodes at that level 
	int height(); // Gives the height of the tree 
	void LCA(int n1, int n2); // Gives the Least Common ancestor of two nodes 
	void preorder(int node); // Preorder 
	void preorder(); // Preorder 
	int* getParentArray(); // Getter for ParentArray 
	int getSize(); // Size Getter 
	
	


	// Ostream operator for displaying the child : parent of the tree. 
	friend ostream& operator<<(ostream& os, const Tree & M)
	{
		for (int i = 0; i < M.size; i++)
		{

			cout << i << ": " << M.parentArray[i] << '\t' ; 
			
		}

		return os;

	};
};
 
	// Empty Constructor 
	Tree::Tree()
	{
		size = NULL;
		root = NULL; 
	}

	// NonEmpty constructor 
	Tree::Tree(int numNodes)
	{
		size = numNodes; 
		parentArray = new int[size];
		root = NULL;
	}

	// Copy Constructor 
	Tree::Tree(Tree & M)
	{
		parentArray = new int[M.getSize()]; 

		for (int i = 0; i < M.getSize(); i++)
		{
			parentArray[i] = M.getParentArray()[i]; 
		}

		size = M.getSize(); 
		root = M.Root();
	}

	// Destructor 
	Tree::~Tree()
	{
		if (parentArray != NULL)
		{
			delete[] parentArray; 
		}
	}

	// Root Setter 
	void Tree::setRoot(int rootNode)
	{

		root = rootNode; 


	}

	// Root "Getter"
	int Tree::Root()
	{
		
		return root; 

	}

	// Parent Setter 
	void Tree::setParent(int node, int parent)
	{
		parentArray[node] = parent;
	}

	// Parent node 
	int Tree::parentNode(int node)
	{
		cout << parentArray[node] << endl; 

		return 0; 
	}

	// Children of Parent Array 
	int Tree::Children(int parent)
	{
		for (int i = 0; i < size; i++)
		{
			if (parentArray[i] == parent)
			{
				cout << i << " "; 
			}

		}
		cout << endl; 
		return 0; 
	}

	// Nodes on same level 
	int Tree::Sibling(int node)
	{

		for (int i = 0; i < size; i++)
		{
			if ((parentArray[i] == parentArray[node]) && (i != node))
			{
				cout << i << " "; 
			}
		}

		cout << endl; 
		return 0; 
	}

	// Gives the level of the node 
	int Tree::level(int node) 
	{
		if (parentArray[node] == -1)
		{
			return 1;
		}
		
		else 
		{
			return (1 + level(parentArray[node]));
		}

	}

	// Gives all the nodes at that level 
	int Tree::nodesAtLevel(int node) 
	{
		for (int i = 0; i < size; i++) 
		{
			if (node == level(i)) 
			{
				cout << i << " ";
			}
		}
		cout << endl;
		return 0;
	}

	// Gives height of the tree 
	int Tree::height() {
		int max = 0;
		if (root == NULL) 
		{
			return 0;
		}
		else 
		{
			for (int i = 0; i < size; i++) 
			{
				if (level(i) > max) 
				{
					max = level(i);
				}
			}
		}
		return max;
	}

	// Gives the Least common ancestor of two nodes 
	void Tree::LCA(int n1, int n2) {
		if (n1 == n2)
		{
			cout << n1 << endl;
		}
		else if (level(n1) < level(n2)) 
		{
			LCA(n1, parentArray[n2]);
		}
		else if (level(n2) < level(n1)) 
		{
			LCA(parentArray[n1], n2);
		}
		else if (level(n2) == level(n1)) 
		{
			LCA(parentArray[n1], parentArray[n2]);
		}
	}

	// preorder bonus recursive
	void Tree::preorder(int node) 
	{
		cout << node << " ";
		for (int j = 0; j < size; j++) 
		{
			if (parentArray[j] == node) 
			{
				preorder(j);
			}
		}

		 
	}
	// preorder starting at the root of the tree and calling the recursive one
	void Tree::preorder() 
	{
		preorder(root);
	}

	int* Tree::getParentArray()
	{
		return parentArray; 
	}

	int Tree::getSize()
	{
		return size; 
	}




	// Control operations of the program. 
	int main()
	{
		Tree* myTree;
		int numNodes, node, parent;

		cin >> numNodes;
		myTree = new Tree(numNodes);
		for (int i = 0; i < numNodes; i++) 
		{
			cin >> node >> parent;
			(*myTree).setParent(node, parent);
			if (parent == -1) {
				(*myTree).setRoot(node);
			}
		}
		cout << "The tree that we just read is : " << endl;
		cout << (*myTree) << endl;// ostream **


		Tree* newTree = new Tree(*myTree);
		cout << "The tree that we just copied is : " << endl;
		cout << (*newTree) << endl;// ostream **

		cout << "The root of the tree is : " << (*myTree).Root() << endl;
	

		cout << "The least common ancestor of nodes 3 and 8 is: " << endl;
		(*newTree).LCA(3, 8);
		cout << "The least common ancestor of nodes 13 and 8 is: " << endl;
		(*newTree).LCA(13, 8);
		cout << "The least common ancestor of nodes 13 and 11 is: " << endl;
		(*myTree).LCA(13, 11);

		cout << "The children of node 12 is / are:" << endl;
		(*myTree).Children(12);

		cout << "The children of node 10 is / are: " << endl;
		(*myTree).Children(10);

		cout << "The siblings of node 3 is / are: " << endl;
		(*myTree).Sibling(3);

		cout << "The siblings of node 12 is / are: " << endl;
		(*myTree).Sibling(12);

		cout << "The nodes at level 3 is / are: " << endl;
		(*myTree).nodesAtLevel(3);

		cout << "The height of the tree is : " << (*myTree).height() << endl;

		cout << "The level of node 3 in the tree is : " << (*myTree).level(3) << endl;
		cout << "The level of node 12 in the tree is : " << (*myTree).level(12) << endl;

		cout << "The preorder traversal of the tree is / are: " << endl;
		// preorder bonus
		(*myTree).preorder();

		cout << endl;

		delete myTree;
		delete newTree;

		system("pause"); 
		return 0; 
	}

	// 14 7 9 8 12 10 6 0 1 1 6 9 12 11 10 2 12 12 6 4 10 3 9 13 4 5 0 6 -1