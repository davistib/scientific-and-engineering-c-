// Define the ConcreteArray2dRef class template

#pragma once

#include <stdexcept>
#include <string>

#include "concrete_array_2d.hpp"
#include "concrete_array_shape.hpp"
#include "concrete_array_2d_const_ref.hpp"

// #####################################################################################################################

/**
 * ConcreteArray2dRef is the base class for concrete arrays references.
 *
 * @tparam Subscriptor
 * @tparam T
 */
template <class Subscriptor, class T>
class ConcreteArray2dRef :
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

        // typedef ConcreteArrayProjection1d<Subscriptor, T> ProjectionT;
        // typedef ConstConcreteArrayProjection1d<Subscriptor, T> ConstProjectionT;

        // typedef ArrayBrowser<ConcreteArray2dRef<Subscriptor, T>> BrowserType;
        // typedef ArrayIterator<ConcreteArray2dRef<Subscriptor, T>> IteratorType;

        // Member functions ########################################################################

        /**
         * Get member element by subscript indices
         *
         * @param i index along the first dimension
         * @param j index along the second dimension
         *
         * @return reference to data at index
         */
        T& operator()(Subscript i, Subscript j) const;

        /**
         * Get the subscriptor object
         */
        Subscriptor subscriptor() const;

        /**
         * Get a constant pointer to the data origin
         */
        T* first_datum() const;

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
         * @return array projection
         */
        // ProjectionT project(Subscript s, Dimension d) const;

        /**
         * Compute row projection, or slice, of array.
         *
         * @param s index along which to compute projection
         *
         * @return array row projection
         */
        // ProjectionT operator[](Subscript s) const;

        /**
         * Compute row projection, or slice, of array.
         *
         * @param s index along which to compute projection
         *
         * @return array row projection
         */
        // ProjectionT row(Subscript i) const;

        /**
         * Compute column projection, or slice, of array.
         *
         * @param s index along which to compute projection
         *
         * @return array column projection
         */
        // ProjectionT column(Subscript j) const;

        // Conversion operators  ###################################################################

        /**
         * Convert non-const array reference to a const array reference
         */
        operator ConcreteArray2dConstRef<Subscriptor, T>() const;

        // Assignment operators  ###################################################################

        /**
         * Copy elements from a constant array reference.
         *
         * @param rhs constant reference array to copy assign
         *
         * @return reference to self
         */
        const ConcreteArray2dRef<Subscriptor, T>& operator=(
            const ConcreteArray2dConstRef<Subscriptor, T>& rhs
        ) const;

        /**
         * Copy elements from another array reference.
         *
         * @param rhs reference array to copy assign
         *
         * @return reference to self
         */
        const ConcreteArray2dRef<Subscriptor, T>& operator=(
            const ConcreteArray2dRef<Subscriptor, T>& rhs
        ) const;

        /**
         * Assign all elements to constant value.
         *
         * @param rhs value to assign
         *
         * @return reference to self
         */
        const ConcreteArray2dRef<Subscriptor, T>& operator=(const T& rhs) const;

    protected:

        // Constructor
        // Declae protected so only derived classes can access it
        ConcreteArray2dRef(Subscriptor s, T* p);

        friend ConcreteArray2d<Subscriptor, T>;

    private:

        T* const data_;

};

// Global functions ################################################################################

template <class Shape1, class Shape2, class T>
void concrete_copy(
    const ConcreteArray2dRef<Shape1, T>& lhs,
    const ConcreteArray2dConstRef<Shape2, T>& rhs
);

template <class Shape1, class Shape2, class T>
void concrete_copy(
    ConcreteArray2d<Shape1, T>& lhs,
    const ConcreteArray2d<Shape1, T>& rhs
);

template <class Shape1, class Shape2, class T>
void concrete_copy(
    ConcreteArray2d<Shape1, T>& lhs,
    const ConcreteArray2dConstRef<Shape1, T>& rhs
);

// Implementation ######################################################################################################

// Member functions ################################################################################

