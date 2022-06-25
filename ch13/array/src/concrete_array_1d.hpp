// Define the ConcreteArray1d class template

#pragma once

#include <stdexcept>
#include <string>

#include "concrete_array_shape.hpp"
#include "concrete_array_1d_const_ref.hpp"
#include "concrete_array_2d_ref.hpp"

// #####################################################################################################################

/**
 * ConcreteArray1d is the base class for 1-dimensional concrete arrays.
 *
 * @tparam Subscriptor
 * @tparam T
 */
template <class Subscriptor, class T>
class ConcreteArray1d :
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
        typedef const T& ConstProjectionT;

        // typedef ConcreteArrayBrowser<ConcreteArray1d<Subscriptor, T>> BrowserType;
        // typedef ConcreteArrayIterator<ConcreteArray1d<Subscriptor, T>> IteratorType;

        // Member functions ########################################################################

        /**
         * Get member element by subscript indices
         *
         * @param i index along the first dimension
         *
         * @return reference to data at index
         */
        T& operator()(Subscript i);

        /**
         * Get member element by subscript indices
         *
         * @param i index along the first dimension
         *
         * @return const reference to data at index
         */
        const T& operator()(Subscript i) const;

        /**
         * Get member element by subscript indices
         *
         * @param i index along the first dimension
         *
         * @return reference to data at index
         */
        ProjectionT operator[](Subscript i);

        /**
         * Get member element by subscript indices
         *
         * @param i index along the first dimension
         *
         * @return const reference to data at index
         */
        ConstProjectionT operator[](Subscript i) const;

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

        // Conversion operators  ###################################################################

        operator ConcreteArray1dRef<Subscriptor, T>();
        operator ConcreteArray1dConstRef<Subscriptor, T>() const;

        // Assignment operators  ###################################################################

        ConcreteArray1d<Subscriptor, T>& operator=(const ConcreteArray1d<Subscriptor, T>& rhs);
        ConcreteArray1d<Subscriptor, T>& operator=(const ConcreteArray1dConstRef<Subscriptor, T>& rhs);
        ConcreteArray1d<Subscriptor, T>& operator=(const T& rhs);

    protected:

        // Constructor
        // Declare protected so only derived classes can access it
        // TODO: source does not have const here...think about why
        ConcreteArray1d(const Subscriptor& s, T* p);

        void reshape_on_heap(const SubscriptArray<1>& s);
        void set_size_on_heap(Subscript n);

    protected:

        T* data_;

    private:

        // Copy Constructor
        // Declare private so compiler does not create one - no definition needed
        // ConcreteArray1d(const ConcreteArray1d<Subscriptor, T>&);
        // TODO: why is this not needed in the 1D version?

};

// Implementation ######################################################################################################

// Member functions ################################################################################

template <class Subscriptor, class T>
inline
T& ConcreteArray1d<Subscriptor, T>::operator()(Subscript i) {
    return first_datum()[offset(i)];
}

template <class Subscriptor, class T>
inline
const T& ConcreteArray1d<Subscriptor, T>::operator()(Subscript i) const {
    return first_datum()[offset(i)];
}

template <class Subscriptor, class T>
inline
Subscriptor ConcreteArray1d<Subscriptor, T>::subscriptor() const {
    return *this;
}

template <class Subscriptor, class T>
inline
T* ConcreteArray1d<Subscriptor, T>::first_datum() {
    return data_;
}

template <class Subscriptor, class T>
inline
T const* ConcreteArray1d<Subscriptor, T>::first_datum() const {
    return data_;
}

template <class Subscriptor, class T>
inline
typename ConcreteArray1d<Subscriptor, T>::ProjectionT
ConcreteArray1d<Subscriptor, T>::operator[](Subscript i) {
    return first_datum()[offset(i)];
}

template <class Subscriptor, class T>
inline
typename ConcreteArray1d<Subscriptor, T>::ConstProjectionT
ConcreteArray1d<Subscriptor, T>::operator[](Subscript i) const {
    return first_datum()[offset(i)];
}

// Conversion operators  ###########################################################################

template <class Subscriptor, class T>
inline
ConcreteArray1d<Subscriptor, T>::operator ConcreteArray1dRef<Subscriptor, T>() {
    return ConcreteArray1dRef(subscriptor(), data_);
}

template <class Subscriptor, class T>
inline
ConcreteArray1d<Subscriptor, T>::operator ConcreteArray1dConstRef<Subscriptor, T>() const {
    return ConcreteArray1dConstRef(subscriptor(), data_);
}

// Assignment operators  ###########################################################################

template <class Subscriptor, class T>
inline
ConcreteArray1d<Subscriptor, T>& ConcreteArray1d<Subscriptor, T>::operator=(
    const ConcreteArray1d<Subscriptor, T>& rhs
) {
    // create a reference object and use it's assignment operator
    ConcreteArray1dRef<Subscriptor, T>(*this) = rhs;
    return *this;
}

template <class Subscriptor, class T>
inline
ConcreteArray1d<Subscriptor, T>& ConcreteArray1d<Subscriptor, T>::operator=(
    const ConcreteArray1dConstRef<Subscriptor, T>& rhs
) {
    // create a reference object and use it's assignment operator
    ConcreteArray1dRef<Subscriptor, T>(*this) = rhs;
    return *this;
}

template <class Subscriptor, class T>
inline
ConcreteArray1d<Subscriptor, T>& ConcreteArray1d<Subscriptor, T>::operator=(const T& rhs) {
    // create a reference object and use it's assignment operator
    ConcreteArray1dRef<Subscriptor, T>(*this) = rhs;
    return *this;
}

// NOTE: can implement operators directly if performance hit from making temporary reference

// Protected methods  ##############################################################################

template <class Subscriptor, class T>
inline
ConcreteArray1d<Subscriptor, T>::ConcreteArray1d(const Subscriptor& s, T* p) :
    Subscriptor(s),
    data_(p) {
}
// TODO: source does not have const here...think about why

template <class Subscriptor, class T>
void ConcreteArray1d<Subscriptor, T>::reshape_on_heap(const SubscriptArray<1>& s) {
    this->set_shape(s);
    this->set_size_on_heap(this->length());
}

template <class Subscriptor, class T>
void ConcreteArray1d<Subscriptor, T>::set_size_on_heap(Subscript n) {
    // if (n < 0) throw std::exception(std::string("Negative size."));
    if (n < 0) {
        throw std::runtime_error(std::string("Negative size."));
    }
    delete[] data_;
    data_ = new T[n];
}
