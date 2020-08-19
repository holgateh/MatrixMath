#include "../include/MatrixHelper.hpp"
#include "../include/Polynomial.hpp"

size_t getLeadingEntryColumn(size_t i, const Matrix<double>& m)
{
    size_t result = -1;
    for (size_t j = m.width; j > 0; j--)
    {
        if (m.getEntry(i,j) != 0)
        {
            result = j;
        }
    }
    return result;
}

bool isLeadingEntry(size_t i, const Matrix<double>& m)
{
    bool result = false;
    for (size_t j = i; j > 0; j--) 
    {
        if (abs(m.getEntry(j, i)) != 0)
        {
            result = true;
            size_t k;
            for (k = i-1; k > 0; k--)
            {
                if(m.getEntry(j, k) != 0)
                {
                    result = false;
                    break;
                }
            }
        }
    }

    return result;
}

std::vector<Matrix<double>> getKernel(const Matrix<double>& m)
{
    //kernel vector width = 1;
    //kernel vector height = rref.width;
    std::vector<Matrix<double>> result = std::vector<Matrix<double>>();
    auto rref = getReducedEchelonForm(m); 

    for (size_t i = rref.width; i > 0; i--)
    {
        if (!isLeadingEntry(i, rref))
        {
            Matrix<double> vector = Matrix<double>(rref.width, 1);
            vector.setEntry(i,1,1.0);
            for (size_t j = rref.height; j > 0; j--)
            {
                if (rref.getEntry(j,i) != 0)
                {
                    vector.setEntry(getLeadingEntryColumn(j, rref),1, -rref.getEntry(j,i));
                }
            }
            result.push_back(vector);
        }
    }
    return result;

}

std::vector<double> getEigenValues(const Matrix<double>& m)
{
	if(m.width != m.height)
	{
        throw std::runtime_error("Error: Can only caculate eigenvalues of square matrices.");
	}

	//Create Matrix M - X*I
    Matrix<Polynomial> p = Polynomial({0, -1}) * Matrix<Polynomial>::createIdentity(m.height);
	auto detMatrix = convertMatrix(m) + p;

	//Calculate the determinant of the above matrix to get the characteristic polynomial.

	Polynomial characteristic = detMatrix.det();
	//return the roots of this equation: the eigenvalues of m
    std::cout << "Characteristic: " << characteristic << "\n";
	return getRoots(characteristic); 
	
}

Matrix<Polynomial> convertMatrix(const Matrix<double>& m)
{

    auto result = Matrix<Polynomial>(m.height, m.width);

	for(size_t i = 1; i <= m.height; i++)
	{
		for(size_t j = 1; j <= m.width; j++)
		{
		    result.setEntry(i, j, Polynomial({m.getEntry(i,j)}));
		}
	}
	return result;
}

template <class T>
void swapRows(size_t i, size_t j, Matrix<T>& m)
{
    if (i == j)
    {
        return;
    }

    for (size_t k = 1; k <= m.width; k++)
    {
        T temp = m.getEntry(i, k);
        m.setEntry(i, k, m.getEntry(j, k));
        m.setEntry(j, k, temp);
    }
}

template <class T>
void addRow(size_t i, size_t j, T scale, Matrix<T>& m)
{
    for (size_t k = 1; k <= m.width; k++)
    {
        m.setEntry(i,k, m.getEntry(i,k) + m.getEntry(j,k) * scale);
    }
}

template <class T>
void scaleRow(size_t i, T scale, Matrix<T>& m)
{
    for (size_t j = 1; j <= m.width; j++)
    {
        m.setEntry(i, j, m.getEntry(i,j) * scale);
    }
}

Matrix<double> getEchelonForm(Matrix<double> m)
{
    size_t i = 1 , j = 1;
    while( i <= m.height)
    {   
        size_t maxRow= i;    
        for (size_t k = i+1; k <= m.height; k++)
        {
           if (abs(m.getEntry(k,j)) > abs(m.getEntry(maxRow, j)))
           {
               maxRow = k;
           }
        }

        if(m.getEntry(maxRow,j) == 0)
        {
            i++;
            j=i;
        }
        else
        {
            swapRows(maxRow, i, m);

            for (size_t k = i+1; k <= m.height; k++)
            {
                addRow(k, i, -(m.getEntry(k,j)/m.getEntry(i,j)), m); 
            } 
            i++;
            j=i;
        }
        
    }

    return m;
}

Matrix<double> getReducedEchelonForm(Matrix<double> m)
{
    Matrix<double> q = getEchelonForm(m);
    for (size_t i = m.height; i > 0; i--)
    {
        size_t j = 1;  
        while (j <= m.width && q.getEntry(i,j) == 0)
        {
            j++;
        }


        if(j <= q.width)
        {
            //scale row
            scaleRow(i,1.0/q.getEntry(i,j), q);
            for(size_t k = i-1; k >= 1; k--)
            {
                addRow(k, j, -(q.getEntry(k,j)/q.getEntry(i,j)), q);
            }
        }
    }
    return q;
}

std::vector<Matrix<double>> getEigenVectors(const Matrix<double>& m)
{
    std::vector<double> eigenValues = getEigenValues(m);
    return getEigenVectors(eigenValues, m);
}
std::vector<Matrix<double>> getEigenVectors(const std::vector<double>& eigenValues, const Matrix<double>& m)
{
    std::vector<Matrix<double>> result = std::vector<Matrix<double>>();

    for (size_t i = 0; i < eigenValues.size(); i++)
    {
        std::vector<Matrix<double>> eigenVectors = getKernel(m - eigenValues[i]*Matrix<double>::createIdentity(m.height));
        result.insert(result.end(), eigenVectors.begin(), eigenVectors.end()); 
    }
    return result;
}
