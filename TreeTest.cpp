/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main()
{
    ariel::Tree emptytree;
    ariel::Tree threetree;
    ariel::Tree tree;
    ariel::Tree tree2;
    tree2.insert(100);
    tree2.insert(89);
    tree2.insert(23);
    tree2.insert(102);
    tree2.insert(66);
    tree2.insert(16);
    tree2.insert(18);

    threetree.insert(5);
    threetree.insert(7);
    threetree.insert(3);

    for (int i = -1; i < 1000; i++)
    {
        tree.insert(i);
    }

    ariel::Tree mytree;

    badkan::TestCase tc("Binary tree");
    tc
        .CHECK_EQUAL(emptytree.size(), 0)
        .CHECK_OK(emptytree.insert(5))
        .CHECK_EQUAL(emptytree.size(), 1)
        .CHECK_EQUAL(emptytree.contains(5), true)
        .CHECK_OK(emptytree.remove(5))
        .CHECK_EQUAL(emptytree.contains(5), false)
        .CHECK_THROWS(emptytree.remove(5))
        .CHECK_EQUAL(emptytree.size(), 0)

        .CHECK_EQUAL(threetree.size(), 3)
        .CHECK_EQUAL(threetree.root(), 5)
        .CHECK_EQUAL(threetree.parent(3), 5)
        .CHECK_EQUAL(threetree.parent(7), 5)
        .CHECK_EQUAL(threetree.left(5), 3)
        .CHECK_EQUAL(threetree.right(5), 7)
        .CHECK_THROWS(threetree.insert(3))
        .CHECK_THROWS(threetree.left(6))
        .CHECK_OK(threetree.print())

        .CHECK_EQUAL(tree.size(), 1001)
        .CHECK_OK(tree.insert(1001))
        .CHECK_EQUAL(tree.size(), 1002)
        .CHECK_EQUAL(tree.contains(5), true)
        .CHECK_OK(tree.remove(5))
        .CHECK_EQUAL(tree.contains(5), false)
        .CHECK_THROWS(tree.remove(5))
        .CHECK_EQUAL(tree.size(), 1001)
        .CHECK_OK(tree.insert(-2))
        .CHECK_EQUAL(tree.contains(-2), true)
        .CHECK_OK(tree.remove(-2))
        .CHECK_EQUAL(tree.contains(-2), false)
        .CHECK_THROWS(tree.remove(-2))
        .CHECK_EQUAL(tree.contains(1008), false)
        .CHECK_EQUAL(tree.root(), -1)
        .CHECK_THROWS(tree.parent(-1))
        .CHECK_EQUAL(tree.contains(1008), false)
        .CHECK_THROWS(tree.parent(10008))
        .CHECK_THROWS(tree.left(10008))
        .CHECK_THROWS(tree.right(10008))
        .CHECK_THROWS(tree.left(1002))
        .CHECK_EQUAL(tree2.root(), 100)
        .CHECK_EQUAL(tree2.left(100), 89)
        .CHECK_EQUAL(tree2.right(100), 102)
        .CHECK_THROWS(tree2.right(89))
        .CHECK_THROWS(tree2.right(18))
        .CHECK_THROWS(tree2.left(18))
        .CHECK_EQUAL(tree2.size(), 7)
        .CHECK_THROWS(tree2.remove(17))
        .CHECK_OK(tree2.remove(18))
        .CHECK_EQUAL(tree2.size(), 6)
        .CHECK_THROWS(tree2.remove(18))
        .CHECK_EQUAL(tree2.size(), 6)
        .CHECK_THROWS(tree2.insert(23))
        .CHECK_EQUAL(tree2.contains(23), true)
        .CHECK_EQUAL(tree2.size(), 6)
        .CHECK_EQUAL(tree2.contains(18), false)
        .CHECK_OK(tree2.insert(18))
        .CHECK_EQUAL(tree2.size(), 7)
        .CHECK_EQUAL(tree2.contains(18), true)
        .CHECK_EQUAL(tree2.contains(205), false)
        .CHECK_EQUAL(tree2.contains(16), true)
        .CHECK_OK(tree2.insert(33))
        .CHECK_EQUAL(tree2.contains(33), true)
        .CHECK_EQUAL(tree2.size(), 8)
        .CHECK_THROWS(tree2.right(66))
        .CHECK_THROWS(tree2.left(33))
        .CHECK_EQUAL(tree2.left(23),16)
        .CHECK_EQUAL(tree2.right(16),18)
        .CHECK_EQUAL(tree2.parent(33), 66)
        .CHECK_EQUAL(tree2.parent(18), 16)
        .CHECK_OK(tree2.remove(33))
        
        .CHECK_EQUAL(tree2.contains(33), false)
        .CHECK_THROWS(tree2.right(66))

        .print();

    cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}