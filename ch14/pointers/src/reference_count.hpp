// Define the ReferenceCount class

#ifndef REFERENCE_COUNT_HPP
#define REFERENCE_COUNT_HPP

// #####################################################################################################################

/**
 * ReferenceCount holds the number of references to a referenced object.
 *
 * This class is meant to be used with CountedBuiltInPtr, a shared or referenced smart
 * pointer class.
 */
class ReferenceCount {

public:

    // Constructors ################################################################################

    /**
     * Default constructor.
     *
     * Create object with initial count of 1.
     */
    ReferenceCount();

    /**
     * Copy constructor.
     *
     * Copy other count and increment count.
     *
     * @param other
     */
    ReferenceCount(const ReferenceCount& other);

    /**
     * Copy assignment.
     *
     * Assign `this` to `other` by decrementing `this` count, and incrementing `other` count and assign
     * `this` pointer to `other`'s pointer.
     *
     * @param rhs another `ReferenceCount` object to assign to `this`
     * @return `this`
     */
    ReferenceCount& operator=(const ReferenceCount& rhs);

    ~ReferenceCount();

    // Member functions ############################################################################

    /// Get whether or not `this` has a count of 1
    bool unique() const;

    /// Get the count of `this`, or number of pointers referenced
    unsigned int count() const;

private:

    /// Decrease count of reference count, of delete
    void decrement_();

    /// pointer to actual reference count
    unsigned int* p_cnt_;

};

// Implementation ######################################################################################################

// NOTE: Most of these methods are inline, so just defining everything here becuase the inline methods
// NOTE: need to be in the header anyways.

// Constructors ####################################################################################

inline
ReferenceCount::ReferenceCount() :
    p_cnt_(new unsigned int(1)) {}

inline
ReferenceCount::ReferenceCount(const ReferenceCount& other) :
    p_cnt_(other.p_cnt_) {
    ++(*p_cnt_);
}

inline
ReferenceCount&
ReferenceCount::operator=(const ReferenceCount& rhs) {
    ++(*rhs.p_cnt_);
    decrement_();
    p_cnt_ = rhs.p_cnt_;
    return *this;
}

inline
ReferenceCount::~ReferenceCount() {
    decrement_();
}

// Member functions ################################################################################

bool
ReferenceCount::unique() const {
    if (*p_cnt_ > 1) {
        return false;
    } else {
        return true;
    }
}

unsigned int
ReferenceCount::count() const {
    return *p_cnt_;
}

// Private functions ###############################################################################

void
ReferenceCount::decrement_() {
    if (unique()) {
        delete p_cnt_;
    } else {
        --(*p_cnt_);
    }
}

#endif // REFERENCE_COUNT_HPP
