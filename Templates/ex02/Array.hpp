#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T               *_array;
        unsigned int    _size; 

    public:
        Array()
        {
            this->_array = new T[0];
            this->_size = 0;
        }

        Array(unsigned int n)
        {
            this->_array = new T[n];
            this->_size = n;
        }

        Array(Array const &src)
        {
            this->_array = new T[src._size];
            this->_size = src._size;
            for (unsigned int i = 0; i < src._size; i++)
                this->_array[i] = src._array[i];
        }

        Array& operator=(Array const &src)
        {
            if (this != &src)
            {
                delete[] this->_array;
                this->_array = new T[src._size];
                this->_size = src._size;
                for (unsigned int i = 0; i < src._size; i++)
                    this->_array[i] = src._array[i];
            }
            return *this;
        }

        ~Array()
        {
            delete[] this->_array;
        }

        unsigned int getSize()
        {
            return _size;
        }

        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("Error : Index out of bounds");
            return (_array[index]);
        }
        
};

#endif