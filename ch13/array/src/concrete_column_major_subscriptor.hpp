/**
 * @brief Define the ConcreteColumnMajorSubscriptor class template
 *
 * ConcreteColumnMajorSubscriptor computes the offset for an element based on column major ordering.
 */

#include "concrete_array_shape.hpp"

// #####################################################################################################################

template <Dimension N>
class ConcreteColumnMajorSubscriptor :
    public ConcreteArrayShape<N> {

    public:
        ConcreteColumnMajorSubscriptor();
        ConcreteColumnMajorSubscriptor(const SubscriptArray<N>&);

        // TODO: define projection operators
        typedef ConcreteColumnMajorProjectionSubscriptor<N-1> ProjectionT;
        ProjectionT projection_subscriptor(Dimension d, Subscript s) const;

        Subscript offset(const SubscriptArray<N>& s) const;
};

// ConcreteColumnMajorSubscriptor<1> ###############################################################

// ConcreteColumnMajorSubscriptor<2> ###############################################################
