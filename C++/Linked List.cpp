#include <iostream>

using namespace std; 
/**
In this project, we are building a linkedlist class from scratch and applying it to make polynomials. We will 
be operating function such as multiplying and adding these polynomials in descending order. 

@author Triston Luzanta 
@version 3/13/2019
**/

/*
This is the Linkedlist class that will be the foundation for the polynomial class.
*/
template <class DT>
class LinkedList
{

protected: 
	// Pointer object of DT
	DT* data; 
	// Linked list pointer 
	LinkedList<DT>* nextNode; 

public: 
	LinkedList(); // Empty Constructor 
	LinkedList(DT& i); // NonEmpty Constructor 
	LinkedList(DT& i, LinkedList<DT>* n); // Nonempty Constructor 
	LinkedList(const LinkedList<DT>& other); // Copy Constructor 
	~LinkedList(); // Destructor 
	void insertAt(DT& x, int pos); // Insert method
	void remove(); // Remove method 
	void removeAt(int i); // Removes the object at that specific index 
	void add(DT &newOne); // Add method 
	int size(); // Size method 
	DT & infoAt(int pos); // info at method
	DT & operator[](int pos); // Operator [] method 
	bool isEmpty();  // Accessor method 
	DT & info(); // Accessor method 
	LinkedList<DT>* next(); // Accessor method 





};

class Term
{
protected: 
	// Coefficient of Polynomial 
	int coefficient; 
	// Exponent ofPolynomial 
	int exponent; 

public: 
	Term(); // Empty constructor 
	Term(int a, int b); // Nonempty constructor 
	~Term(); // Destructor 
	void setCoeff(int c); // Setter for Coefficient 
	void setExpo(int ex); // Setter for Exponent 
	int getCoeff(); // Getter for Coefficient 
	int getExpo(); // Setter for exponent 
};

class Polynomial
{
protected: 
	LinkedList<Term>* myPoly; // Pointer of LinkedList of Term classes?
public: 
	Polynomial(); // Empty constructor
	~Polynomial(); // Destructor 
	void addTerm(int cof, int exp); // Inserts a term of the following polynomials kept in descending order
	void printPolynomial(); // Prints the Polynomial
	Polynomial & multiplyPolynomial(Polynomial & ply);  // Multiplies the polynomials 
	Polynomial & addPolynomial(Polynomial & ply); // Adds the polynomials 
	int evaluatePoly(int x); // Evaluates the polynomial at a given value 
	void deleteTerm(int exp); // Removes the polynomial term 
	Polynomial operator+(Polynomial &M); // + operation function 
	Polynomial operator*(Polynomial &M); // * operation function 
	
	// Ostream Operator for displaying the Polynomials in this format 
	friend ostream& operator<<(ostream& os, const Polynomial & M)
	{

		for (int i = 0; i < M.myPoly->size(); i++)

		{

			if (i < M.myPoly->size() - 1)
			{
				cout << "( " << M.myPoly->infoAt(i).getCoeff() << " , " << M.myPoly->infoAt(i).getExpo() << " )" << " + "; 
			}

			else
			{
				cout << "( " << M.myPoly->infoAt(i).getCoeff() << " , " << M.myPoly->infoAt(i).getExpo() << " )" << endl; 

			}
		}

		

		return os;
	}

};


template<class DT>
LinkedList<DT>::LinkedList()
{
	data = NULL; 
	nextNode = NULL; 
}

template<class DT>
LinkedList<DT>::LinkedList(DT& i)
{
	data = new DT(i); 
	nextNode = NULL; 
}


template<class DT>
LinkedList<DT>::LinkedList(DT & i, LinkedList<DT>* n)
{
	data = new DT(i); 
	nextNode = n; 

}

template<class DT>
LinkedList<DT>::LinkedList(const LinkedList<DT>& other)
{
	// Copies the varibles of the default/ nonEmpty constructors. 
	if (other.data == NULL)
	{
		data = NULL; 
	}

	else
	{
		data = new DT(*(other.data)); 
	}

	if (other.nextNode == NULL)
	{
		nextNode = NULL; 
	}

	else
	{
		nextNode = new LinkedList<DT>((*other.nextNode)); 
	}
}

template<class DT>
LinkedList<DT>::~LinkedList()
{
	// Clears up Garbage 
	if (data != NULL)
	{
		delete data; 
		data = NULL; 
	}

	if (nextNode != NULL)
	{
		delete nextNode; 
		nextNode = NULL; 
	}

}

template<class DT>
void LinkedList<DT>::insertAt(DT & x, int pos)
{
	// Using the add method if the position is 0 
	if (pos == 0)
	{
		add(x);
	}

	else
	{
		// If Null , the pointer is now a new Linked list of DT x
		if (nextNode == NULL)
		{
			nextNode = new LinkedList(x); 
		}
		// Recursively using the method if none of the conditions are met 
		else
		{

			nextNode->insertAt(x, pos - 1);
		}
	}

}

