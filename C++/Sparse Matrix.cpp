/**

Project 1: 
	The Goal of this project is to display 2 matrices and apply functions to them. One displayed in normal format and the other in a Sparse Matrix format. 
	Once the displays are  working, we can then proceed to apply functions specifically for the Sparse Matrix format. These functions consist of 
	transposing, adding, and multiplying the formatted sparse matrix. 

@author Triston Luzanta

@version 2/6/19


*/


#include <iostream>
using namespace std;

/*
This class keeps track of formatting the Sparse Matrix. 
*/
class SparseRow
{
protected: 

	int row; // Row #
	int col; // Column #
	int value; // Assume that all our values will be integers 
	
public: 

	SparseRow(); // Default Constructor 
	void display(); // Displays sparse row 
	void setRow(int n); // Sets the row
	int getRow(); // Return row input 
	void setColumn(int m); // Sets the Column 
	int getColumn(); // Return Column input 
	void setValue(int val); // Sets the nonSparse Value
	int getValue(); // Return the nonSparse Value 
	
};
/*
Default constructor 
*/
SparseRow::SparseRow()
{
	row = -1; 
	col = -1; 
	value = 0; 
}

/* This displays the sparse rows used in later methods*/
void SparseRow::display()
{
	cout << row << "," << col << "," << value << endl;
}

/* Row setter*/
void SparseRow::setRow(int n)
{
	row = n; 
}
/* Gets the Row value */
int SparseRow::getRow()
{
	return row;
}

/* Column setter*/
void SparseRow::setColumn(int m)
{
	col = m;
}

/* Gets the Column value */
int SparseRow::getColumn()
{
	return col;
}

/* Value setter*/
void SparseRow::setValue(int val)
{
	value = val;
}

/* Gets the value */
int SparseRow::getValue()
{
	return value;
}




/*
This class is responsible for creating the methods for displaying the matrices, and the functions for them. 
*/
class SparseMatrix
{
protected: 
	int noRows; // # of rows of original matrix 
	int noCols; // # of columns of original matrix 
	int commonValue; // common value 
	int noNonSparseValues; // number of nonsparse values 
	
	SparseRow* myMatrix; // Array 
	
public: 
	SparseMatrix(); // Default Constructor 
	SparseMatrix(int n, int m, int cv, int noSCV); // Constructor 
	SparseMatrix* Transpose(); // Transposes the matrix  
	SparseMatrix* Multiply(SparseMatrix& M); // Multiplies two matrices 
	SparseMatrix* Add(SparseMatrix& M); // Adds the two matrices 
	void counterArr(int n, int m, int value, int position); // Keeps track of the myMatrix's values 
	void display(); // Display the sparse matrix 
	void setNoRows(int matrixRow); // Sets the # of rows 
	int getNoRows(); // Returns the # of row 
	void setNoCols(int matrixCol); // Sets the # of columns 
	int getNoCols(); //  Returns the # of columns 
	void setCommonValue(int matrixCV); // Sets the common value 
	int getCommonValue(); // Returns the common value 
	void setNonSV(int matrixNCV); // Sets the number of non sparse values 
	int getNonSV(); // Returns the # of non sparse values 

	int getSparseVal(int noRows, int noCols); // Returns the value in that row and column 
	
	void displayMatrix(); // Displays the normal formatted matrix 
	

	

	


};


/*
 Default constructor 
*/

SparseMatrix::SparseMatrix()
{
	int row = -999; 
	int column = -999; 
	int value = -999; 
}
/*
Another constructor with paramaters. This will allow us to create sparseMatrix objects enabling us to use our methods. 
*/
SparseMatrix::SparseMatrix(int n, int m, int cv, int noNSCV)
{
	noRows = n; 
	noCols = m; 
	commonValue = cv; 
	noNonSparseValues = noNSCV; 
	
	myMatrix = new SparseRow[noNSCV]; 
}
/* Transposes the sparsed matrix */
SparseMatrix * SparseMatrix::Transpose()
{	
	// SparseMatrix pointer object created to store the rows, columns, and value
	SparseMatrix* mTest = new SparseMatrix(noRows, noCols, commonValue, noNonSparseValues); 
	// intialized for future assigning
	int p, q, r; 
	// For each iteration, myMatrix will store the row, column, and value number. 
	for (int i = 0;  i < noNonSparseValues; i++)
	{
		p = myMatrix[i].getRow(); 
		q = myMatrix[i].getColumn(); 
		r = myMatrix[i].getValue();


		// Stores and swaps the rows and columns
		(*mTest).counterArr(q, p, r,i); 
	}

	// Returns the swapped values 
	return mTest; 


}

