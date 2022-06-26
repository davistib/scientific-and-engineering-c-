// Define the ConcreteColumnMajorProjectionSubscriptor template class

#pragma once

#include "concrete_array_shape.hpp"
#include "concrete_strides.hpp"

// #####################################################################################################################

// FIXME: have to use unnamed namespace to make this compile across multiple units
// FIXME: figure out the best way to avoid?
namespace {

template <Dimension N>
class ConcreteColumnMajorProjectionSubscriptor :
    private ConcreteArrayShape<N>,
    private ConcreteStrides<N> {

    public:

        // Constructors ############################################################################

        ConcreteColumnMajorProjectionSubscriptor(
            const ConcreteArrayShape<N> shape,
            const SubscriptArray<N>& strides
        );

        ConcreteColumnMajorProjectionSubscriptor();

        // Typdefs #################################################################################

        typedef ConcreteColumnMajorProjectionSubscriptor<N-1> ProjectionT;

        // elevate desired private member functions
        using ConcreteArrayShape<N>::dim;
        using ConcreteArrayShape<N>::shape;
        using ConcreteArrayShape<N>::length;
        using ConcreteArrayShape<N>::set_shape;
        using ConcreteStrides<N>::offset;

        // Member functions ########################################################################

        // Create a new projection subscriptor from this one
        ProjectionT projection_subscriptor(Dimension d, Subscript) const;

};

}

// Define template specialization to end recursion on ProjectionT
template <>
class ConcreteColumnMajorProjectionSubscriptor<1> :
    private ConcreteArrayShape<1>,
    private ConcreteStrides<1> {

    public:

        // Constructors ############################################################################

        ConcreteColumnMajorProjectionSubscriptor(
            const ConcreteArrayShape<1> shape,
            const SubscriptArray<1>& strides
        );

        ConcreteColumnMajorProjectionSubscriptor();

        // elevate desired private member functions
        using ConcreteArrayShape<1>::dim;
        using ConcreteArrayShape<1>::shape;
        using ConcreteArrayShape<1>::length;
        using ConcreteArrayShape<1>::set_shape;
        using ConcreteStrides<1>::offset;

};

// Implementation ######################################################################################################

template <Dimension N>
ConcreteColumnMajorProjectionSubscriptor<N>::ConcreteColumnMajorProjectionSubscriptor() {}

template <Dimension N>
ConcreteColumnMajorProjectionSubscriptor<N>::ConcreteColumnMajorProjectionSubscriptor(
    const ConcreteArrayShape<N> shape,
    const SubscriptArray<N>& strides
) :
    ConcreteArrayShape<N>(shape),
    ConcreteStrides<N>(strides) {
}

template <Dimension N>
typename ConcreteColumnMajorProjectionSubscriptor<N>::ProjectionT
ConcreteColumnMajorProjectionSubscriptor<N>::projection_subscriptor(Dimension d, Subscript) const {
    SubscriptArray<N-1> projection_shape;
    SubscriptArray<N-1> projection_strides;
    SubscriptArray<N> first;
    SubscriptArray<N> second;

    first = 0;
    second = 0;

    for (Dimension j = 0; j < N - 1; j++) {
        Dimension j_old = j + (j >= d);
        projection_shape(j) = shape(j_old);
        second(j_old) = 1;
        projection_strides(j) = offset(second) - offset(first);
        second(j_old) = 0;
    }

    return ConcreteColumnMajorProjectionSubscriptor<N-1>(projection_shape, projection_strides);
}

ConcreteColumnMajorProjectionSubscriptor<1>::ConcreteColumnMajorProjectionSubscriptor() {}

ConcreteColumnMajorProjectionSubscriptor<1>::ConcreteColumnMajorProjectionSubscriptor(
    const ConcreteArrayShape<1> shape,
    const SubscriptArray<1>& strides
) :
    ConcreteArrayShape<1>(shape),
    ConcreteStrides<1>(strides) {
}
