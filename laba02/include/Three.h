#pragma once

#include <string>
#include <iostream>

class Three
{ 
    private:
        size_t size;
        unsigned char *array;
        void resize(size_t new_size);
        void remove_firsts_zeros();
    public:
        Three();
        Three(const size_t & n, unsigned char t = 0);
        Three(const std::initializer_list< unsigned char> &t);
        Three(const std::string &t);

        Three(const Three& other);
        Three(Three&& other) noexcept;      

        friend std::ostream& operator <<(std::ostream& out, Three const &t);

        Three& operator = (Three const & other);
        Three& operator = (Three && other);

        Three operator + (Three & other);
        Three operator - (Three & other);

        bool operator == (Three & other);
        bool operator<(Three& other);
        bool operator>(Three& other);


        Three add(Three& other);
        Three remove(Three& other);

        virtual ~Three() noexcept;


};
