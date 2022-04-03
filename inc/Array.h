#ifndef ARRAY_H
#define ARRAY_H

#include "ArrayBase.h"

template <typename T>
class Array : public ArrayBase<T, Array<T>>
{
    // Member Functions
    public:
        using Base = ArrayBase<T, Array<T>>;
        using Base::operator=;
        // Constructor (rows, cols)
        Array(int rows, int cols) : Base(rows, cols) {}
    private:
    protected:
    // Member Data
    public:
    private:
    protected:
};

template <>
class Array<double> : public ArrayBase<double, Array<double>>

{
    // Member Functions
    public:
        using Base = ArrayBase<double, Array<double>>;
        using Base::operator=;
        // Constructor (rows, cols)
        Array(int rows, int cols) : Base(rows, cols) {}
        // Setter Function: zeros
        void zeros(void)  {Base::set(0.0);};
        // Setter Function: ones
        void ones(void)  {Base::set(1.0);};
        // Setter Function: identity 
        void identity(void);
        // Setter Function: transpose
        void s_transpose(void);
        // Setter Function: s_inverse 
        void s_inverse(void);
        // Setter Function: s_cofactor 
        void s_cofactor(void);
        // Setter Function: s_adjugate 
        void s_adjugate(void);
        // Setter Function: s_minor 
        void s_minor(void);
        // Getter Function: transpose
        Array<double> g_transpose(void);
        // Getter Function: g_inverse 
        Array<double> g_inverse(void);
        // Getter Function: g_cofactor 
        Array<double> g_cofactor(void);
        // Getter Function: g_adjugate 
        Array<double> g_adjugate(void);
        // Getter Function: g_minor 
        Array<double> g_minor(void);
        // Getter Function: determinant 
        double determinant(void);
        // Getter Function: trace
        double trace(void);
        // Arithmetic Operator: *
        Array<double> operator* (const double scalar) const;
        // Arithmetic Operator: *
        Array<double> operator* (const Array<double>& arr) const;
        // Arithmetic Operator: *
        friend Array<double> operator* (const double scalar, const Array<double>& arr)
        {
            return arr * scalar;
        }
    private:
    protected:
    // Member Data
    public:
    private:
    protected:
};

// Set Identity
inline void Array<double>::identity(void)
{
    if (myRows == myCols)
    {
        zeros();
        for (int i = 0; i < myElements; i += (myCols + 1))
        {
            myArray.at(i) = 1.0;
        }
    }
    else
    {
        throw std::length_error("ERROR: Matrix needs to be SQUARE to have an identity\n");
    }
}

// Set Transpose
inline void Array<double>::s_transpose(void)
{
    Array<double> tmp(myCols, myRows);
    // Utilize LAPACKE out-of-place transpose
    LAPACKE_dge_trans( LAPACK_ROW_MAJOR, myRows, myCols, myArray.data(), myCols, tmp.myArray.data(), myRows );
    swap(*this, tmp);
}

// Get Transpose
inline Array<double> Array<double>::g_transpose(void)
{
    Array<double> tmp(*this);
    tmp.s_transpose();
    return tmp;
}

// Set Inverse
inline void Array<double>::s_inverse(void)
{
    int mn = myRows;
    std::vector<int> ipiv(mn);
    // Utilize LAPACKE LU Factorization
    int info = LAPACKE_dgetrf( LAPACK_ROW_MAJOR, mn, mn, myArray.data(), mn, ipiv.data() );
    // INFO < 0: if INFO = -i, the i-th argument had an illegal value
    // INFO > 0: if INFO = i, U(i,i) is exactly zero. The factorization 
    //           has been completed, but the factor U is exactly
    //           singular, and division by zero will occur if it is used
    //           to solve a system of equations.
    if ( info != 0 )
    {
        throw std::invalid_argument("ERROR:\n"
                                    "INFO < 0 in setInverse: if INFO = -i, the i-th argument had an illegal value.\n"
                                    "INFO > 0 in setInverse: if INFO = i, U(i,i) is exactly zero. The factorization " 
                                    "has been completed, but the factor U is exactly singular, and division by zero will "
                                    "occur if it is used to solve a system of equations.\nINFO = " + 
                                    std::to_string(info) + "\n");
    }
    
    info = LAPACKE_dgetri( LAPACK_ROW_MAJOR, mn, myArray.data(), mn, ipiv.data() );
    
    if ( info != 0 )
    {
        throw std::invalid_argument("ERROR:\n"
                                    "INFO < 0 in getInverse: if INFO = -i, the i-th argument had an illegal value.\n"
                                    "INFO > 0 in getInverse: if INFO = i, U(i,i) is exactly zero; the matrix is " 
                                    "singular and its inverse could not be computed.\nINFO = " + 
                                    std::to_string(info) + "\n");
    }
}

