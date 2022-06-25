/**
 * @brief Define the ConcreteColumnMajorSubscriptor class template
 *
 * ConcreteColumnMajorSubscriptor computes the offset for an element based on column major ordering.
 */

#pragma once

#include "concrete_array_shape.hpp"

// #####################################################################################################################

// FIXME: have to use unnamed namespace to make this compile across multiple units
// FIXME: figure out the best way to avoid
namespace {

template <Dimension N>
class ConcreteColumnMajorSubscriptor :
    public ConcreteArrayShape<N> {

    public:
        ConcreteColumnMajorSubscriptor() {};
        ConcreteColumnMajorSubscriptor(const SubscriptArray<N>& s);

        // TODO: define projection operators
        // typedef ConcreteColumnMajorProjectionSubscriptor<N-1> ProjectionT;
        // ProjectionT projection_subscriptor(Dimension d, Subscript s) const;

        /**
         * @brief Compute the integral offset from the beginning of the underlying element storage
         *        to the element given by the subscripts passed as arguments.
         *
         * @param s subscripts array to compute offset to
         *
         * @return integer offset from beginning of array to subscripts
         */
        Subscript offset(const SubscriptArray<N>& s) const;
};

}

// ConcreteColumnMajorSubscriptor<1> ###############################################################

// Template speciliazation for 1D subscriptors

template <>
class ConcreteColumnMajorSubscriptor<1> :
    public ConcreteArrayShape<1> {

    public:
        ConcreteColumnMajorSubscriptor<1>(const SubscriptArray<1>& s);
        ConcreteColumnMajorSubscriptor() {};

        Subscript offset(const SubscriptArray<1>& s) const;
};

// Implementation ######################################################################################################

template <Dimension N>
ConcreteColumnMajorSubscriptor<N>::ConcreteColumnMajorSubscriptor(const SubscriptArray<N>& s) :
    ConcreteArrayShape<N>(s) {}

template <Dimension N>
inline
Subscript ConcreteColumnMajorSubscriptor<N>::offset(const SubscriptArray<N>& s) const {
    Dimension n = N;
    Subscript offset_ = 0;
    while (n-- > 0) {
        offset_ = offset_ * this->shape(n) + s(n);
    }
    return offset_;
}

ConcreteColumnMajorSubscriptor<1>::ConcreteColumnMajorSubscriptor(const SubscriptArray<1> & s) :
    ConcreteArrayShape<1>(s) {}

Subscript ConcreteColumnMajorSubscriptor<1>::offset(const SubscriptArray<1>& s) const {
    Subscript offset_ = s(0);
    return offset_;
}