/* Multiplies the sparse matrices */
SparseMatrix * SparseMatrix::Multiply(SparseMatrix & M)
{
	// Created to SparseMatrix pointer object to temporarily store the parameters. 
	SparseMatrix* testM = new SparseMatrix(noRows, noCols, commonValue, noRows * noCols); 
	// Initialized counter 
	int q = 0; 

	for (int i = 0; i < noRows; i++)
	{
		for (int j = 0; j < M.noCols; j++)
		{
			// Sets the # of rows and columns for the created object 
			(*testM).myMatrix[q].setRow(i); 
			(*testM).myMatrix[q].setColumn(j);
			
			// This loop sets the values for the multiplication process. 
			for (int k = 0; k < noCols; k++)
			{

				// cout was used to test the method to make sure it is working properly. 

				//cout << getSparseVal(i, k) << " i k value " << endl; 
				
				//cout << M.getSparseVal(k, j) << " k, j value" << endl; 
				
				//cout << (*testM).myMatrix[q].getValue() << " Before matrix value" << endl; 
				
				// Store the set values 
				(*testM).myMatrix[q].setValue((*testM).getSparseVal(i,j) + (getSparseVal(i, k) * M.getSparseVal(k, j))); 
			
				//cout << (*testM).myMatrix[q].getValue() << " After matrix value" << endl;
			
			
			
			}
			// incremented each time the myMatrix has found a match. 
			q++; 


		}
	}

	// Returns the multiplied value.
	return testM; 
}

/* 
Add the sparsed matrices
*/
SparseMatrix * SparseMatrix::Add(SparseMatrix & M)
{
	// initialized counter
	int q = 0; 

	// Created a sparseMatrix pointer object to store our values. 
	SparseMatrix* mObject = new SparseMatrix(noRows, noCols, commonValue, noRows * noCols);

	// Gets our value from both matrices. If the number of rows and columns match, the value is retrieved. 
	for (int i = 0; i < noRows; i++)
	{
		for (int j = 0; j < noCols; j++)
		{
			// Adds the two matrices values together 
			M.getSparseVal(i, j) + this->getSparseVal(i, j); 

			// Store the value in that specific position and will continue on the matrix to see if there are more matches. 
			(*mObject).counterArr(i, j, M.getSparseVal(i, j) + this->getSparseVal(i, j), q); 

			q++; 
		}
	}

	// Returns the summed values
	return mObject; 
}
/**
Keeps track of the sparse row position 
*/
void SparseMatrix::counterArr(int n, int m, int value, int position)
{
	// Object created to store the set values 
	SparseRow MM = SparseRow(); 
	
	MM.setRow(n); 
	MM.setColumn(m); 
	MM.setValue(value); 
	// The array now keeps track of the sparseRow, in a similar format to the diplay() method.  
	myMatrix[position] = MM;

}

/* Displays the sparse matrix format.*/
void SparseMatrix::display()
{
	// If a nonSparse value is found myMatrix will store that position, if it's not a common value. 
	for (int i = 0; i < noNonSparseValues; i++)
	{
		if (myMatrix[i].getValue() != commonValue)
		{
			myMatrix[i].display();
		}
		// Uses the sparse row display method to display (row, col, and value)	
	}

}

/*
 Sets the number of rows. 
*/
void SparseMatrix::setNoRows(int matrixRow)
{
	noRows = matrixRow; 
}

/*
Returns the number of rows. 
*/
int SparseMatrix::getNoRows()
{
	return noRows;
}

/*
Sets the number of columns. 
*/
void SparseMatrix::setNoCols(int matrixCol)
{
	noCols = matrixCol; 
}

/*
Returns the number of columns. 
*/
int SparseMatrix::getNoCols()
{
	return noCols;
}

/*
Sets the common value. 
*/
void SparseMatrix::setCommonValue(int matrixCV)
{
	commonValue = matrixCV; 
}

