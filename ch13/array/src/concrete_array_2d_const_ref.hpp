// Define the ConcreteArray2dConstRef class template

#pragma once

#include <stdexcept>

#include "concrete_array_shape.hpp"

// #####################################################################################################################

// forward declarations
template <class Subscriptor, class T> class ConcreteArray2d;
template <class Subscriptor, class T> class ConcreteArray2dRef;

/**
 * ConcreteArray2dConstRef is the base class for constant concrete array references.
 *
 * @tparam Subscriptor
 * @tparam T
 */
template <class Subscriptor, class T>
class ConcreteArray2dConstRef :
    private Subscriptor {  // using template parameter in private inheritance!

    public:

        // elevate desired private member functions
        using Subscriptor::dim;
        using Subscriptor::shape;
        using Subscriptor::length;
        using Subscriptor::offset;

        // Typdefs #################################################################################

        typedef T ElementT;
        typedef Subscriptor SubscriptorT;

        // typedef ConstConcreteArrayProjection1d<Subscriptor, T> ConstProjectionT;

        // typedef ArrayBrowser2d<ConcreteArray2dConstRef<Subscriptor, T>> BrowserType;

        // Member functions ########################################################################

        /**
         * Get member element by subscript indices
         *
         * @param i index along the first dimension
         * @param j index along the second dimension
         *
         * @return reference to data at index
         */
        const T& operator()(Subscript i, Subscript j) const;

        /**
         * Get the subscriptor object
         */
        Subscriptor subscriptor() const;

        /**
         * Get pointer to the constant data origin
         */
        const T* first_datum() const;

        // define projection methods

        /**
         * Compute projection, or slice, of array.
         *
         * The projection is taken along a given index of the array. In numpy, an equivalent syntax would be
         * array[i, :] for the ith row projection, or array[:, i] for the ith column projection.
         *
         * @param s index along which to compute projection
         * @param d dimension along which to compute projection
         *
         * @return const array projection
         */
        // ConstProjectionT project(Subscript s, Dimension d) const;

        /**
         * Compute row projection, or slice, of array.
         *
         * @param s index along which to compute projection
         *
         * @return const array row projection
         */
        // ConstProjectionT operator[](Subscript s) const;

        /**
         * Compute row projection, or slice, of array.
         *
         * @param s index along which to compute projection
         *
         * @return const array row projection
         */
        // ConstProjectionT row(Subscript i) const;

        /**
         * Compute column projection, or slice, of array.
         *
         * @param s index along which to compute projection
         *
         * @return const array column projection
         */
        // ConstProjectionT column(Subscript j) const;

    protected:

        // Constructor
        // Declae protected so only derived classes can access it
        ConcreteArray2dConstRef(Subscriptor s, const T* p);
        // TODO: understand why the arguments are different here...
        // TODO: why is Subscriptor passed by value, and pointer const

        friend ConcreteArray2dRef<Subscriptor, T>;
        friend ConcreteArray2d<Subscriptor, T>;

    protected:


    private:

        // Assignment operator
        // Declare private so compiler does not create one - no definition needed
        void operator=(const ConcreteArray2dConstRef<Subscriptor, T>&);

        const T* const data_;

};

// Implementation ######################################################################################################

// Member functions ################################################################################

template <class Subscriptor, class T>
inline
const T& ConcreteArray2dConstRef<Subscriptor, T>::operator()(Subscript i, Subscript j) const {
    return first_datum()[offset(SubscriptArray<2>(i, j))];
}

template <class Subscriptor, class T>
inline
Subscriptor ConcreteArray2dConstRef<Subscriptor, T>::subscriptor() const {
    return *this;
}

template <class Subscriptor, class T>
inline
T const* ConcreteArray2dConstRef<Subscriptor, T>::first_datum() const {
    return data_;
}

// template <class Subscriptor, class T>
// inline
// ConcreteArray2dConstRef<Subscriptor, T>::ConstProjectionT
// ConcreteArray2dConstRef<Subscriptor, T>::operator[](Subscript s) const {
//     return project(s, 0);
// }
//
// template <class Subscriptor, class T>
// inline
// ConcreteArray2dConstRef<Subscriptor, T>::ConstProjectionT
// ConcreteArray2dConstRef<Subscriptor, T>::row(Subscript i) const {
//     return project(i, 0);
// }
//
// template <class Subscriptor, class T>
// inline
// ConcreteArray2dConstRef<Subscriptor, T>::ConstProjectionT
// ConcreteArray2dConstRef<Subscriptor, T>::column(Subscript j) const {
//     return project(j, 1);
// }

// Protected methods  ##############################################################################

template <class Subscriptor, class T>
inline
ConcreteArray2dConstRef<Subscriptor, T>::ConcreteArray2dConstRef(Subscriptor s, const T* p) :
    Subscriptor(s),
    data_(p) {
}
