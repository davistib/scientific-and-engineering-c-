// Define the ConcreteStrides template class

#pragma once

#include "subscript.hpp"
#include "subscript_array.hpp"

// #####################################################################################################################

template <Dimension N>
class ConcreteStrides {

    public:

        /**
         * Create a new instance.
         *
         * @param s index array
         */
        ConcreteStrides(const SubscriptArray<N>& s);

        /**
         * Get the stride.
         *
         * @param The dimension along to get stride
         * @return The computed stride
         */
        Subscript stride(Dimension d) const;

        /**
         * Get the offset from the first element.
         *
         * @param index array to compute offset to
         * @return The computed offset
         */
        Subscript offset(const SubscriptArray<N>& s) const;


    protected:

        ConcreteStrides();
        SubscriptArray<N> strides_;

};
