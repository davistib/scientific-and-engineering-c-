/**
 * @brief Define the SubscriptArray class template
 *
 * SubscriptArray is a simple, low-overhead way to store arrays of subscripts. The subscripts represents subscripts of
 * an actual array implementation. SubscriptArray is parameterized by the subscript dimension. This class may be used
 * to store the size/shape of an array (though it is generally a private data member in that case), or used to store
 * the subscripts for an element on a larger array.
 *
 * Note, this class is missing potentially useful safe-guards againts sampling outside of the array class. However, it
 * is not always attached to a physical array, and as such, those safe-guards are not general purpose. The user must be
 * careful, or those safe-guards have to implemented downstream of this class.
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
