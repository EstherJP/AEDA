#include "count.hpp"

count::count() { 
    reset();
}

count::~count() {}

void count::reset(void) {
    max_=0;
    count_=0;
    min_=std::numeric_limits<int>::max();
    n_=0;
}

void count::start(void) {
    // reset();
    acc_=0;
}

int count::stop(void) {

    if(min_ > acc_)
        min_=acc_;

    if(max_ < acc_)
        max_=acc_;
    
    count_+=acc_;
    n_++;

    return count_;

}

int count::operator++(int) {
    //acc_++;
    return acc_++;
} 

int count::get_acc(void) {
    return count_/n_;
}
int count::get_max(void) {
    return max_;
}

int count::get_min(void) {
    return min_;
}

std::ostream& count::write(std::ostream& os) const {

    os << acc_ << std::endl;
    return os;

}

std::ostream& operator<<( std::ostream& os, const count& c) {

    return c.write(std::cout);

}