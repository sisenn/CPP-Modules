#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    else
    {
        for (int i=1; i < argc; i++)
        {
            int j = 0;
            while(argv[i][j])
            {
                if (argv[i][j] >= 97 && argv[i][j] <= 122)
                {
                    argv[i][j] -= 32;
                    std:: cout << argv[i][j];
                }
                else
                    std::cout << argv[i][j];
                j++;
            }
        }
        std::cout << std::endl;
        return 0;
    }
}