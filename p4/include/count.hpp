#include <iostream>
#include <limits>

class count {

    private:
        int count_;
        int max_;
        int min_;
        int acc_;
        int n_;

    public:
        count();
        ~count();

        void start(void);
        int stop(void);
        void reset(void);
        int get_acc(void);
        int get_max(void);
        int get_min(void);
        // void set(unsigned ini=0);
        int operator++(int);
        std::ostream& write(std::ostream& os) const;

        friend std::ostream& operator<<(std::ostream& os, const count& c);
};