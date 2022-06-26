// Define the ConstConcreteArrayProjection1d template class

#pragma once

#include "concrete_array_1d_const_ref.hpp"

// #####################################################################################################################

template <class Subscriptor, class T>
class ConstConcreteArrayProjection1d :
    public ConcreteArray1dConstRef<typename Subscriptor::ProjectionT, T> {

    public:

        // Typdefs #################################################################################

        typedef typename Subscriptor::ProjectionT ProjectionSubscriptor;

        // Constructors ############################################################################

        ConstConcreteArrayProjection1d(const ProjectionSubscriptor& s, const T* t);

    protected:

        // Copying a projection only copies the reference
        // Make copy constructor protected to avoid client from using it
        ConstConcreteArrayProjection1d(const ConstConcreteArrayProjection1d<Subscriptor, T>& projection);

};

// Implementation ######################################################################################################

template <class Subscriptor, class T>
ConstConcreteArrayProjection1d<Subscriptor, T>::ConstConcreteArrayProjection1d(
    const ProjectionSubscriptor& s, const T* t
) :
    ConcreteArray1dConstRef<ProjectionSubscriptor, T>(s, t) {
}


template <class Subscriptor, class T>
ConstConcreteArrayProjection1d<Subscriptor, T>::ConstConcreteArrayProjection1d(
    const ConstConcreteArrayProjection1d<Subscriptor, T>& projection
) :
    ConcreteArray1dConstRef<typename Subscriptor::ProjectionT, T>(
        projection.subscriptor(), projection.first_datum()
    ) {
}
