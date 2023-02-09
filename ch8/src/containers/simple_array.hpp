/**
* Template header file for SimpleArray
* Source:
*     Scientific and Engineering C++, 4.3, p. 101
*/
#pragma once

// #################################################################################################

template <class T>
class SimpleArray {

    public:
        SimpleArray();
        SimpleArray(int n);
        SimpleArray(const SimpleArray<T>&);
        ~SimpleArray();

        // Member functions
        int length() const;
        void resize(int);

        // Operator functions
        T& operator[](int i);
        T& operator[](int i) const;
        SimpleArray<T>& operator=(const SimpleArray<T>&);
        SimpleArray<T>& operator=(T);

    private:

        int m_n;
        T* m_data;

        void copy(const SimpleArray<T>&);

};

// Implementation ##################################################################################

// Constructors ################################################################

template <class T>
SimpleArray<T>::SimpleArray() {
    m_n = 0;
    m_data = nullptr;
}

template <class T>
SimpleArray<T>::SimpleArray(int n) {
    m_n = n;
    m_data = new T[n];
}

template <class T>
SimpleArray<T>::SimpleArray(const SimpleArray<T>& other) {
    m_n = other.m_n;
    m_data = new T[m_n];
    copy(other);
}

template <class T>
SimpleArray<T>::~SimpleArray() {
    delete [] m_data;
}

// Member functions ############################################################

template <class T>
int SimpleArray<T>::length() const {
    return m_n;
}

template <class T>
void SimpleArray<T>::resize(int n) {
    if (n != m_n) {
        delete [] m_data;
        m_n = n;
        m_data = new T[n];
    }
}

// Operator functions ##########################################################

template <class T>
T& SimpleArray<T>::operator[](int i) {
    return m_data[i];
}

template <class T>
T& SimpleArray<T>::operator[](int i) const {
    return m_data[i];
}

template <class T>
SimpleArray<T>& SimpleArray<T>::operator=(const SimpleArray<T>& other) {
    if (m_n != other.m_n || m_data == other.m_data) {
        resize(other.m_n);
        copy(other);
    }
    return *this;
}

template <class T>
SimpleArray<T>& SimpleArray<T>::operator=(T value) {
    T* p_data = m_data + m_n;
    while (p_data > m_data) *--p_data = value;
    return *this;
}

// Private functions ###########################################################

template <class T>
void SimpleArray<T>::copy(const SimpleArray<T>& other) {
    T* p_data = m_data + m_n;
    T* p_other = other.m_data + m_n;
    while (p_data > m_data) *--p_data = *--p_other;
}
