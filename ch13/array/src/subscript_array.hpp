/**
 * @brief Define the SubscriptArray class template
 *
 * SubscriptArray is a simple, low-overhead way to store arrays of subscripts. The subscripts represents subscripts of
 * an actual array implementation. SubscriptArray is parameterized by the subscript dimension.
 *
 * For example, for a one-dimensional array of size 20, SubscriptArray<1> stores 20. Similarly, for a two-dimensional
 * array of size 5 x 4, SubscriptArray<2> stores 5 and 4. In each case, the size of each dimension is accessible using
 * the operator().
 *
 * Note this class is not intended to be used on its own. It does not have the safe-guards necessary for general
 * purpose use. Rather, it should be used as private members of other classes of the template library.
 */

#include "subscript.hpp"

// #####################################################################################################################

template <Dimension N>
class SubscriptArray {
    // Empty template - must supply template specialization for each
};

// SimpleArray<1> ##################################################################################

template <>
class SubscriptArray<1> {

    public:

        SubscriptArray();
        SubscriptArray(Subscript s);

        SubscriptArray<1>& operator=(Subscript rhs);
        Subscript& operator()(Subscript);
        Subscript operator()(Subscript) const;

    private:

        Subscript s_;

};

// SimpleArray<2> ##################################################################################

template <>
class SubscriptArray<2> {

    public:

        SubscriptArray();
        SubscriptArray(Subscript s0, Subscript s1);

        SubscriptArray<2>& operator=(Subscript rhs);
        Subscript& operator()(Subscript i);
        Subscript operator()(Subscript i) const;

    private:

        Subscript s_[2];

};

// Implementation ######################################################################################################

// SimpleArray<1> ##################################################################################

inline
SubscriptArray<1>::SubscriptArray() {}

inline
SubscriptArray<1>::SubscriptArray(Subscript s) :
    s_(s) {}

inline
SubscriptArray<1>& SubscriptArray<1>::operator=(Subscript rhs) {
    s_ = rhs;
    return *this;
}

inline
Subscript& SubscriptArray<1>::operator()(Subscript) {
    return s_;
}

inline
Subscript SubscriptArray<1>::operator()(Subscript) const {
    return s_;
}

// SimpleArray<2> ##################################################################################

inline
SubscriptArray<2>::SubscriptArray() {}

inline
SubscriptArray<2>::SubscriptArray(Subscript s0, Subscript s1) {
    s_[0] = s0;
    s_[1] = s1;
}

inline
SubscriptArray<2>& SubscriptArray<2>::operator=(Subscript rhs) {
    s_[0] = s_[1] = rhs;
    return *this;
}

inline
Subscript& SubscriptArray<2>::operator()(Subscript i) {
    return s_[i];
}

inline
Subscript SubscriptArray<2>::operator()(Subscript i) const {
    return s_[i];
}
