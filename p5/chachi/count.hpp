#pragma once

#include <iostream>
#include <limits>

class count {

    private:
        int media_;
        int max_;
        int min_;
        int acc_;
        int n_;

    public:
        count();
        ~count();

        void start(void);
        void stop(void);
        void reset(void);
        int get_acc(void);
        int get_max(void);
        int get_min(void);
        // void set(unsigned ini=0);
        int operator++(int);
        std::ostream& write(std::ostream& os) const;

        friend std::ostream& operator<<(std::ostream& os, const count& c);
};