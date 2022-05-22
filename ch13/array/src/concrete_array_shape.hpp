/**
 * @brief Define the ConcreteArrayShape class template
 *
 * ConcreteArrayShape represents the shape of an array that is fixed at compile time.
 */

#include "subscript.hpp"
#include "subscript_array.hpp"

// #####################################################################################################################

template <Dimension N>
class ConcreteArrayShape {

    public:
        ConcreteArrayShape();
        ConcreteArrayShape(const SubscriptArray<N>&);

        Dimension dim() const;
        Subscript shape(Dimension d) const;
        Subscript length() const;
        void set_shape(const SubscriptArray<N>& shape);

    private:
        SubscriptArray<N> shape_;

};

// Implementation ######################################################################################################

template <Dimension N>
ConcreteArrayShape<N>::ConcreteArrayShape() {}

template <Dimension N>
ConcreteArrayShape<N>::ConcreteArrayShape(const SubscriptArray<N>& shape) :
    shape_(shape) {
}

template <Dimension N>
inline
Dimension ConcreteArrayShape<N>::dim() const {
    return N;
}

template <Dimension N>
inline
Subscript ConcreteArrayShape<N>::shape(Dimension d) const {
    return shape_(d);
}

template <Dimension N>
Subscript ConcreteArrayShape<N>::length() const {
    Dimension d = dim() - 1;
    Subscript length = shape(d);
    while (d > 0) {
        length *= shape(--d);
    }
    return length;
}

template <Dimension N>
inline
void ConcreteArrayShape<N>::set_shape(const SubscriptArray<N>& shape) {
    shape_ = shape;
}
