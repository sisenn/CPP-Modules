#include  "easyfind.hpp"

int main()
{
    std::vector<int> v;
    std::set<int> s;
    std::list<int> l;
    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
        s.insert(i);
        l.push_back(i);
    }
    
    try
    {
        std::cout << *easyfind(v, 3) << std::endl;
        std::cout << *easyfind(s, 3) << std::endl;
        std::cout << *easyfind(l, 3) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}