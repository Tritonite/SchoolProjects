#include <iostream>
#include <vector>
using namespace std;
/**
In this Project, we are building up from our project 1 by adding more implementations. 
These implementations include using  templates, vector class, overloading operators to preform our sparse row matrix functions, 
and using exceptions. 

@author Triston Luzanta 
@version 2/25/2019



**/

// This exception class is used for matrix addition. If the dimenensions of the matrices are not the same then this exception will be thrown. 
template<class DT>
class ExceptionAdd {};

/*
This exception class is used for matrix multiplication. If the column of the first matrix doest not match the row of the second column, 
then this exception will be thrown. 
*/
template<class DT>
class ExceptionMultiply {};

/*
This exception class is used for common value. If both matrices do not share the same common value then this exception will be thrown. 
*/
template<class DT>
class ExceptionCV {};

/*
Sparse Row setup 
*/
template <class DT>
class SparseRow
{
protected: 

	int row; 
	int col; 
	DT value; 

public:

	SparseRow(); 
	SparseRow(int r, int c, DT& v); 
	virtual ~SparseRow(); // Destructor
	void display(); 
	void setRow(int n); // Sets the row
	int getRow(); // Return row input 
	void setColumn(int m); // Sets the Column 
	int getColumn(); // Return Column input 
	void setValue(DT val); // Sets the nonSparse Value
	DT getValue(); // Return the nonSparse Value 

};

template <class DT> 
class SparseMatrix
{


protected:

	int noRows;
	int noCols;
	int commonValue;
	int nonSparseValues;
    vector<SparseRow<DT> >* myMatrix; // Array - should be dynamic 

public:

	SparseMatrix(); 
	SparseMatrix(int n, int m, int cv); 
	virtual  ~SparseMatrix(); // Destructor 

	void setSparseRow(int pos, int r, int c, DT& v); // Sets the SparseRow position 

	void display(); // Displays Sparse Matrix 
	void displayMatrix(); // Display the Matrix in original format 

	int getSparseVal(int noRows, int noCols); // Returns the value in that row and column 
	

	void setNoRows(int matrixRow); // Sets the # of rows 
	int getNoRows(); // Returns the # of row 
	void setNoCols(int matrixCol); // Sets the # of columns 
	int getNoCols(); //  Returns the # of columns 
	void setCommonValue(int matrixCV); // Sets the common value 
	int getCommonValue(); // Returns the common value 
	void setNonSV(int matrixNCV); // Sets the number of non sparse values 
	int getNonSV(); // Returns the # of non sparse values 
	
	SparseMatrix<DT>* Multiply(SparseMatrix<DT>& M); // Multiplies the two matrices
	SparseMatrix<DT>* Add(SparseMatrix<DT>& M); // Adds the two matrices 
	
	// The ostream operator allows us to display the matrix in sparse row format. 
	friend ostream& operator<<(ostream& os, const SparseMatrix <DT>& M)
	{
		for (int i = 0; i < M.myMatrix->size(); i++)
		{
			M.myMatrix->at(i).display(); 
		}

		return os; 
	}
		
	
	SparseMatrix<DT>* operator!(); // ! sign function for transposing matrices 
	SparseMatrix<DT>* Transpose(); // Method for tranposing the matrices 
	SparseMatrix<DT>* operator+(SparseMatrix<DT>& M); // + sign function for add matrices 
	SparseMatrix<DT>* operator*(SparseMatrix<DT> &M); // * sign function for multiplying matrices 
	
	

};

template<class DT>
SparseMatrix<DT>::SparseMatrix()
{
	 

}

/*
This method sets the postion for myMatrix 
*/
template<class DT>
void SparseMatrix<DT>::setSparseRow(int pos, int r, int c, DT & v)
{
	SparseRow<DT> P =  SparseRow<DT>(); 

	P.setRow(r); 
	P.setColumn(c); 
	P.setValue(v); 
	
	myMatrix->insert(myMatrix->begin() + pos, P); 

	
	


}


template<class DT>
SparseMatrix<DT>::SparseMatrix(int n, int m, int cv)
{
	int currSize = 0; 
	 noRows = n; 
	 noCols = m; 
	 commonValue = cv; 
	 myMatrix = new vector <SparseRow<DT>> (currSize); 

}
/*
SparseMatrix destructor 
*/
template<class DT>
SparseMatrix<DT>::~SparseMatrix()
{
	delete myMatrix; 

}
/*
* operator function for multiplying matrices 
*/
template<class DT>
SparseMatrix<DT>* SparseMatrix<DT>::operator*(SparseMatrix<DT> &M)
{
	/*
	If the number of rows and columns are equal then the multiply exception is thrown. 
	*/
	if (this->getNoCols() != M.getNoRows())
	{
		throw ExceptionMultiply<DT>();
		
	}
	/*
	Commonvalue exception is thrown if the condition is met 
	*/
	if (M.commonValue != commonValue)
	{
		throw ExceptionCV<DT>(); 
	
	}
	/*
	Returns the multiplied function. 
	*/
	else
	{
	
	return Multiply(M);
}
}

