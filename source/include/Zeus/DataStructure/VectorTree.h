/*
 * VectorTree.h
 *
 *  Created on: 21.04.2013
 *      Author: grand
 */

#ifndef VECTORTREE_H_
#define VECTORTREE_H_

#include <vector>
#include <assert.h>

namespace Zeus
{
    namespace DataStructure
    {
        template <class T>
        class VectorTree
        {
            std::vector<T> data;
        public:
            VectorTree(int n=0);
            ~VectorTree();
            T & operator[](int index);
            const T & operator[](int index) const;
            int parent(int index) const;
            int leftChild(int index) const;
            int rightChild(int index) const;
            int size() const;
            void push_back(const T & value);
            void pop_back();
            void resize(int newSize);
            void reserve(int newSize);
        };

        template<class T>
        inline VectorTree<T>::VectorTree(int n)
            : data(n)
        {
        }

        template<class T>
        inline VectorTree<T>::~VectorTree()
        {
        }

        template<class T>
        inline T & VectorTree<T>::operator [](int index)
        {
            assert((index>=0)&&(index<static_cast<int>(data.size())) );
            return data[index];
        }

        template<class T>
        inline const T & VectorTree<T>::operator [](int index) const
        {
            return const_cast<VectorTree<T> * >(this)->operator[](index);
        }

        template<class T>
        inline int VectorTree<T>::parent(int index) const
        {
            return index?(index-1)>>1:-1;
        }

        template<class T>
        inline int VectorTree<T>::leftChild(int index) const
        {
            int child = (index<<1)+1;
            return (child<static_cast<int>(data.size()))?child:-1;
        }

        template<class T>
        inline int VectorTree<T>::rightChild(int index) const
        {
            int child = (index<<1)+2;
            return (child<static_cast<int>(data.size()))?child:-1;
        }

        template<class T>
        inline int VectorTree<T>::size() const
        {
            return data.size();
        }

        template<class T>
        inline void VectorTree<T>::push_back(const T & value)
        {
            data.push_back(value);
        }

        template<class T>
        inline void VectorTree<T>::pop_back()
        {
            data.pop_back();
        }

        template<class T>
        inline void VectorTree<T>::resize(int newSize)
        {
            data.resize(newSize);
        }

        template<class T>
        inline void VectorTree<T>::reserve(int newSize)
        {
            data.reserve(newSize);
        }
    }
}

#endif /* VECTORTREE_H_ */
