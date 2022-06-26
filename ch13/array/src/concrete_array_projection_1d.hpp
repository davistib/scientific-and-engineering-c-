// Define the ConcreteArrayProjection1d template class

#pragma once

#include "concrete_array_1d_ref.hpp"
#include "const_concrete_array_projection_1d.hpp"

// #####################################################################################################################

template <class Subscriptor, class T>
class ConcreteArrayProjection1d :
    public ConcreteArray1dRef<typename Subscriptor::ProjectionT, T> {

    public:

        // Typdefs #################################################################################

        typedef typename Subscriptor::ProjectionT ProjectionSubscriptor;

        // Constructors ############################################################################

        ConcreteArrayProjection1d(const ProjectionSubscriptor& s, T* t);

        // Conversion operators ####################################################################

        operator ConstConcreteArrayProjection1d<Subscriptor, T>() const;

        // Assignment operators ####################################################################

        ConcreteArrayProjection1d<Subscriptor, T>& operator=(ConcreteArray1dConstRef<ProjectionSubscriptor, T> rhs);

        ConcreteArrayProjection1d<Subscriptor, T>& operator=(const T& rhs);

    protected:

        // Copying a projection only copies the reference
        // Make copy constructor protected to avoid client from using it
        ConcreteArrayProjection1d(const ConcreteArrayProjection1d<Subscriptor, T>& projection);

};

// Implementation ######################################################################################################

template <class Subscriptor, class T>
ConcreteArrayProjection1d<Subscriptor, T>::ConcreteArrayProjection1d(
    const ProjectionSubscriptor& s, T* t
) :
    ConcreteArray1dRef<typename Subscriptor::ProjectionT, T>(s, t) {

}

template <class Subscriptor, class T>
ConcreteArrayProjection1d<Subscriptor, T>::operator ConstConcreteArrayProjection1d<Subscriptor, T>() const {
    return ConstConcreteArrayProjection1d<Subscriptor, T>(this->subscriptor(), this->first_datum());
}

template <class Subscriptor, class T>
ConcreteArrayProjection1d<Subscriptor, T>&
ConcreteArrayProjection1d<Subscriptor, T>::operator=(ConcreteArray1dConstRef<ProjectionSubscriptor, T> rhs) {
    ConcreteArray1dRef<ProjectionSubscriptor, T>::operator=(rhs);
    return *this;
}

template <class Subscriptor, class T>
ConcreteArrayProjection1d<Subscriptor, T>&
ConcreteArrayProjection1d<Subscriptor, T>::operator=(const T& rhs) {
    ConcreteArray1dRef<ProjectionSubscriptor, T>::operator=(rhs);
    return *this;
}

template <class Subscriptor, class T>
ConcreteArrayProjection1d<Subscriptor, T>::ConcreteArrayProjection1d(
    const ConcreteArrayProjection1d<Subscriptor, T>& projection
) :
    ConcreteArray1dRef<ProjectionSubscriptor, T>(projection.subscriptor(), projection.first_datum()) {

}