/*
 Displays the sparse matrix. 
*/
template<class DT>
void SparseMatrix<DT>::display()
{
	for (int i = 0; i < myMatrix->size(); i++)
	{
		if (myMatrix->at(i).getValue() != commonValue)
		{	
			myMatrix->at(i).display();
		}
			
	}
}

/*
Displays the matrix normally. 
*/
	template<class DT>
	void SparseMatrix<DT>::displayMatrix()
	{
		bool test = false;

		for (int i = 0; i < noRows; i++)
		{

			for (int j = 0; j < noCols; j++)
			{
				for (int q = 0; q < myMatrix->size(); q++)
				{
					if ((myMatrix->at(q).getRow() == i) && (myMatrix->at(q).getColumn() == j))
					{
						// If true print the non common value
						test = true;
						cout << myMatrix->at(q).getValue() << " ";
					}
				}

				if (!test)
				{
					// If not true print the common Value 
					cout << commonValue << " ";
				}
				
				test = false;
			}

			cout << endl;
		}

	}








	/*
	Method for getting the value 
	*/
template<class DT>
int SparseMatrix<DT>::getSparseVal(int nRows, int nCols)
{

	int q = 0; // initialized counter 
	int p = commonValue; // Sets to the common value if there is no match 

	for (int i = 0; i < noRows; i++)
	{

		for (int j = 0; j < noCols; j++)
		{

			for (int q = 0; q < myMatrix->size(); q++)
			{
				if ((myMatrix->at(q).getRow() == nRows) && (myMatrix->at(q).getColumn() == nCols))
				{
					// P is no assigned to the value if there is a match 
					p = myMatrix->at(q).getValue(); 
				}
			}
		}

	}
	return p; 
}


	

template<class DT>
void SparseMatrix<DT>::setNoRows(int matrixRow)
{
	noRows = matrixRow; 
}

template<class DT>
int SparseMatrix<DT>::getNoRows()
{
	return noRows;
}

template<class DT>
void SparseMatrix<DT>::setNoCols(int matrixCol)
{
	noCols = matrixCol; 
}

template<class DT>
int SparseMatrix<DT>::getNoCols()
{
	return noCols;
}

template<class DT>
void SparseMatrix<DT>::setCommonValue(int matrixCV)
{
	commonValue = matrixCV; 
}

template<class DT>
int SparseMatrix<DT>::getCommonValue()
{
	return commonValue;
}

template<class DT>
void SparseMatrix<DT>::setNonSV(int matrixNCV)
{
	nonSparseValues = matrixNCV; 
}

template<class DT>
int SparseMatrix<DT>::getNonSV()
{
	return nonSparseValues;
}

/*
Method for multiplying the matrices 
*/
template<class DT>
SparseMatrix<DT>* SparseMatrix<DT>::Multiply(SparseMatrix<DT>  &M)
{
	SparseMatrix<DT>* testM = new SparseMatrix<DT>(noRows, noCols, commonValue);

	int q = 0;

	for (int i = 0; i < noRows; i++)
	{
		for (int j = 0; j < M.noCols; j++)
		{

			// This loop sets the values for the multiplication process. 
			for (int k = 0; k < noCols; k++)
			{
				
				DT c = ((*testM).getSparseVal(i, j)) + (getSparseVal(i, k) * M.getSparseVal(k, j));

				SparseRow<DT> testL = SparseRow<DT>(i, j, c);
				
				if (k == 0)
				{ 
					testM->myMatrix->push_back(testL);
				
				}
			}

			q++;
		}		
	}
	return testM;

}

/*
Method to add the matrices 
*/
template<class DT>
SparseMatrix<DT>* SparseMatrix<DT>::Add(SparseMatrix<DT>& M)
{
	// initialized counter
	int q = 0;
	int r = 0; 

	// Created a sparseMatrix pointer object to store our values. 
	
	SparseMatrix<DT>* mObject = new SparseMatrix<DT>(noRows, noCols, commonValue); 

	// Gets our value from both matrices. If the number of rows and columns match, the value is retrieved. 
	for (int i = 0; i < noRows; i++)
	{
		for (int j = 0; j < noCols; j++)
		{
			// Adds the two matrices values together 
	    r = ((M.getSparseVal(i, j) + this->getSparseVal(i, j)));

			// Store the value in that specific position and will continue on the matrix to see if there are more matches. 
		mObject->setSparseRow(q,i,j,r);

		
		q++; 

		}

		
	}

	// Returns the summed values
	return mObject;
}

/*
! function for tranpsose. 
*/
template<class DT>
SparseMatrix<DT>* SparseMatrix<DT>::operator!()
{
	// uses the transpose method to return 
	return this->Transpose(); 
	
}

