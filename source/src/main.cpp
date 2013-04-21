/*
 * main.cpp
 *
 *  Created on: 23.03.2013
 *      Author: grand
 */

#include <stdio.h>
#include <string>
#include <Zeus/DataStructure/FenwickTree.h>
#include <Zeus/DataStructure/BloomFilter.h>

using namespace Zeus::DataStructure;

struct HashBank
{
    static const int hash_param[5];
    static int hash(const std::string & s, int hashNumber)
    {
        int result = 376211;
        for(int i=0; i<(int)s.length(); ++i)
            result = result * hash_param[hashNumber] ^ s[i];
        return result;
    }
};

const int HashBank::hash_param[5] = {13215763, 1231717, 2341713, 56123781, 12398919};

int main()
{
    FenwickTree<float> a(10);

    a.increase(3, 5);
    a.increase(1, 2);
    a.increase(4, 3);

    printf("sum[0..4] = %f\n", a.sum(4));

    BloomFilter<std::string, HashBank> bloomFilter(800, 5);

//    bloomFilter.insert("mother");
    bloomFilter.insert("queen");
//    bloomFilter.insert("wilcox");
    bloomFilter.insert("mewerick");

    printf("mother: %s\n", bloomFilter.find("mother")?"yes":"no");
    printf("queen: %s\n", bloomFilter.find("queen")?"yes":"no");
    printf("wilcox: %s\n", bloomFilter.find("wilcox")?"yes":"no");
    printf("mewerick: %s\n", bloomFilter.find("mewerick")?"yes":"no");

	return 0;
}
