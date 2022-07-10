// Define the CopiedBuiltInPtr class
#ifndef COPIED_BUILT_IN_PTR_HPP
#define COPIED_BUILT_IN_PTR_HPP

/**
 * CopiedBuiltInPtr is a smart pointer that manages a raw pointer resource.
 *
 * This version acts like a built-in pointer, but provides methods to copy resources and maintains
 * a 1:1 relationship between pointer and object in memery. The 1:1 relationshp is maintained by
 * a deep copy of resources, not by move semantics. As such, this should be used with care and, in
 * general, avoided for resources that expensive. See also `UniqueBuiltInPtr`.
 *
 * This class contains no member selection
 * operator ->, as that operator must return a built-in pointer to another class and cannot return a
 * built-in pointer to a built-in type. This class, thus, can be used with both built-in types and
 * classes. However, the derived `CopiedObjectPtr` is likely a better choice for classes.
 */
template <class T>
class CopiedBuiltInPtr {

public:

    // Constructors ################################################################################

    /**
     * Default constructor, intializes to nullptr
     */
    CopiedBuiltInPtr();

    /**
     * Construct from a new pointer
     *
     * This constructor should only be called with a new-ed pointer. The pointer itself should be passed
     * to the argument list. An example usage would be `CopiedBuiltInPtr(new T())`.
     *
     * @param new_ptr pointer to a new-ed object
     */
    CopiedBuiltInPtr(T* new_ptr);

    /**
     * Copy constructor from other.
     *
     * This performs an actual copy of the object, which may be expensive.
     *
     * @param other another `CopiedBuiltInPtr` object to copy
     */
    CopiedBuiltInPtr(const CopiedBuiltInPtr<T>& other);

    /**
     * Copy assignment operator from raw pointer.
     *
     * This deletes `this` and assigns to new pointer. This should only be called with a new-ed pointer.
     *
     * @param new_ptr a raw pointer to something
     * @return reference to `this`
     */
    CopiedBuiltInPtr<T>& operator=(T* new_ptr);

    /**
     * Copy assignment operator from other object.
     *
     * This performs an actual copy of the object, which may be expensive.
     *
     * @param other object to copy and assign to `this`
     * @return reference to `this`
     */
    CopiedBuiltInPtr<T>& operator=(const CopiedBuiltInPtr<T>& other);

    /**
     * Destructor to delete the object on heap.
     */
    ~CopiedBuiltInPtr();

    // Member functions ############################################################################

    /**
     * Overload of dereference operator `*` to access object.
     *
     * @return object pointed to by `this`
     */
    T& operator*() const;

    /**
     * Get whether or not `this` is a null pointer.
     */
    bool is_null() const;

    /**
     * Give up control of raw pointer.
     *
     * @return raw pointer `this` controlled
     */
    T* release_control();

    // Friend functions ############################################################################

    /**
     * Determine if pointers are equal.
     *
     * @param lhs `this` object
     * @param rhs other object
     */
    template <class S>
    friend bool operator==(const CopiedBuiltInPtr<S>& lhs, const CopiedBuiltInPtr<S>& rhs);
    // NOTE: this must be defined as a template function to avoid overload resolution

    /**
     * Determine if pointers are not equal.
     *
     * @param lhs `this` object
     * @param rhs other object
     */
    template <class S>
    friend bool operator!=(const CopiedBuiltInPtr<S>& lhs, const CopiedBuiltInPtr<S>& rhs);
    // NOTE: this must be defined as a template function to avoid overload resolution

protected:

    /// Declare protected so derived classes can access
    T* ptr_;

};

// Implementation ######################################################################################################

// Constructors ####################################################################################

template <class T>
inline
CopiedBuiltInPtr<T>::CopiedBuiltInPtr() :
    ptr_(nullptr) {}

template <class T>
inline
CopiedBuiltInPtr<T>::CopiedBuiltInPtr(T* new_ptr) :
    ptr_(new_ptr) {}

template <class T>
CopiedBuiltInPtr<T>::CopiedBuiltInPtr(const CopiedBuiltInPtr<T>& other) :
    ptr_(other.is_null() ? nullptr : new T(*other.ptr_)) {}
// Note: this effectively calls the copy constructor from the underlying object with `this` object

template <class T>
CopiedBuiltInPtr<T>&
CopiedBuiltInPtr<T>::operator=(T* new_ptr) {
    delete ptr_;
    ptr_ = new_ptr;
    return *this;
}
// TODO: what _if_ you assign to the same pointer as `this` already contains, by accident?
// This should be avoided because `this` should only be constructed from `new` itself

template <class T>
CopiedBuiltInPtr<T>&
CopiedBuiltInPtr<T>::operator=(const CopiedBuiltInPtr<T>& other) {
    if (ptr_ != other.ptr_) {
        delete ptr_;
        ptr_ = other.is_null() ? nullptr : new T(*other.ptr_);
    }
    return *this;
}

template <class T>
inline
CopiedBuiltInPtr<T>::~CopiedBuiltInPtr() {
    delete ptr_;
}

// Member functions ################################################################################

template <class T>
inline
T&
CopiedBuiltInPtr<T>::operator*() const {
    return *ptr_;
}

template <class T>
inline
bool
CopiedBuiltInPtr<T>::is_null() const {
    return ptr_ == nullptr;
}

template <class T>
T*
CopiedBuiltInPtr<T>::release_control() {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
}

// Friend functions ################################################################################

template <class T>
inline
bool operator==(const CopiedBuiltInPtr<T>& lhs, const CopiedBuiltInPtr<T>& rhs) {
    return lhs.ptr_ == rhs.ptr_;
}

template <class T>
inline
bool operator!=(const CopiedBuiltInPtr<T>& lhs, const CopiedBuiltInPtr<T>& rhs) {
    return lhs.ptr_ != rhs.ptr_;
}

#endif // COPIED_BUILT_IN_PTR_HPP