/*
Method for transposing the matrices. 
*/
template<class DT>
SparseMatrix<DT>* SparseMatrix<DT>::Transpose()
{
	// SparseMatrix pointer object created to store the rows, columns, and value
	SparseMatrix<DT>* mTest = new SparseMatrix<DT>(noRows, noCols, commonValue);
	// intialized for future assigning
	int p, q, r;
	// For each iteration, myMatrix will store the row, column, and value number. 
	for (int i = 0; i < myMatrix->size(); i++)
	{
		p = myMatrix->at(i).getRow(); 
		q = myMatrix->at(i).getColumn(); 
		r = myMatrix->at(i).getValue(); 


		// Stores and swaps the rows and columns
		mTest->setSparseRow(i, q, p, r); 
	}

	// Returns the swapped values 
	return mTest;

}

/*
+ function method for adding the matrices. 
*/
template<class DT>
SparseMatrix<DT>* SparseMatrix<DT>::operator+(SparseMatrix<DT> & M)
{
	/*
	Addition exception is thrown if these conditions are met
	*/
	if ((M.noCols != noCols) || (M.noRows != noRows))
	{
		throw ExceptionAdd<DT>(); 
	}

	/*
	Commonvalue exception is thrown if ese conditions are met 
	*/
	if (commonValue != M.commonValue)
	{
		throw ExceptionCV<DT>(); 
	}

	else
	{
		// Return the added matrices 
		return Add(M);

	}
}




template<class DT>
SparseRow<DT>::SparseRow()
{
	row = -1; 
	col = -1; 
	value = 0; 
}

template<class DT>
SparseRow<DT>::SparseRow(int r, int c, DT & v)
{
	row = r; 
	col = c; 
	value = v; 

}
/*
SparseRow destructor 
*/
template<class DT>
SparseRow<DT>::~SparseRow()
{
  
}

/*
Sparse row display format 
*/
template<class DT>
void SparseRow<DT>::display()
{
	cout << row << "," << col << "," << value << endl; 
}

template<class DT>
void SparseRow<DT>::setRow(int n)
{
	row = n; 
}

template<class DT>
int SparseRow<DT>::getRow()
{
	return row;
}

template<class DT>
void SparseRow<DT>::setColumn(int m)
{
	col = m; 
}

template<class DT>
int SparseRow<DT>::getColumn()
{
	return col;
}

template<class DT>
void SparseRow<DT>::setValue(DT val)
{
	value = val; 
}

template<class DT>
DT SparseRow<DT>::getValue()
{
	return value;
}





/*
Controls operation of program 
*/
int main()
{

// User inputs

	int n;
	int m;
	int cv;
	int v;

	SparseMatrix<int>* temp;

	int position = 0; 
	int position2 = 0; 
	cin >> n >> m >> cv;
	SparseMatrix<int>* firstOne = new SparseMatrix<int>(n, m, cv);

	// For the Sparse matrix format, if the value is not common then this method will store its row, column, and value.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v;
			if (v != cv)
			{

				firstOne->setSparseRow(position, i, j, v); 
				// Incrementing to see if there are more values that are not common.
				position++;

			}
		}


	}

	
	cin >> n >> m >> cv;
	SparseMatrix<int>* secondOne = new SparseMatrix<int>(n, m, cv);

	// For the Sparse matrix format, if the value is not common then this method will store its row, column, and value.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v;
			if (v != cv)
			{

				secondOne->setSparseRow(position2, i, j, v);
				// Incrementing to see if there are more values that are not common.
				position2++;
				// incrementing the position of the secondOne. 
			}
		}


	}



	cout << "First one in sparse matrix format" << endl;
	cout << (*firstOne); 
	
	cout << "First one in the normal matrix format" << endl;
	firstOne->displayMatrix(); 
	
	
	temp = !(*firstOne);
	cout << "After Transpose first one in normal format" << endl; 
	temp->displayMatrix(); 
	
	cout << "Second one in sparse matrix format" << endl;
	cout << (*secondOne); 
	
	cout << "Second one in the normal matrix format" << endl;
	secondOne->displayMatrix();
	
	temp = !(*secondOne);
	cout << "After Transpose second one  in normal format" << endl;
	temp->displayMatrix(); 
	
   cout << "Multiplication in sparse matrix form" << endl; 

   // These booleans are used for whether the displays should be up or not if the exceptions are thrown or not. 
   bool test = false; 
   bool test2 = false; 

	try
	{
		
		temp = (*secondOne) * (*firstOne);
	}
	catch(ExceptionMultiply<int> e)
	{
		test = true; 
		cout << "First column of first matrix does not match second row of second matrix (Multiplication)" << endl; 
	}

	catch (ExceptionCV<int> e)
	{
		test = true; 
		cout << "Common Value does not match" << endl; 

	}
	
	if (!test)
	{
		(*temp).display();
	}
	
	
	cout << "Addition of matrices in sparse matrix form:" << endl;
	try
	{		
	temp = (*secondOne) + (*firstOne);
	}
	
	catch (ExceptionAdd<int> e)
	{
		test2 = true; 
		cout << "Matrices dimensions do not match (Addition Error)" << endl; 
	}

	catch (ExceptionCV<int> e)
	{
		test2 = true; 
		cout << "Common Value does not match" << endl; 
	}
	if (!test2)
	{
		(*temp).display();

	}

	system("pause");
	return 0;

}




