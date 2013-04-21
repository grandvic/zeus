/*
 * main.cpp
 *
 *  Created on: 23.03.2013
 *      Author: grand
 */

#include <stdio.h>
#include <Zeus/DataStructure/BinaryHeap.h>

using namespace Zeus::DataStructure;

int main()
{
    BinaryHeap<int> a;
    a.push(6);
    a.push(6);
    a.push(9);
    a.push(5);
    a.push(10);
    a.push(3);
    a.push(8);
    a.push(4);
    a.push(1);
    a.push(7);
    a.push(2);
    a.push(9);
    a.push(5);
    a.push(10);
    a.push(6);
    a.push(9);
    a.push(5);
    a.push(10);
    a.push(3);
    a.push(8);
    a.push(4);
    a.push(1);
    a.push(7);
    a.push(2);
    a.push(3);
    a.push(8);
    a.push(6);
    a.push(9);
    a.push(5);
    a.push(10);
    a.push(3);
    a.push(8);
    a.push(4);
    a.push(1);
    a.push(7);
    a.push(2);
    a.push(4);
    a.push(1);
    a.push(7);
    a.push(2);

    for(int i = 0; i < 4; ++i)
    {
        printf("top = %d\n", a.top());
        a.pop();
        printf("top = %d\n", a.top());
        a.pop();
        printf("top = %d\n", a.top());
        a.pop();
        printf("top = %d\n", a.top());
        a.pop();
        printf("top = %d\n", a.top());
        a.pop();
        printf("top = %d\n", a.top());
        a.pop();
        printf("top = %d\n", a.top());
        a.pop();
        printf("top = %d\n", a.top());
        a.pop();
        printf("top = %d\n", a.top());
        a.pop();
        printf("top = %d\n", a.top());
        a.pop();
    }

    return 0;
}