/*
Returns the common value. 
*/
int SparseMatrix::getCommonValue()
{
	return commonValue;
}

/*
Sets the number of non common values. 
*/
void SparseMatrix::setNonSV(int matrixNCV)
{
	noNonSparseValues = matrixNCV; 
}

/*
Returns the number of non common values. 
*/
int SparseMatrix::getNonSV()
{
	return noNonSparseValues;
}

/*
This gives us the myMatrix value 
*/
int SparseMatrix::getSparseVal(int nRows, int nCols)
{
	int q = 0; // initialized counter 
	int p = commonValue; // Sets to the common value if there is no match 

	for (int i = 0; i < noRows; i++)
	{

		for (int j = 0; j < noCols; j++)
		{

			if (myMatrix[q].getRow() == nRows && myMatrix[q].getColumn() == nCols)
			{
				// P is no assigned to the value if there is a match 
				p = myMatrix[q].getValue();

			}

			// Incremented to see if there are more matching 
			q++;
		}
	
	}
	// Returns the value whether it will be common or not 
	return p; 





}



/* Displays normal Matrix */
void SparseMatrix::displayMatrix()
{ 
	// Whether or not the value will be common or non common.
	bool test = false; 

for (int i = 0; i < noRows;  i++)
	{

for (int j = 0; j < noCols; j++)
		{
			for (int q = 0; q < noRows * noCols; q++)
			{
				if (myMatrix[q].getRow() == i && myMatrix[q].getColumn() == j)
				{
					// If true print the non common value
					test = true; 
					cout << myMatrix[q].getValue() << " ";
				}

				
			}

			if (!test)
			{
				// If not true print the common Value 
				cout << commonValue << " "; 
			}
			// Reinitializing 
			test = false; 
		}

		cout << endl; 
}
}








/*
Control operations of the program. 
*/
int main()
{
	// Intialized inputs
	int n; 
	int m; 
	int cv; 
	int noNSV; 
	// Counters for our matrix
	int val; 
	int position = 0; 
	int position2 = 0; 
	
	// Sparsematrix pointer object used to store and display our values and methods. 
	SparseMatrix* temp; 

	// User inputs
	cin >> n >> m >> cv >> noNSV;
     SparseMatrix* firstOne = new SparseMatrix(n, m, cv, noNSV);

	 // For the Sparse matrix format, if the value is not common then this method will store its row, column, and value. 
	 for (int i = 0; i < n; i++)
	 {
		 for (int j = 0; j < m; j++)
		 {
			 cin >> val;
			 if (val != cv)
			 {

				 (*firstOne).counterArr(i, j, val, position);
				 // Incrementing to see if there are more values that are not common. 
				 position++;

			 }
		 }

	
	 }
	

	 // The same as above but with a different counter due to a different pointer object being created. 
	cin >> n >> m >> cv >> noNSV;
	SparseMatrix* secondOne = new SparseMatrix(n, m, cv, noNSV);

	// If the value is not a commonvalue the method will store that values row, column, and value. 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> val;
			if (val != cv)
			{

				(*secondOne).counterArr(i, j, val, position2);
				// Incremented to see if there are more values that not common. 
				position2++;

			}
		}


	}

	// Display the program
	cout << "First one in sparse matrix format" << endl;
	(*firstOne).display();

	cout << "First one in normal matrix format" << endl;
	(*firstOne).displayMatrix();

	cout << "Second one in sparse matrix format" << endl;
	(*secondOne).display();

	cout << "Second one in normal matrix format" << endl;
	(*secondOne).displayMatrix();

	cout << "After Transpose first one in normal format" << endl;
	temp = (*firstOne).Transpose();
	(*temp).displayMatrix();

	cout << "After Transpose second one in normal format" << endl;
	temp = (*secondOne).Transpose();
	(*temp).displayMatrix();

	cout << "Multiplication of matrices in sparse matrix form:" << endl; 
	temp = (*secondOne).Multiply(*firstOne); 
	(*temp).display();  
	
	cout << "Addition of matrices in sparse matrix form:" << endl; 
	temp = (*secondOne).Add(*firstOne);
	(*temp).display();

	// Used for Deaollocating memory 
	delete temp; 
	delete firstOne; 
	delete secondOne; 

	// A way to exit the program by pressing any key 
  system("pause"); 
	return 0;
	
}

