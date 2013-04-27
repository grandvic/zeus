/*
 * DSU.h
 *
 *  Created on: 27.04.2013
 *      Author: grand
 */

#ifndef DSU_H_
#define DSU_H_

#include <vector>

namespace Zeus
{
    namespace DataStructure
    {
        template<class T>
        class DSU
        {
            std::vector<T> data;
            std::vector<T> rank;
            int components;
        public:
            DSU(T N = 0);
            ~DSU();
            T size() const;
            T componentsCount()const;
            T addSet();
            T find(T index);
            void unite(T a, T b);
        };

        template<class T>
        DSU<T>::DSU(T N)
                : rank(N, 1), components(N)
        {
            data.reserve(N);
            for(T i = 0; i < N; ++i)
                data.push_back(i);
        }

        template<class T>
        DSU<T>::~DSU()
        {
        }

        template<class T>
        T DSU<T>::size() const
        {
            return data.size();
        }

        template<class T>
        T DSU<T>::componentsCount()const
        {
            return components;
        }

        template<class T>
        T DSU<T>::addSet()
        {
            const T N = size();
            data.push_back(N);
            rank.push_back(1);
            return N;
        }

        template<class T>
        T DSU<T>::find(T index)
        {
            std::vector<T> found;
            T i=index;
            for(; data[i]!=i; i=data[i]) found.push_back(i);
            for(T j=0; j<found.size(); ++j) data[found[j]]=i;
            return i;
        }

        template<class T>
        void DSU<T>::unite(T a, T b)
        {
            T first = find(a);
            T second = find(b);
            if(first!=second)
            {
                --components;
                if(rank[first]<rank[second])
                {
                    data[second] = first;
                    rank[first] += rank[second];
                }
                else
                {
                    data[first] = second;
                    rank[second] += rank[first];
                }
            }
        }
    }
}

#endif /* DSU_H_ */
