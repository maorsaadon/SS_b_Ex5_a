#ifndef MAGICL_CONTAINER_HPP
#define MAGICL_CONTAINER_HPP
#include <map>
#include <cstdlib>
#include <iostream>
#include <type_traits>
#include <set>
#include <vector>
#include <list>

using namespace std;

namespace ariel
{
    struct PointerComparator
    {
        bool operator()(const int *left, const int *right) const
        {
            return *left < *right;
        }
    };

    class MagicalContainer
    {
    public:
        vector<int> element_;
        int index_ = 0;

        void addElement(int);
        int size();
        void removeElement(int);

        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t index_;
        public:
            AscendingIterator(MagicalContainer &);
            AscendingIterator(const AscendingIterator &);
            ~AscendingIterator() = default;
            AscendingIterator &operator=(const AscendingIterator &other);                     
            AscendingIterator(AscendingIterator &&other) noexcept = default;                 
            AscendingIterator &operator=(AscendingIterator &&other) noexcept { return *this; } 

            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other);
            bool operator<(const AscendingIterator &other);
            int operator*();
            AscendingIterator& operator++();
            AscendingIterator begin();
            AscendingIterator end();
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &container_;
            size_t start_;
            size_t end_;
            size_t counter_;

        public:
            SideCrossIterator(MagicalContainer &);
            SideCrossIterator(const SideCrossIterator &);
            ~SideCrossIterator() = default;
            SideCrossIterator &operator=(const SideCrossIterator &other);                     
            SideCrossIterator(SideCrossIterator &&other) noexcept = default;                 
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept { return *this; } 
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other);
            bool operator<(const SideCrossIterator &other);
            int operator*();
            SideCrossIterator &operator++();
            SideCrossIterator begin();
            SideCrossIterator end();
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t index_;

        public:
            PrimeIterator(MagicalContainer &);
            PrimeIterator(const PrimeIterator &);
            ~PrimeIterator() = default;
            PrimeIterator &operator=(const PrimeIterator &other);                      
            PrimeIterator(PrimeIterator &&other) noexcept = default;                   
            PrimeIterator &operator=(PrimeIterator &&other) noexcept { return *this; }

            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other);
            bool operator<(const PrimeIterator &other);
            int operator*();
            PrimeIterator &operator++();
            PrimeIterator begin();
            PrimeIterator end();
        };
    };
};
#endif