template<class DT>
void LinkedList<DT>::remove()
{
	// If the data is not null then delete that linked list containing that info and next 
	if (data != NULL)
	{
		delete data;
		LinkedList<DT>* temp = nextNode;
		data = (*temp).data;
		nextNode = (*temp).nextNode;
		(*temp).data = NULL;
		(*temp).nextNode = NULL;

		delete temp;
	}
}

template<class DT>
void LinkedList<DT>::removeAt(int i)
{
	// Uses the remove method if the index is 0 
	if (i == 0)
	{
		 remove(); 
	}
	// Recursively using the method if the position is not 0 
	 (*nextNode).removeAt(i - 1);
	
}

template<class DT>
void LinkedList<DT>::add(DT& x)
{

	if (data == NULL)
	{
		data = new DT(x); 
	}

	// Adds the Element to the list 
	else
	{
		LinkedList<DT>* newList = new LinkedList<DT>(*data, nextNode); 
			(*data) = x; 
			nextNode = newList; 
	}


}

template<class DT>
int LinkedList<DT>::size()
{
	if (nextNode == NULL)
	{
		// If our data is Null return 0 
		if (data == NULL)
		{
			return 0;
		}
		// If not return 1 
		else
		{
			return 1;
		}

	}
	else {
		// Recursviley using the method if none of the conditions are met. 
		return (1 + nextNode->size());
	}

	}


 
template<class DT>
DT & LinkedList<DT>::infoAt(int pos)
{
	// Returns the derefence data object 
	if (pos == 0)
	{
		return (*data); 
	}

	else
	{
		// Recursively using the method if the position isnt 0 
		return nextNode->infoAt(pos - 1); 
	}

}

template<class DT>
DT & LinkedList<DT>::operator[](int pos)
{
	// Returns the data at that index or position 
	 return infoAt(pos); 
	
}

template<class DT>
bool LinkedList<DT>::isEmpty()
{
	// Returns null if the Linked list is empty. 
	return (data == NULL);
}

template<class DT>
DT & LinkedList<DT>::info()
{

	// Accessor method for our pointer object 
	return *(data); 
}

template<class DT>
LinkedList<DT>* LinkedList<DT>::next()
{
	// Accessor method for our linked list pointer 
	return nextNode;
}







Term::Term()
{
}


Term::Term(int a, int b)
{
	coefficient = a; 
	exponent = b; 
}


Term::~Term()
{
}


void Term::setCoeff(int c)
{
	coefficient = c; 
}

void Term::setExpo(int ex)
{
	exponent = ex; 
}


int Term::getCoeff()
{
	return coefficient;
}


int Term::getExpo()
{
	return exponent;
}





Polynomial::Polynomial()
{
	myPoly = new LinkedList<Term>; 


}




Polynomial::~Polynomial()
{
	delete myPoly; 
}

void Polynomial::addTerm(int cof, int exp)
{
	// Boolean for checking 
	bool test = false; 

	for (int i = 0; i < myPoly->size(); i++)
	{
		if (!test)
		{
			// The greater exponent polynomial is inserted first 
			if (exp > (*myPoly).infoAt(i).getExpo())
			{
				Term* temp = new Term(cof, exp);

				(*myPoly).insertAt(*temp, i);

				test = true; 

			}
			// The same exponent polynomial has their coefficients added 
			else if (exp == (*myPoly).infoAt(i).getExpo())
			{

				// Setting the added coeffiecient polynomials 
				(*myPoly).infoAt(i).setCoeff((*myPoly).infoAt(i).getCoeff() + cof);
				(*myPoly).infoAt(i).setExpo(exp);

				test = true; 

			}

		}


	}
	// Inserts all other polynomial 
	if (!test)
	{
		Term* temp3 = new Term(cof, exp);
		myPoly->insertAt(*temp3, (*myPoly).size());



		test = true; 
	}

	}


// Prints out the polynomial 
void Polynomial::printPolynomial()
{

	for (int i = 0; i < (*myPoly).size(); i++)

	{
	
		cout << "( " << (*myPoly).infoAt(i).getCoeff() << " , " << (*myPoly).infoAt(i).getExpo() << " )" << endl; 
	}


}

Polynomial & Polynomial::multiplyPolynomial(Polynomial & ply)
{
	// Polynomial pointer object 
	Polynomial* test = new Polynomial(); 

	// Set the sizes of both polynomials to ints for easier typing 
	int myPlySize = (*myPoly).size(); 
	int plySize = ply.myPoly->size(); 
	// Gets the 1st polynomials coefficients and exponenets.  
	for (int i = 0; i < myPlySize; i++)
	{
		
		int myPolyCoeff = this->myPoly->infoAt(i).getCoeff();
		int myPolyExp = this->myPoly->infoAt(i).getExpo();
		// Gets the 2nd polynomials coeeficient and exponents. 
		for (int j = 0; j < plySize; j++)
		{
			int plyCoeff = ply.myPoly->infoAt(j).getCoeff();
			int plyExp = ply.myPoly->infoAt(j).getExpo();
			// Put the new coeffiecent and exponent values into the pointer object using addTerm method 
			(*test).addTerm(plyCoeff * myPolyCoeff, plyExp + myPolyExp); 
		}

	}
	// Dereferenced pointer object to get the output of the polynomial 
	cout << (*test); 
	return *test; 

}

