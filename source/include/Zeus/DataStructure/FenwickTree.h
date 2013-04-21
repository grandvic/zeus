/*
 * FenwickTree.h
 *
 *  Created on: 23.03.2013
 *      Author: grand
 */

#ifndef FENWICKTREE_H_
#define FENWICKTREE_H_

#include <vector>
#include <assert.h>

namespace Zeus
{
    namespace DataStructure
    {
        /*
         * @brief data structure which allows:
         *      1) increase any element of array by some value in O(logN);
         *      2) calculate sum of elements with indexes 0..index in O(logN).
         */
        template<class T>
        class FenwickTree
        {
        public:
            /*
             * @brief constructor. Creates Fenwick tree for array with n elements initialized by value T().
             * @param n - size of Fenwick tree.
             */
            FenwickTree(int n);
            ~FenwickTree();
            /*
             * @brief increases element data[index] by <value> using T::operator+(const T &).
             * @param index - index of increasing element;
             * @param value - value of increasing the element.
             */
            void increase(int index, const T & value);
            /*
             * @brief calculates sum of the elements data[i]: 0 <= i <= index.
             * @param count - count of elements in the sum.
             */
            const T sum(int index) const;
        private:
            std::vector<T> data;
        };

        template<class T>
        FenwickTree<T>::FenwickTree(int n)
                : data(n, T())
        {
        }

        template<class T>
        FenwickTree<T>::~FenwickTree()
        {
        }

        template<class T>
        void FenwickTree<T>::increase(int index, const T & value)
        {
            assert(index>=0);
            assert(index<static_cast<int>(data.size()));

            for(int i = index; i < static_cast<int>(data.size()); i |= (i + 1))
            {
                data[i] = data[i] + value;
            }
        }

        template<class T>
        const T FenwickTree<T>::sum(int index) const
        {
            assert(index>=0);
            assert(index<static_cast<int>(data.size()));

            T result = T();
            for(int i = index; i >= 0; i = (i & (i + 1)) - 1)
            {
                result = result + data[i];
            }
            return result;
        }
    }
}

#endif /* FENWICKTREE_H_ */
