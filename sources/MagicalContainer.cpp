#include "MagicalContainer.hpp"

using namespace std;
namespace ariel
{

    // helper function
    bool checkIsPrime(int data_)
    {
        for (int i = 2; i * i <= data_; i++)
        {
            if (data_ % i == 0)
                return false;
        }
        return true;
    }

    void MagicalContainer::addElement(int val){};

    void MagicalContainer::removeElement(int val){};

    int MagicalContainer::size()
    {
        return element_.size();
    };

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &magicalContainer) : container(magicalContainer), index_(0){};
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), index_(other.index_){};

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return other.index_ == index_;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {

        return !(other.index_ == index_);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other)
    {
        return true;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other)
    {
        return true;
    }
    
    int MagicalContainer::AscendingIterator::operator*()
    {
        return true;
    }
    
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        return *this;
    }

    
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return *this;
    }
    
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        return *this;
    }

    
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &other) : container_(other), start_(0), end_(0){}; 
    
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container_(other.container_), start_(other.start_), end_(other.end_){}; 
   
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return true;
    }
  
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other)
    {
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other)
    {
        return true;
    }

    int MagicalContainer::SideCrossIterator::operator*()
    {
        return 1;
    }
 

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return *this;
    }
   
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        return *this;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &other) : container(other), index_(0){}; 

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), index_(other.index_){};

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !operator==(other); 
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other)
    {
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other)
    {
        return true;
    }

    int MagicalContainer::PrimeIterator::operator*()
    {
        return 1;
    }
 
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        return *this;
    }
 
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        return *this;
    }
 
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return *this;
    }

}