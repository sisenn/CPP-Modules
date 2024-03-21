#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av){

    std::deque<int> deque;
    std::list<int> list;

    srand(time(NULL));
    for (int i = 1; i < ac; ++i)
    {
        int value = atoi(av[i]);
        if (value <= 0)
        {
            std::cerr << "Invalid input \"" << av[i] << "\". Only positive integers are allowed." << std::endl;
			exit(1);
        }
        deque.push_back(value);
        list.push_back(value);
    }
    std::cout << "Before: ";
    display(deque);

    clock_t start1 = clock();
    mergeInsertSortDeque(deque);
    clock_t end1 = clock();
    double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

    clock_t start2 = clock();
    mergeInsertSortList(list);
    clock_t end2 = clock();
    double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    display(deque);
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << list.size() << " elements with std::list container: " << time2 << " us" << std::endl;
    if (deque == std::deque<int>(list.begin(), list.end()))
        std::cout << "Sorted sequences are equal." << std::endl;
    else
        std::cout << "Sorted equences are not equal." << std::endl;
}

template <typename T>
void PmergeMe::display(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
    std::deque<int>::iterator it1, it2;
    for (it1 = arr.begin() + 1; it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(std::prev(it2)) > temp)
        {
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}

void PmergeMe::mergeInsertSortList(std::list<int>& arr)
{
    std::list<int>::iterator it1, it2;
    for (it1 = ++arr.begin(); it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(std::prev(it2)) > temp)
        {
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}
