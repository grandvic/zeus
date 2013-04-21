/*
 * BinaryHeap.h
 *
 *  Created on: 21.04.2013
 *      Author: grand
 */

#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include <Zeus/DataStructure/VectorTree.h>

namespace Zeus
{
    namespace DataStructure
    {
        template<class T>
        class BinaryHeap
        {
            VectorTree<T> data;
        public:
            BinaryHeap();
            ~BinaryHeap();
            bool empty() const;
            const T & top() const;
            void push(const T & value);
            void pop();
        private:
            void thieveUp(int index);
            void thieveDown(int index);
        };

        template<class T>
        BinaryHeap<T>::BinaryHeap()
                : data(0)
        {
        }

        template<class T>
        BinaryHeap<T>::~BinaryHeap()
        {
        }

        template<class T>
        bool BinaryHeap<T>::empty() const
        {
            return data.size() == 0;
        }

        template<class T>
        const T & BinaryHeap<T>::top() const
        {
            assert(data.size());
            return data[0];
        }

        template<class T>
        void BinaryHeap<T>::thieveUp(int index)
        {
            for(int i = index, iParent = data.parent(index); iParent != -1; i = iParent, iParent = data.parent(i))
            {
                if(data[iParent] > data[i]) std::swap(data[iParent], data[i]);
            }
        }

        template<class T>
        void BinaryHeap<T>::thieveDown(int index)
        {
            int i = index;
            while(true)
            {
                int iLeft = data.leftChild(i);
                int iRight = data.rightChild(i);
                if((iLeft == -1) && (iRight == -1)) break;

                if((iRight != -1) && (data[iLeft] > data[iRight])) std::swap(iLeft, iRight);

                if(data[i] > data[iLeft])
                {
                    std::swap(data[i], data[iLeft]);
                    i = iLeft;
                }
                else break;
            }
        }

        template<class T>
        void BinaryHeap<T>::push(const T & value)
        {
            data.push_back(value);
            thieveUp(data.size() - 1);
        }

        template<class T>
        void BinaryHeap<T>::pop()
        {
            assert(!empty());

            std::swap(data[0], data[data.size() - 1]);
            data.pop_back();
            if(!empty()) thieveDown(0);
        }
    }
}

#endif /* BINARYHEAP_H_ */
