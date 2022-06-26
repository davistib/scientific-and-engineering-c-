// Define the ConcreteColumnMajorArray2d class template

#pragma once

#include "concrete_column_major_subscriptor.hpp"
#include "concrete_array_2d.hpp"

// #####################################################################################################################

/**
 * ConcreteColumMajorArray2d is the final class for concrete, 2d, column major arrays.
 *
 * This template class array is actually meant to be used, and is equivalent to a Fortran array
 * but with zero-based indexing.
 *
 * @tparam T
 */
template <class T>
class ConcreteColumnMajorArray2d :
    public ConcreteArray2d<ConcreteColumnMajorSubscriptor<2>, T> {

    public:

        // Constructors ############################################################################

        /**
         * Create a new 2d array from specified rows and columns
         *
         * @param s0 number of rows
         * @param s1 number of columns
         */
        ConcreteColumnMajorArray2d(Subscript s0, Subscript s1);

        /**
         * Create a new 2d array from another array
         *
         * @param array array to copy
         */
        ConcreteColumnMajorArray2d(
            const ConcreteColumnMajorArray2d<T>& array
        );

        /**
         * Create a new 2d array from another array, that is a constant reference
         *
         * @param array array to copy
         */
        ConcreteColumnMajorArray2d(
            const ConcreteArray2dConstRef<ConcreteColumnMajorSubscriptor<2>, T>& array
        );

        /**
         * Create a new 2d array from another array, that is a constant reference
         *
         * @param array array to copy
         */
        ConcreteColumnMajorArray2d(
            const ConcreteArray2dConstRef<ConcreteColumnMajorSubscriptor<3>::ProjectionT, T>& array
        );

        /**
         * Create a new 2d array from another array, that is any constant array
         *
         * @param array array to copy
         */
        // ConcreteColumnMajorArray2d(const ConstArray2d<T>&);

        // ~ConcreteColumnMajorArray2d();

        // Assignment operators ####################################################################

        ConcreteColumnMajorArray2d<T>& operator=(const ConcreteColumnMajorArray2d<T>& rhs);

        // ConcreteColumnMajorArray2d<T>& operator=(const ConcreteArray2dConstRef<SubscriptorT, T>& rhs);

        ConcreteColumnMajorArray2d<T>& operator=(const T& rhs);

        // Member functions ########################################################################

        /**
         * Reshape array
         *
         * @param shape new shape
         */
        void reshape(const SubscriptArray<2>& shape);

};

// Implementation ######################################################################################################

// Constructors ####################################################################################

template <class T>
ConcreteColumnMajorArray2d<T>::ConcreteColumnMajorArray2d(Subscript s0, Subscript s1) :
    // ConcreteArray2d<SubscriptorT, T>(SubscriptArray<2>(s0, s1), 0) {
    ConcreteArray2d<ConcreteColumnMajorSubscriptor<2>, T>(SubscriptArray<2>(s0, s1), 0) {
        this->set_size_on_heap(s0 * s1);
}

// template <class T>
// ConcreteColumnMajorArray2d<T>::ConcreteColumnMajorArray2d(const ConcreteColumnMajorArray2d<T>& a) :
//     ConcreteArray2d<SubscriptorT, T>(SubscriptArray<2>(a.shape(0), a.shape(1)), 0) {
//         set_size_on_heap(a.length());
//         concrete_copy(*this, a);
// }

// Assignment operators ############################################################################

template <class T>
ConcreteColumnMajorArray2d<T>&
ConcreteColumnMajorArray2d<T>::operator=(const T& rhs) {
    ConcreteArray2d<ConcreteColumnMajorSubscriptor<2>, T>::operator=(rhs);
    return *this;
}
