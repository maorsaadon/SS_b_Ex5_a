#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("addElement")
{
    MagicalContainer container;

    SUBCASE("single element")
    {
        container.addElement(2);
        CHECK(container.size() == 1);
    }

    SUBCASE("multiple elements")
    {
        container.addElement(2);
        container.addElement(4);
        container.addElement(6);
        container.addElement(8);
        container.addElement(10);
        CHECK(container.size() == 5);
    }
}

TEST_CASE("removeElement")
{
    MagicalContainer container;

    SUBCASE("existing element")
    {
        container.addElement(2);
        container.addElement(4);
        CHECK_NOTHROW(container.removeElement(2));
        CHECK(container.size() == 1);
    }

    SUBCASE("non-existing element")
    {
        container.addElement(2);
        container.addElement(4);
        container.addElement(6);
        CHECK_THROWS_AS(container.removeElement(8), runtime_error);
        CHECK(container.size() == 3);
    }
}

TEST_CASE("Comparing iterators from the same container")
{
    MagicalContainer container;
    for (int i = 1; i <= 10; ++i)
    {
        container.addElement(i * 10);
    }

    SUBCASE("Comparing AscendingIterator with itself")
    {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }

    SUBCASE("Comparing SideCrossIterator with itself")
    {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }

    SUBCASE("Comparing PrimeIterator with itself")
    {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }
}

TEST_SUITE("Class AscendingIterator")
{
    TEST_CASE("AscendingIterator")
    {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(4);
        container.addElement(6);
        container.addElement(8);
        container.addElement(10);

        SUBCASE("Iterating over elements")
        {
            MagicalContainer::AscendingIterator it(container);
            CHECK(*it == 2);
            ++it;
            CHECK(*it == 4);
            ++it;
            CHECK(*it == 6);
            ++it;
            CHECK(*it == 8);
            ++it;
            CHECK(*it == 10);
            ++it;
            CHECK(it == it.end());
        }

    }

    TEST_CASE("Method: operator*")
    {
        MagicalContainer container;
        container.addElement(12);
        container.addElement(1);
        container.addElement(18);
        container.addElement(29);

        MagicalContainer::AscendingIterator ascIter(container);

        CHECK(*ascIter == 1);
        ++ascIter;
        CHECK(*ascIter == 12);
        ++ascIter;
        CHECK(*ascIter == 18);
        ++ascIter;
        CHECK(*ascIter == 29);

        ++ascIter;
        CHECK_THROWS(*ascIter);
    }
}

TEST_SUITE("Class SideCrossIterator")
{
    TEST_CASE("SideCrossIterator")
    {
        MagicalContainer container;
        container.addElement(2);
        container.addElement(4);
        container.addElement(6);
        container.addElement(8);

        SUBCASE("Iterating over elements")
        {
            MagicalContainer::SideCrossIterator it(container);
            CHECK(*it == 2);
            ++it;
            CHECK(*it == 8);
            ++it;
            CHECK(*it == 4);
            ++it;
            CHECK(*it == 6);
            ++it;
            CHECK(it == it.end());
        }

    }

    TEST_CASE("Method: operator*")
    {
        MagicalContainer container;
        container.addElement(30);
        container.addElement(5);
        container.addElement(2);
        container.addElement(80);
        container.addElement(17);

        MagicalContainer::SideCrossIterator crossIter(container);
        
        CHECK(*crossIter == 2);
        ++crossIter;
        CHECK(*crossIter == 80);
        ++crossIter;
        CHECK(*crossIter == 5);
        ++crossIter;
        CHECK(*crossIter == 30);
        ++crossIter;
        CHECK(*crossIter == 17);

        
        ++crossIter;
        CHECK_THROWS(*crossIter);
       
        CHECK_THROWS(++crossIter);
    }

}

TEST_SUITE("Class PrimeIterator")
{
    TEST_CASE("PrimeIterator")
    {
        MagicalContainer container;
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);
        container.addElement(6);

        SUBCASE("Iterating over elements")
        {
            MagicalContainer::PrimeIterator it(container);
            CHECK(*it == 2);
            ++it;
            CHECK(*it == 3);
            ++it;
            CHECK(*it == 5);
            ++it;
            CHECK(it == it.end());
        }
    }

    TEST_CASE("Method: operator*")
    {
        MagicalContainer container;
        container.addElement(103);
        container.addElement(18);
        container.addElement(3);
        container.addElement(7);
        container.addElement(28);

        MagicalContainer::PrimeIterator primeIter(container);

        CHECK(*primeIter == 3);
        ++primeIter;
        CHECK(*primeIter == 7);
        ++primeIter;
        CHECK(*primeIter == 103);

        ++primeIter;
        CHECK_THROWS(*primeIter);

        CHECK_THROWS(++primeIter);
    }

}

TEST_CASE("operator= throws when iterators are pointing at different containers") {
    MagicalContainer container1;
    MagicalContainer container2;

    container1.addElement(1);
    container1.addElement(2);
    container1.addElement(3);

    container2.addElement(4);
    container2.addElement(5);
    container2.addElement(6);    

   SUBCASE("AscendingIterator")
   {
        MagicalContainer::AscendingIterator it1(container1);
        MagicalContainer::AscendingIterator it2(container2);

        CHECK_THROWS_AS(it1 = it2, std::runtime_error);
   }
   SUBCASE("SideCrossIterator")
   {
        MagicalContainer::SideCrossIterator it1(container1);
        MagicalContainer::SideCrossIterator it2(container2);

        CHECK_THROWS_AS(it1 = it2, std::runtime_error);
   }
   SUBCASE("AscendingIterator")
   {
        MagicalContainer::PrimeIterator it1(container1);
        MagicalContainer::PrimeIterator it2(container2);

        CHECK_THROWS_AS(it1 = it2, std::runtime_error);
   }
}