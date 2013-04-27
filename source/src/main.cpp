/*
 * main.cpp
 *
 *  Created on: 23.03.2013
 *      Author: grand
 */

#include <iostream>
#include <Zeus/DataStructure/DSU.h>

using namespace Zeus::DataStructure;
using namespace std;

int main()
{
    DSU<unsigned int> a(5);
    cout<<a.componentsCount()<<endl;

    a.unite(1,2);
    a.unite(0,2);
    a.unite(1,3);
    a.unite(0,3);

    cout<<a.componentsCount()<<endl;

    return 0;
}
