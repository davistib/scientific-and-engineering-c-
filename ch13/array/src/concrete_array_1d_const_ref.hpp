// Define the ConcreteArray1dConstRef class template

#pragma once

#include <stdexcept>
#include <string>

#include "concrete_array_shape.hpp"

// #####################################################################################################################

// forward declarations
template <class Subscriptor, class T> class ConcreteArray1d;
template <class Subscriptor, class T> class ConcreteArray1dRef;

/**
 * ConcreteArray1dConstRef is the base class for 1-dimensional concrete arrays.
 *
 * @tparam Subscriptor
 * @tparam T
 */
template <class Subscriptor, class T>
class ConcreteArray1dConstRef :
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

        typedef const T& ConstProjectionT;

        // typedef ArrayBrowser1d<ConcreteArray1dConstRef<Subscriptor, T>> BrowserType;

        // Member functions ########################################################################

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
         * @return const reference to data at index
         */
        ConstProjectionT operator[](Subscript i) const;

        /**
         * Get the subscriptor object
         */
        Subscriptor subscriptor() const;

        /**
         * Get a constant pointer to the data origin
         */
        T const* first_datum() const;

    protected:

        // Constructor
        // Declare protected so only derived classes can access it
        ConcreteArray1dConstRef(Subscriptor s, const T* p);

        friend ConcreteArray1dRef<Subscriptor, T>;
        friend ConcreteArray1d<Subscriptor, T>;

    private:

        // Copy Constructor
        // Declare private so compiler does not create one - no definition needed
        // ConcreteArray1d(const ConcreteArray1d<Subscriptor, T>&);
        // TODO: why is this not needed in the 1D version?
        void operator=(const ConcreteArray1dConstRef<Subscriptor, T>& rhs);

        const T* const data_;

};

// Implementation ######################################################################################################

// Member functions ################################################################################

template <class Subscriptor, class T>
inline
const T& ConcreteArray1dConstRef<Subscriptor, T>::operator()(Subscript i) const {
    return first_datum()[offset(i)];
}

template <class Subscriptor, class T>
inline
typename ConcreteArray1dConstRef<Subscriptor, T>::ConstProjectionT
ConcreteArray1dConstRef<Subscriptor, T>::operator[](Subscript i) const {
    return first_datum()[offset(i)];
}

template <class Subscriptor, class T>
inline
Subscriptor ConcreteArray1dConstRef<Subscriptor, T>::subscriptor() const {
    return *this;
}

template <class Subscriptor, class T>
inline
const T* ConcreteArray1dConstRef<Subscriptor, T>::first_datum() const {
    return data_;
}

// Protected methods  ##############################################################################

template <class Subscriptor, class T>
inline
ConcreteArray1dConstRef<Subscriptor, T>::ConcreteArray1dConstRef(Subscriptor s, const T* p) :
    Subscriptor(s),
    data_(p) {
}