// Get Inverse
inline Array<double> Array<double>::g_inverse(void)
{
    Array<double> tmp(*this);
    int mn = tmp.myRows;
    std::vector<int> ipiv(mn);
    // Utilize LAPACKE LU Factorization
    int info = LAPACKE_dgetrf( LAPACK_ROW_MAJOR, mn, mn, tmp.myArray.data(), mn, ipiv.data() );
    // INFO < 0: if INFO = -i, the i-th argument had an illegal value
    // INFO > 0: if INFO = i, U(i,i) is exactly zero. The factorization 
    //           has been completed, but the factor U is exactly
    //           singular, and division by zero will occur if it is used
    //           to solve a system of equations.
    if ( info != 0 )
    {
        throw std::invalid_argument("ERROR:\n"
                                    "INFO < 0 in getInverse: if INFO = -i, the i-th argument had an illegal value.\n"
                                    "INFO > 0 in getInverse: if INFO = i, U(i,i) is exactly zero. The factorization " 
                                    "has been completed, but the factor U is exactly singular, and division by zero will "
                                    "occur if it is used to solve a system of equations.\nINFO = " + 
                                    std::to_string(info) + "\n");
    }
    
    info = LAPACKE_dgetri( LAPACK_ROW_MAJOR, mn, tmp.myArray.data(), mn, ipiv.data() );
    
    if ( info != 0 )
    {
        throw std::invalid_argument("ERROR:\n"
                                    "INFO < 0 in getInverse: if INFO = -i, the i-th argument had an illegal value.\n"
                                    "INFO > 0 in getInverse: if INFO = i, U(i,i) is exactly zero; the matrix is " 
                                    "singular and its inverse could not be computed.\nINFO = " + 
                                    std::to_string(info) + "\n");
    }
    return tmp;
}

// Set Adjugate
inline void Array<double>::s_adjugate(void)
{
    double det = determinant();
    s_inverse();
    *this = det * (*this);
}

// Get Adjugate
inline Array<double> Array<double>::g_adjugate(void)
{
    Array<double> tmp(*this);
    tmp.s_adjugate();
    return tmp;
}

// Set Cofactor
inline void Array<double>::s_cofactor(void)
{
    s_adjugate();
    s_transpose();
}

// Get Cofactor
inline Array<double> Array<double>::g_cofactor(void)
{
    Array<double> tmp(*this);
    tmp.s_cofactor();
    return tmp;
}

// Set Minor
inline void Array<double>::s_minor(void)
{
    s_cofactor();
    for (int i = 0; i < myElements; i++)
    {
        if (i % 2 != 0)
        {
            myArray.at(i) *= -1;
        }
    }
}

// Get Minor
inline Array<double> Array<double>::g_minor(void)
{
    Array<double> tmp(*this);
    tmp.s_minor();
    return tmp;
}

// Get Determinant
inline double Array<double>::determinant(void)
{
    if (myRows == myCols)
    {
        Array<double> tmp(*this);
        int mn = tmp.myRows;
        std::vector<int> ipiv(mn);
        // Utilize LAPACKE LU Factorization
        int info = LAPACKE_dgetrf( LAPACK_ROW_MAJOR, mn, mn, tmp.myArray.data(), mn, ipiv.data() );
        // INFO < 0: if INFO = -i, the i-th argument had an illegal value
        // INFO > 0: if INFO = i, U(i,i) is exactly zero. The factorization 
        //           has been completed, but the factor U is exactly
        //           singular, and division by zero will occur if it is used
        //           to solve a system of equations.
        if ( info != 0 )
        {
            throw std::invalid_argument("ERROR:\n" 
                                        "INFO < 0 in getDeterminant: if INFO = -i, the i-th argument had an illegal value.\n"
                                        "INFO > 0 in getDeterminant: if INFO = i, U(i,i) is exactly zero. The factorization " 
                                        "has been completed, but the factor U is exactly singular, and division by zero will "
                                        "occur if it is used to solve a system of equations.\nINFO = " + 
                                         std::to_string(info) + "\n");
        }
        else
        {
            // Calculate Determinant
            double det = 1.0;
            for( int i = 0; i < mn; i++ )
            {
                if ( i != ipiv[ i ] - 1 )
                {
                    det *= -tmp(i,i);
                }
                else
                {
                    det *= tmp(i,i);
                }
            }
            return det;
        }
    }
    else
    {
        throw std::length_error("ERROR: Matrix needs to be SQUARE to have a determinant\n");
    } 
}

// Get Trace
inline double Array<double>::trace(void)
{
    if (myRows == myCols)
    {
        double tmp = 0.0;
        for (int i = 0; i < myElements; i += (myCols + 1))
        {
            tmp += myArray.at(i);
        }
        return tmp;
    }
    else
    {
        throw std::length_error("ERROR: Matrix needs to be SQUARE to have a trace\n");
    }
}

// Overload "*" Operator (Array*Array)
inline Array<double> Array<double>::operator* (const Array<double>& arr) const
{
    int m = myRows;
    int n = arr.myCols;
    int k = myCols;
    if ( k == arr.myRows )
    {
        Array<double> tmp(m, n);
        // Utilize cblas matrix-matrix multiply
        cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                    m, n, k, 1.0, myArray.data(), k, arr.myArray.data(), n, 0.0, tmp.myArray.data(), n); 
        return tmp;
    }
    else
    {
        throw std::length_error("ERROR: Array operation [*] size mismatch.\n");
    }
}

// Overload "*" Operator (lhs: Array*Scalar)
inline Array<double> Array<double>::operator* (const double scalar) const
{
    Array<double> tmp(myRows, myCols);
    for (int i = 0; i < myElements; i++)
    {
        tmp.myArray.at(i) = myArray.at(i) * scalar;
    }
    return tmp;
}

#endif