#include "Three.h"

Three::Three() : size(0), array{nullptr}
{

}

Three::Three(const size_t &n, unsigned char t)
{
    array = new unsigned char[n];
    for (size_t i = 0; i < n; ++i)
        array[i] = t;
    size = n;
}

Three::Three(const std::initializer_list<unsigned char> &t)
{
    array = new unsigned char[t.size()];
    size_t i{0};
    for (auto &c : t)
        array[i++] = c;
    size = t.size();
}

Three::Three(const std::string &t)
{
    array = new unsigned char[t.size()];
    size  = t.size();

    for(size_t i{0};i<size;++i) array[i] = t[i];
}

Three::Three(const Three &other)
{
    size  = other.size;
    array = new unsigned char[size];

    for(size_t i{0};i<size;++i) array[i] = other.array[i];
}

Three::Three(Three &&other) noexcept
{
    size = other.size;
    array = other.array;

    other.size = 0;
    other.array = nullptr;
}

Three Three::add(const Three &other)
{
    return Three(this->size+other.size,'1');
}
Three Three::remove(const Three &other)
{

    if(size<other.size) throw std::logic_error("dash array can't be negative");

    size -= other.size;

    return *this;
}

bool Three::equals(const Three &other) const
{
    return size==other.size;
}

bool Three::operator<(const Three &other) const
{
    return size < other.size;
}

bool Three::operator>(const Three & other) const 
{
    return size > other.size;
}

std::ostream &Three::print(std::ostream &ostream)
{
    for (size_t i = 0; i < size; ++i)
        ostream << array[i];
    return ostream;
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