/*
 * BloomFilter.h
 *
 *  Created on: 24.03.2013
 *      Author: grand
 */

#ifndef BLOOMFILTER_H_
#define BLOOMFILTER_H_

#include <vector>

namespace Zeus
{
    namespace DataStructure
    {
        /**
         * @brief probabilistic light set data structure.
         *        class HashBank MUST contain static int hash(const T & value, int hashNumber).
         *        probablility of fail positive answer: (1-exp(-kn/m))^k,
         *          where m - size of hash values array;
         *                n - number of stored elements;
         *                k - number of hash functions (recommended k = 0.6931*m/n)
         */
        template<class T, class HashBank>
        class BloomFilter
        {
        public:
            /**
             * @brief constructor.
             * @param table_size - size of hash values table;
             * @param hash_count - count of used hash functions.
             */
            BloomFilter(int table_size, int hash_count);
            /**
             * @brief destructor.
             */
            ~BloomFilter();
            /**
             * @brief inserts new pass-element to the filter.
             * @param value - element to be inserted.
             */
            void insert(const T & value);
            /**
             * @brief try to find element <value>.
             * @param value - element to be found.
             * @return true - if element being found; false - if not.
             */
            bool find(const T & value) const;
        private:
            std::vector<bool> data;
            const int hashCount;
        };

        template<class T, class HashBank>
        BloomFilter<T, HashBank>::BloomFilter(int table_size, int hash_count)
            : data(table_size),
              hashCount(hash_count)
        {
        }

        template<class T, class HashBank>
        BloomFilter<T, HashBank>::~BloomFilter()
        {
        }

        template<class T, class HashBank>
        void BloomFilter<T, HashBank>::insert(const T & value)
        {
            for(int i = 0; i < hashCount; ++i)
            {
                data[HashBank::hash(value, i) % data.size()] = true;
            }
        }

        template<class T, class HashBank>
        bool BloomFilter<T, HashBank>::find(const T & value) const
        {
            for(int i = 0; i < hashCount; ++i)
            {
                if(!data[HashBank::hash(value, i) % data.size()])
                {
                    return false;
                }
            }
            return true;
        }
    }
}

#endif /* BLOOMFILTER_H_ */
