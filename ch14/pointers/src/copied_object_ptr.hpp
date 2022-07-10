// Define the CopiedObjectPtr class
#ifndef COPIED_OBJECT_PTR_HPP
#define COPIED_OBJECT_PTR_HPP

#include "copied_built_in_ptr.hpp"

/**
 *  CopiedObjectPtr is a smart pointer that can point to objects.
 *
 *  This is like the CopiedBuiltInPtr, but has the member selection operator. It should be used to point
 *  to objects that themselves are either pointers or objects, not built-in types.
 */
template <class T>
class CopiedObjectPtr :
    public CopiedBuiltInPtr<T> {

public:

    // Constructors ################################################################################

    /**
     * Default constructor, intializes to nullptr
     */
    CopiedObjectPtr();

    /**
     * Construct from a new pointer
     *
     * This constructor should only be called with a new-ed pointer. The pointer itself should be passed
     * to the argument list. An example usage would be `CopiedObjectPtr(new T())`.
     *
     * @param new_ptr pointer to a new-ed object
     */
    CopiedObjectPtr(T* new_ptr);

    /**
     * Copy constructor from other.
     *
     * This performs an actual copy of the object, which may be expensive.
     *
     * @param other another `CopiedObjectPtr` object to copy
     */
    CopiedObjectPtr(const CopiedObjectPtr<T>& other);

    // TODO: what about constructing/assigning from a CopiedBuiltInPtr?
    // That is not inherited and will not work.

    /**
     * Copy assignment operator from raw pointer.
     *
     * This deletes `this` and assigns to new pointer. This should only be called with a new-ed pointer.
     *
     * @param new_ptr a raw pointer to something
     * @return reference to `this`
     */
    CopiedObjectPtr<T>& operator=(T* new_ptr);

    /**
     * Copy assignment operator from other object.
     *
     * This performs an actual copy of the object, which may be expensive.
     *
     * @param other object to copy and assign to `this`
     * @return reference to `this`
     */
    CopiedObjectPtr<T>& operator=(const CopiedObjectPtr<T>& rhs);

    // Member functions ############################################################################

    /**
     * Member selection operator.
     *
     * @return pointer to object
     */
    T* operator->() const;

};

// Implementation ######################################################################################################

// Constructors ####################################################################################

template <class T>
CopiedObjectPtr<T>::CopiedObjectPtr() :
    CopiedBuiltInPtr<T>() {}

template <class T>
CopiedObjectPtr<T>::CopiedObjectPtr(T* new_ptr) :
    CopiedBuiltInPtr<T>(new_ptr) {}

template <class T>
CopiedObjectPtr<T>::CopiedObjectPtr(const CopiedObjectPtr<T>& other) :
    CopiedBuiltInPtr<T>(other) {}

template <class T>
CopiedObjectPtr<T>&
CopiedObjectPtr<T>::operator=(T* new_ptr) {
    CopiedBuiltInPtr<T>::operator=(new_ptr);
    return *this;
}

template <class T>
CopiedObjectPtr<T>&
CopiedObjectPtr<T>::operator=(const CopiedObjectPtr<T>& rhs) {
    CopiedBuiltInPtr<T>::operator=(rhs);
    return *this;
}

template <class T>
T*
CopiedObjectPtr<T>::operator->() const {
    return this->ptr_;
}

#endif // COPIED_OBJECT_PTR_HPP