// Adds polynomials with same exponents 
Polynomial & Polynomial::addPolynomial(Polynomial & ply)
{
	// Pointer Polynomial Object 
	Polynomial* test = new Polynomial();

	int plySize = ply.myPoly->size();
	int myPlySize = (*myPoly).size();
	// Gets the 1st polynomials coefficients and expononets 
	for (int i = 0; i < plySize; i++)
	{
		int plyCoeff = ply.myPoly->infoAt(i).getCoeff();
		int plyExp = ply.myPoly->infoAt(i).getExpo();
		// For if the size of the 2nd polynomial is less than the 1st
		for (int j = 0; j < myPlySize; j++)
		{

			int myPolyCoeff = myPoly->infoAt(j).getCoeff();

			int myPolyExp = myPoly->infoAt(j).getExpo();


		}

		// Puts the 1st polynomials values in this test object 
		test->addTerm(plyCoeff, plyExp);

	}

	// Gets the 2nd polynomials coefficients and exponents 
	for (int i = 0; i < myPlySize; i++)
	{
		int myPolyCoeff = myPoly->infoAt(i).getCoeff();

		int myPolyExp = myPoly->infoAt(i).getExpo();

		// For if the size of the 1st polynomial is less than the 2nd 
		for (int j = 0; j < plySize; j++)
		{
			int plyCoeff = ply.myPoly->infoAt(j).getCoeff();
			int plyExp = ply.myPoly->infoAt(j).getExpo();

			
		}
		// Puts the 2nd polynomials values in this test object. 
		test->addTerm(myPolyCoeff, myPolyExp);
	}
	// Dereferenced test object to see the added polynomial terms. 
	cout << (*test);

	return  *test;
}
int Polynomial::evaluatePoly(int x)
{
	// Size of polynomial 
	int myPlySize = (*myPoly).size();
	// To store the value for x
	int result = 1; 
	// Used to store the result of the polynomial 
	int final = 0; 

	int count = 0; 

	for (int i = 0; i < myPlySize; i++)
	{
		result = 1; 

		int myPolyCoef = (*myPoly).infoAt(i).getCoeff(); 
		int myPolyExpo = (*myPoly).infoAt(i).getExpo(); 

		for (int j = 0; j < myPolyExpo; j++)
		{
			// Acts as an exponent by multiplying by itself 
			result *= x;
		}
	
		// Result of the polynomial 
		final = result * myPolyCoef + final; 
		
	}
	cout << final;
	return final;
}

void Polynomial::deleteTerm(int exp)
{
	int myPolySize = (*myPoly).size(); 

	for (int i = 0; i < myPolySize; i++)
	{
		// If the exponent is the same then set its coefficient at that postion to 0. 
		if (exp == (*myPoly).infoAt(i).getExpo())
		{
			(*myPoly).infoAt(i).setCoeff(0);
		}

	}
}

Polynomial Polynomial::operator+(Polynomial & M)
{
	// Uses the addPolynomial method 
	return addPolynomial(M); 
}

Polynomial Polynomial::operator*(Polynomial & M)
{
	// Uses the MultiplyPolynomial method 
	return multiplyPolynomial(M);
}


// Controls the Operation of the program. 
int main()
{
	// Array of polynomials of 10 
	Polynomial* Polynomials = new Polynomial[10]; 

	// Input variables 
	char command; 
	int polynum; 
	int coefficient; 
	int exponent; 
	int value; 
	int i; 
	int j; 

	cin >> command; 
	while (!cin.eof())
	{
		switch (command)
		{
			// Inserts the polynomial 
		case 'I': cin >> polynum >> coefficient >> exponent; 
		
				Polynomials[polynum].addTerm(coefficient, exponent);

			break; 
		
			// Prints the polynomial 
		case 'P': cin >> polynum; 
		
			cout << Polynomials[polynum]; 

		break;

		// Adds the polynomial 
		case 'A': cin >> i >> j; 
			Polynomials[i] + Polynomials[j]; 
		
			break; 

			// Deletes the polynomial term
		case 'D': cin >> polynum >> coefficient >> exponent; 

			if (exponent)
			{
				Polynomials[polynum].deleteTerm(exponent);
				
			}

			else {

				cout << "There is no term in polynomial " << polynum << " with and exponent of " << exponent;
			}

			break; 
		case 'M': cin >> i >> j; 

			// Multiplies the polynomials 
			Polynomials[i] * Polynomials[j]; 
			
			
			break; 

		case 'E': cin >> polynum >> value; 

			// Evaluates the polynomial with user input value. 
			Polynomials[polynum].evaluatePoly(value); 
			

			break; 
			
			// Default 
		default: cout << "I missed something" << endl; 
		}
		cin >> command; 
	}

	// Deleting pointer after exectution
	delete[]Polynomials; 



	system("pause");
	return 0;
}
