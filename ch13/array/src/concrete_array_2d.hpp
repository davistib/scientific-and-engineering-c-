// Define the ConcreteArray2d class template

#pragma once

#include <stdexcept>
#include <string>

#include "concrete_array_shape.hpp"
#include "concrete_array_2d_const_ref.hpp"
#include "concrete_array_2d_ref.hpp"

// #####################################################################################################################

/**
 * ConcreteArray2d is the base class for concrete arrays.
 *
 * @tparam Subscriptor
 * @tparam T
 */
template <class Subscriptor, class T>
class ConcreteArray2d :
    private Subscriptor {  // using template parameter in private inheritance!

    public:

        // elevate desired private member functions
        using Subscriptor::dim;
        using Subscriptor::shape;
        using Subscriptor::length;
        using Subscriptor::offset;
        using Subscriptor::set_shape;

        // Typdefs #################################################################################

        typedef T ElementT;
        typedef Subscriptor SubscriptorT;

        // typedef ConcreteArrayProjection1d<Subscriptor, T> ProjectionT;
        // typedef ConstConcreteArrayProjection1d<Subscriptor, T> ConstProjectionT;

        // typedef ConcreteArrayBrowser<ConcreteArray2d<Subscriptor, T>> BrowserType;
        // typedef ConcreteArrayIterator<ConcreteArray2d<Subscriptor, T>> IteratorType;

        // Member functions ########################################################################

        /**
         * Get member element by subscript indices
         *
         * @param i index along the first dimension
         * @param j index along the second dimension
         *
         * @return reference to data at index
         */
        T& operator()(Subscript i, Subscript j);

        /**
         * Get member element by subscript indices
         *
         * @param i index along the first dimension
         * @param j index along the second dimension
         *
         * @return const reference to data at index
         */
        const T& operator()(Subscript i, Subscript j) const;

        /**
         * Get the subscriptor object
         */
        Subscriptor subscriptor() const;

        /**
         * Get a pointer to the data origin
         */
        T* first_datum();

        /**
         * Get a constant pointer to the data origin
         */
        T const* first_datum() const;

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
        // ProjectionT project(Subscript s, Dimension d);

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
         * @return array row projection
         */
        // ProjectionT operator[](Subscript s);

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
         * @return array row projection
         */
        // ProjectionT row(Subscript i);

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
         * @return array column projection
         */
        // ProjectionT column(Subscript j);

        /**
         * Compute column projection, or slice, of array.
         *
         * @param s index along which to compute projection
         *
         * @return const array column projection
         */
        // ConstProjectionT column(Subscript j) const;

        // Conversion operators  ###################################################################

        operator ConcreteArray2dRef<Subscriptor, T>();
        operator ConcreteArray2dConstRef<Subscriptor, T>() const;

        // Assignment operators  ###################################################################

        ConcreteArray2d<Subscriptor, T>& operator=(const ConcreteArray2d<Subscriptor, T>& rhs);
        ConcreteArray2d<Subscriptor, T>& operator=(const ConcreteArray2dConstRef<Subscriptor, T>& rhs);
        ConcreteArray2d<Subscriptor, T>& operator=(const T& rhs);

    protected:

        // Constructor
        // Declae protected so only derived classes can access it
        ConcreteArray2d(const Subscriptor& s, T* p);

        void reshape_on_heap(const SubscriptArray<2>& s);
        void set_size_on_heap(Subscript n);

    protected:

        T* data_;

    private:

        // Copy Constructor
        // Declare private so compiler does not create one - no definition needed
        ConcreteArray2d(const ConcreteArray2d<Subscriptor, T>&);

};

// Implementation ######################################################################################################

// Member functions ################################################################################

template <class Subscriptor, class T>
inline
T& ConcreteArray2d<Subscriptor, T>::operator()(Subscript i, Subscript j) {
    return first_datum()[offset(SubscriptArray<2>(i, j))];
}

template <class Subscriptor, class T>
inline
const T& ConcreteArray2d<Subscriptor, T>::operator()(Subscript i, Subscript j) const {
    return first_datum()[offset(SubscriptArray<2>(i, j))];
}

template <class Subscriptor, class T>
inline
Subscriptor ConcreteArray2d<Subscriptor, T>::subscriptor() const {
    return *this;
}

