#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
//test
void    print_args(int argc, char **argv)
{
    int i = 1;
    std::string curr_arg;

    while (i < argc)
    {
        curr_arg = argv[i];
        std::transform(curr_arg.begin(), curr_arg.end(), curr_arg.begin(), ::toupper);
        std::cout << curr_arg;
        i++;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
        print_args(argc, argv);
    return 0;
}