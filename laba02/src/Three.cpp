#include "Three.h"

Three::Three() : size(0), array{nullptr} {}

//default
Three::Three(const size_t &n, unsigned char t)
{
    size = n;
    array = new unsigned char[size];
    for (size_t i = 0; i < size; ++i)
        array[size-i-1] = t;
}

//initializer
Three::Three(const std::initializer_list<unsigned char> &t) {
    size = t.size();
    array = new unsigned char[t.size()];
    size_t i = size - 1;
    for (auto &c : t)
        array[i--] = c;

}

//copy string
Three::Three(const std::string &t) {
    size  = t.size();
    array = new unsigned char[t.size()];
    for(size_t i = 0;i<size;++i) {
        array[size-i-1] = t[i];
    }
}

//copy constructor
Three::Three(const Three &other) {
    size  = other.size;
    array = new unsigned char[size];

    for(size_t i{0};i<size;++i) {
        array[i] = other.array[i];
    }
}
//move constructor
Three::Three(Three &&other) noexcept {
    size = other.size;
    array = other.array;

    other.size = 0;
    other.array = nullptr;
}


Three& Three::operator = (Three const &other) {
    if (this == &other) {
        return *this;
    }

    if (this->size != other.size) {
        unsigned char *temp = new unsigned char[other.size];
        if (this->array != nullptr) {
            delete[] this->array;
        }
        this->array = temp;
        this->size = other.size;
    }
    std::copy(other.array, other.array + other.size, this->array);

    return *this;
}

Three& Three::operator = (Three &&other) {
    if (this == &other) {
        return *this;
    }

    this->size = other.size;
    other.size = 0;

    if (this->array != nullptr)  {
        delete[] this->array;
    }
    this->array = other.array;
    other.array = nullptr;

    return *this;
}

std::ostream& operator <<(std::ostream &out, Three const &t) {
    for (size_t i = t.size; i > 0; i--) {
        out << t.array[i - 1];
    }
    return out;
}

bool Three::operator ==(Three& other) {
    if (this->size != other.size) {
        return false;
    }

    for (size_t i = this->size; i > 0; --i) {
        if (this->array[i - 1] == other.array[i - 1]) {
            continue;
        }
        return false;
    }

    return true;
}

bool Three::operator>(Three & other)
{
    if (this->size < other.size) {
        return false;
    } 

    if (this->size > other.size) {
        return true;
    } 

    for (size_t i = this->size; i > 0; --i) {
        if (this->array[i - 1] == other.array[i - 1]) {
            continue;
        }
        if (this->array[i - 1] > other.array[i - 1]) {
            return true;
        }
        if (this->array[i - 1] < other.array[i - 1]) {
            return false;
        }
    }

    return false;
}

bool Three::operator <(Three &other)
{
    if (*this > other || *this == other) {
        return false;
    }

    return true;
}

void Three::resize(size_t new_size) {
    if (this->size > new_size) {
        throw std::logic_error("New size have to be bigger that current");
    } 

    if (this->size == new_size) {
        return;
    }

    unsigned char *new_array = new unsigned char[new_size];
    for (size_t i = 0; i < this->size; ++i) {
        new_array[i] = this->array[i];
    }
    delete[] this->array;
    this->size = new_size;
    this->array = new_array;
}

Three Three::operator +(Three &other) {
    size_t max_size = this->size > other.size ? this->size : other.size;
    Three tmp(max_size, '0');
    unsigned int rem = 0, digit_of_this = 0, digit_of_other = 0;

    for (size_t i = 0; i < max_size; ++i) {
        digit_of_this = i < this->size ? int(this->array[i]) - 48 : 0;
        digit_of_other = i < other.size ? int(other.array[i]) - 48 : 0;

        int sum = digit_of_this + digit_of_other + rem;
        tmp.array[i] = static_cast<char>(int(tmp.array[i]) + sum % 3);
        rem = sum / 3;
    }

    if (rem != 0) {
        tmp.resize(max_size + 1);
        tmp.array[tmp.size - 1] = static_cast<char>(rem + 48);
    }

    return tmp;
}

void Three::remove_firsts_zeros() {
    int cnt_of_zeros = 0;
    for (size_t i = this->size; i > 0; i--) {
        if (this->array[i - 1] == '0') {
            cnt_of_zeros += 1;
        } 
        else {
            break;
        }
    }
    if (cnt_of_zeros == this->size) {
        --cnt_of_zeros;
    }
    size_t new_size = this->size - cnt_of_zeros;
    unsigned char *new_array = new unsigned char[new_size];
    for (size_t i = 0; i < new_size; ++i) {
        new_array[i] = this->array[i];
    }
    delete[] this->array;
    this->size = new_size;
    this->array = new_array;
}

Three Three::operator -(Three &other) {
    if (other > *this) {
        throw std::logic_error("Second number is smaller than first");
    }

    size_t max_size = this->size > other.size ? this->size : other.size;
    Three tmp(max_size, '0');
    int rem = 0, digit_of_this = 0, digit_of_other = 0;

    for (size_t i = 0; i < max_size; ++i) {
        digit_of_this = i < this->size ? int(this->array[i]) - 48 : 0;
        digit_of_other = i < other.size ? int(other.array[i]) - 48 : 0;

        if (rem > 0) {
            digit_of_this -= rem;
        }

        int diff = digit_of_this - digit_of_other;

        if (diff < 0) {
            rem = 1;
            diff += 3;
        } 
        else {
            rem = 0;
        }
        tmp.array[i] = static_cast<char>(int(tmp.array[i]) + diff);
    }

    tmp.remove_firsts_zeros();
    
    return tmp;
}

Three Three::add(Three &other)
{
    *this = *this + other;
    return *this;
}

Three Three::remove(Three &other)
{
    *this = *this - other;

    return *this;
}



Three::~Three() noexcept
{
    if (size > 0)
    {
        size = 0;
        delete[] array;
        array = nullptr;
    }
}
