#pragma once

#include <string>
#include <iostream>

class Three
{ 
    private:
        size_t size;
        unsigned char *array;
    public:
        Three();
        Three(const size_t & n, unsigned char t = 0);
        Three(const std::initializer_list< unsigned char> &t);
        Three(const std::string &t);
        Three(const Three& other);
        Three(Three&& other) noexcept;      

        Three add(const Three& other);
        Three remove(const Three& other);
        bool equals(const Three& other) const;

        bool operator<(const Three& other) const;
        bool operator>(const Three& other) const;
        std::ostream&   print(std::ostream& os);

        virtual ~Three() noexcept;


};