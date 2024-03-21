#include "Span.hpp"

Span::Span() : _numbers(0), _maxSize(MAX) {}

Span::Span(unsigned int n){
    _maxSize = n;
    _numbers.reserve(n);
}

Span::Span(Span const &other)
{
    this->_numbers = other._numbers;
    this->_maxSize = other._maxSize;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    try
    {
        if (_numbers.size() >= _maxSize)
            throw SpanFull();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return ;
    }
    _numbers.push_back(number);
}

std::vector<int> Span::getNumbers() const
{
    return _numbers;
}


int randomNumber()
{
    return (rand() % 1000000);
}

void Span::randomAdd()
{
    try
    {
        if (_numbers.size() > _maxSize)
            throw SpanFull();
        for (unsigned int i = 0; i < this->_maxSize; i++)
        {
            _numbers.push_back(randomNumber());
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

long long Span::shortestSpan()
{
    try
    {
        if (_numbers.size() <= 1)
            throw SpanEmpty();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (0);
    }
    std::sort(_numbers.begin(), _numbers.end());
    long long min = 99999999999999;
    for (int i = 1; i < (int)_numbers.size(); i++)
    {
        long long x = static_cast<long long>(_numbers[i]);
        long long y = static_cast<long long>(_numbers[i - 1]);
        if ((x - y) < min)
            min = (x - y);
    }
    return (min);
}

int Span::numberSign(long min, long max)
{
    if (min < 0 && max < 0)
        return 2;
    else if (min < 0 || max < 0)
        return 1;
    return 0;
}

long long Span::longestSpan()
{
    try
    {
        if (_numbers.size() <= 1)
            throw SpanEmpty();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (0);
    }
    long long max = static_cast<long long>(_numbers[_maxSize - 1]);
    long long min = static_cast<long long>(_numbers[0]);
    return (max - min);
}


const char *Span::SpanFull::what() const throw()
{
    return "Span is full!";
}
const char *Span::SpanEmpty::what() const throw()
{
    return "Not enough elements to calculate span!";
}