template <class Subscriptor, class T>
inline
T& ConcreteArray2dRef<Subscriptor, T>::operator()(Subscript i, Subscript j) const {
    return first_datum()[offset(SubscriptArray<2>(i, j))];
}

template <class Subscriptor, class T>
inline
Subscriptor ConcreteArray2dRef<Subscriptor, T>::subscriptor() const {
    return *this;
}

template <class Subscriptor, class T>
inline
T* ConcreteArray2dRef<Subscriptor, T>::first_datum() const {
    return data_;
}

// template <class Subscriptor, class T>
// inline
// ConcreteArray2dRef<Subscriptor, T>::ProjectionT
// ConcreteArray2dRef<Subscriptor, T>::operator[](Subscript s) const {
//     return project(s, 0);
// }
//
// template <class Subscriptor, class T>
// inline
// ConcreteArray2dRef<Subscriptor, T>::ProjectionT
// ConcreteArray2dRef<Subscriptor, T>::row(Subscript i) const {
//     return project(i, 0);
// }
//
// template <class Subscriptor, class T>
// inline
// ConcreteArray2dRef<Subscriptor, T>::ProjectionT
// ConcreteArray2dRef<Subscriptor, T>::column(Subscript j) const {
//     return project(j, 1);
// }
//
// Conversion operators  ###########################################################################

template <class Subscriptor, class T>
inline
ConcreteArray2dRef<Subscriptor, T>::operator ConcreteArray2dConstRef<Subscriptor, T>() const {
    return ConcreteArray2dConstRef<Subscriptor, T>(*this, data_);
}

// Assignment operators  ###########################################################################

template <class Subscriptor, class T>
const ConcreteArray2dRef<Subscriptor, T>&
ConcreteArray2dRef<Subscriptor, T>::operator=(const ConcreteArray2dConstRef<Subscriptor, T>& rhs) const {
    concrete_copy(*this, rhs);
    return *this;
}

template <class Subscriptor, class T>
const ConcreteArray2dRef<Subscriptor, T>&
ConcreteArray2dRef<Subscriptor, T>::operator=(const ConcreteArray2dRef<Subscriptor, T>& rhs) const {
    // Convert rhs reference to const reference and use its assignment operator
    const ConcreteArray2dConstRef<Subscriptor, T> tmp = rhs;
    return *this = rhs;
}

template <class Subscriptor, class T>
const ConcreteArray2dRef<Subscriptor, T>&
ConcreteArray2dRef<Subscriptor, T>::operator=(const T& rhs) const {
    Subscript n = shape(0);
    while (n -- > 0) {
        (*this)[n] = rhs;  // use projection operator for assignment
    }
}

// Protected methods  ##############################################################################

template <class Subscriptor, class T>
inline
ConcreteArray2dRef<Subscriptor, T>::ConcreteArray2dRef(Subscriptor s, T* p) :
    Subscriptor(s),
    data_(p) {
}

// Global functions ################################################################################

template <class Shape1, class Shape2, class T>
void concrete_copy(
    const ConcreteArray2dRef<Shape1, T>& lhs,
    const ConcreteArray2dConstRef<Shape2, T>& rhs
) {
    Subscript n = lhs.shape(0);
    if (n != rhs.shape(0)) throw std::runtime_error(std::string("Array size mismatch."));
    while (n-- > 0) {
        concrete_copy(lhs[n], rhs[n]);  // NOTE: calling 1D version
    }
}

template <class Shape1, class Shape2, class T>
inline
void concrete_copy(
    ConcreteArray2d<Shape1, T>& lhs,
    const ConcreteArray2d<Shape1, T>& rhs
) {
    concrete_copy(ConcreteArray2dRef<Shape1, T>(lhs), ConcreteArray2dConstRef<Shape2, T>(rhs));
}

template <class Shape1, class Shape2, class T>
inline
void concrete_copy(
    ConcreteArray2d<Shape1, T>& lhs,
    const ConcreteArray2dConstRef<Shape1, T>& rhs
) {
    concrete_copy(ConcreteArray2dRef<Shape1, T>(lhs), rhs);
}
