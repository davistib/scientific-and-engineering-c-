// Define the ConcreteArray1dRef class template

#pragma once

#include <stdexcept>
#include <string>

#include "concrete_array_shape.hpp"
#include "concrete_array_1d_const_ref.hpp"

// #####################################################################################################################

/**
 * ConcreteArray1dConstRef is the base class for 1-dimensional concrete arrays.
 *
 * @tparam Subscriptor
 * @tparam T
 */
template <class Subscriptor, class T>
class ConcreteArray1dRef :
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

        typedef T& ProjectionT;

        // typedef ArrayBrowser1d<ConcreteArray1dRef<Subscriptor, T>> BrowserType;
        // typedef ArrayIterator1d<ConcreteArray1dRef<Subscriptor, T>> IteratorType;

        // Member functions ########################################################################

        /**
         * Get member element by subscript indices
         *
         * @param i index along the first dimension
         *
         * @return const reference to data at index
         */
        T& operator()(Subscript i) const;

        /**
         * Get member element by subscript indices
         *
         * @param i index along the first dimension
         *
         * @return const reference to data at index
         */
        ProjectionT operator[](Subscript i) const;

        /**
         * Get the subscriptor object
         */
        Subscriptor subscriptor() const;

        /**
         * Get a constant pointer to the data origin
         */
        T* first_datum() const;

        // Conversion operators  ###################################################################

        operator ConcreteArray1dConstRef<Subscriptor, T>() const;

        // Assignment operators  ###################################################################

        ConcreteArray1dRef<Subscriptor, T>& operator=(ConcreteArray1dConstRef<Subscriptor, T> rhs);
        ConcreteArray1dRef<Subscriptor, T>& operator=(const T& rhs);

    protected:

        // Constructor
        // Declare protected so only derived classes can access it
        ConcreteArray1dRef(Subscriptor s, T* p);

        friend ConcreteArray1d<Subscriptor, T>;

    private:

        T* const data_;

};

// Global functions ################################################################################

template <class Shape1, class Shape2, class T>
void concrete_copy(
    const ConcreteArray1dRef<Shape1, T>& lhs,
    const ConcreteArray1dConstRef<Shape2, T>& rhs
);

// Implementation ######################################################################################################

// Member functions ################################################################################

template <class Subscriptor, class T>
inline
T& ConcreteArray1dRef<Subscriptor, T>::operator()(Subscript i) const {
    return first_datum()[offset(i)];
}

template <class Subscriptor, class T>
inline
typename ConcreteArray1dRef<Subscriptor, T>::ProjectionT
ConcreteArray1dRef<Subscriptor, T>::operator[](Subscript i) const {
    return first_datum()[offset(i)];
}

template <class Subscriptor, class T>
inline
Subscriptor ConcreteArray1dRef<Subscriptor, T>::subscriptor() const {
    return *this;
}

template <class Subscriptor, class T>
inline
T* ConcreteArray1dRef<Subscriptor, T>::first_datum() const {
    return data_;
}

// Conversion operators  ###################################################################

template <class Subscriptor, class T>
inline
ConcreteArray1dRef<Subscriptor, T>::operator ConcreteArray1dConstRef<Subscriptor, T>() const {
    return ConcreteArray1dConstRef(subscriptor(), data_);
}

// Assignment operators  ###################################################################

// TODO: I may want to prohibit this to act like a built-in reference
template <class Subscriptor, class T>
inline
ConcreteArray1dRef<Subscriptor, T>&
ConcreteArray1dRef<Subscriptor, T>::operator=(ConcreteArray1dConstRef<Subscriptor, T> rhs) {
    concrete_copy(*this, rhs);
    return *this;
}

template <class Subscriptor, class T>
inline
ConcreteArray1dRef<Subscriptor, T>&
ConcreteArray1dRef<Subscriptor, T>::operator=(const T& rhs) {
    Subscript n = shape(0);
    while (n-- > 0) {
        (*this)(n) = rhs;
    }
    return *this;
}

// Protected methods  ##############################################################################

template <class Subscriptor, class T>
inline
ConcreteArray1dRef<Subscriptor, T>::ConcreteArray1dRef(Subscriptor s, T* p) :
    Subscriptor(s),
    data_(p) {
}

// Global functions ################################################################################

template <class Shape1, class Shape2, class T>
void concrete_copy(
    const ConcreteArray1dRef<Shape1, T>& lhs,
    const ConcreteArray1dConstRef<Shape2, T>& rhs
) {
    Subscript n = lhs.shape(0);
    if (n != rhs.shape(0)) throw std::runtime_error(std::string("Array size mismatch."));
    while (n-- > 0) {
        lhs[n] = rhs[n];
    }
}