template <class Subscriptor, class T>
inline
T* ConcreteArray2d<Subscriptor, T>::first_datum() {
    return data_;
}

template <class Subscriptor, class T>
inline
T const* ConcreteArray2d<Subscriptor, T>::first_datum() const {
    return data_;
}

// template <class Subscriptor, class T>
// inline
// ConcreteArray2d<Subscriptor, T>::ProjectionT ConcreteArray2d<Subscriptor, T>::operator[](Subscript s) {
//     return project(s, 0);
// }
//
// template <class Subscriptor, class T>
// inline
// ConcreteArray2d<Subscriptor, T>::ConstProjectionT ConcreteArray2d<Subscriptor, T>::operator[](Subscript s) const {
//     return project(s, 0);
// }
//
// template <class Subscriptor, class T>
// inline
// ConcreteArray2d<Subscriptor, T>::ProjectionT ConcreteArray2d<Subscriptor, T>::row(Subscript i) {
//     return project(i, 0);
// }
//
// template <class Subscriptor, class T>
// inline
// ConcreteArray2d<Subscriptor, T>::ConstProjectionT ConcreteArray2d<Subscriptor, T>::row(Subscript i) const {
//     return project(i, 0);
// }
//
// template <class Subscriptor, class T>
// inline
// ConcreteArray2d<Subscriptor, T>::ProjectionT ConcreteArray2d<Subscriptor, T>::column(Subscript j) {
//     return project(j, 1);
// }
//
// template <class Subscriptor, class T>
// inline
// ConcreteArray2d<Subscriptor, T>::ConstProjectionT ConcreteArray2d<Subscriptor, T>::column(Subscript j) const {
//     return project(j, 1);
// }

// Conversion operators  ###########################################################################

template <class Subscriptor, class T>
inline
ConcreteArray2d<Subscriptor, T>::operator ConcreteArray2dRef<Subscriptor, T>() {
    return ConcreteArray2dRef(subscriptor(), data_);
}

template <class Subscriptor, class T>
inline
ConcreteArray2d<Subscriptor, T>::operator ConcreteArray2dConstRef<Subscriptor, T>() const {
    return ConcreteArray2dConstRef(subscriptor(), data_);
}

// Assignment operators  ###########################################################################

template <class Subscriptor, class T>
inline
ConcreteArray2d<Subscriptor, T>& ConcreteArray2d<Subscriptor, T>::operator=(
    const ConcreteArray2d<Subscriptor, T>& rhs
) {
    // create a reference object and use it's assignment operator
    ConcreteArray2dRef<Subscriptor, T>(*this) = rhs;
    return *this;
}

template <class Subscriptor, class T>
inline
ConcreteArray2d<Subscriptor, T>& ConcreteArray2d<Subscriptor, T>::operator=(
    const ConcreteArray2dConstRef<Subscriptor, T>& rhs
) {
    // create a reference object and use it's assignment operator
    ConcreteArray2dRef<Subscriptor, T>(*this) = rhs;
    return *this;
}

template <class Subscriptor, class T>
inline
ConcreteArray2d<Subscriptor, T>& ConcreteArray2d<Subscriptor, T>::operator=(const T& rhs) {
    // create a reference object and use it's assignment operator
    ConcreteArray2dRef<Subscriptor, T>(*this) = rhs;
    // std::cout << "in copy assignment..." << std::endl;
    return *this;
}

// NOTE: can implement operators directly if performance hit from making temporary reference

// Protected methods  ##############################################################################

template <class Subscriptor, class T>
inline
ConcreteArray2d<Subscriptor, T>::ConcreteArray2d(const Subscriptor& s, T* p) :
    Subscriptor(s),
    data_(p) {
}

template <class Subscriptor, class T>
void ConcreteArray2d<Subscriptor, T>::reshape_on_heap(const SubscriptArray<2>& s) {
    this->set_shape(s);
    this->set_size_on_heap(this->length());
}

template <class Subscriptor, class T>
void ConcreteArray2d<Subscriptor, T>::set_size_on_heap(Subscript n) {
    // if (n < 0) throw std::exception(std::string("Negative size."));
    if (n < 0) {
        throw std::runtime_error(std::string("Negative size."));
    }
    delete[] data_;
    data_ = new T[n];
}
