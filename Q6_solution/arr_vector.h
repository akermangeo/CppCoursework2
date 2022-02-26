#include <iostream>

/// <summary>
/// array-like vector
/// </summary>
class Vector
{

private:
    int nn; // size of array; upper index is nn - 1
    double* v;
public:
    //int nn; // size of array; upper index is nn - 1
    //double* v;

    /// <summary>
    /// empty
    /// </summary>
    Vector();

    /// <summary>
    /// zero-based array
    /// </summary>
    /// <param name="n">size</param>
    explicit Vector(int n) : nn{ n }, v{ new double[nn] } {
        for (int i = 0; i < nn; i++) {
            v[i] = 0.0;
        }
    };

    /// <summary>
    /// initialize to constant value
    /// </summary>
    /// <param name="n">size</param>
    /// <param name="a">constant value</param>
    Vector(int n, double a);

    /// <summary>
    /// TODO:!!!
    /// initialize to array using an array pointer.
    /// It is user responsibility to make sure the array pointer is pointing to an array with propery length.
    /// If length is less than n, you may see a mess array as there is no way to determine the end given a pointer;
    /// If length is larger than n, you will only have the first n elements copyed to yourVector. 
    /// </summary>
    /// <param name="n">size</param>
    /// <param name="a">init array pointer</param>
    Vector(int n, const double* a);

    /// <summary>
    /// copy constructor
    /// </summary>
    /// <param name="rhs">Vector referrence to copy</param>
    Vector(const Vector& rhs);

    /// <summary>
    /// assignment
    /// </summary>
    /// <param name="rhs">vector to assign</param>
    /// <returns></returns>
    Vector& operator=(const Vector& rhs);

    /// <summary>
    /// the i'th element
    /// </summary>
    /// <param name="i">i'th index</param>
    /// <returns></returns>
    inline double& operator[](const int i);

    /// <summary>
    /// return only the value of the i'th element
    /// </summary>
    /// <param name="i"></param>
    /// <returns></returns>
    inline const double& operator[](const int i) const;

    /// <summary>
    /// return the size of the Vector
    /// </summary>
    /// <returns>size</returns>
    inline int size() const;

    /// <summary>
    /// resize (contents not preserved) as a zero vetors.
    /// </summary>
    /// <param name="newn">size of the new Vector</param>
    void resize(int newn);

    /// <summary>
    /// resize and assign a constant value
    /// </summary>
    /// <param name="newn">size of the new Vector</param>
    /// <param name="a">constant value</param>
    void assign(int newn, double a);

    //~Vector();
    void get() {
        std::cout << "nn: " << nn << std::endl;
        for (int i = 0; i < nn; i++) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }
};
