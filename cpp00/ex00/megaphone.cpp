#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

void    print_args(int argc, char **argv)
{
    int i = 1;
    std::string curr_arg;

    while (i < argc)
    {
        curr_arg = argv[i];
        if (curr_arg.find(' ') == 0)
            curr_arg.erase(0, curr_arg.find_first_not_of(' '));
        if (curr_arg.find_last_of(' ') == curr_arg.length() - 1)
            curr_arg.erase(curr_arg.find_last_not_of(' ') + 1, curr_arg.length());
        std::transform(curr_arg.begin(), curr_arg.end(), curr_arg.begin(), ::toupper);
        std::cout << curr_arg << ' ';
        i++;
    }
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
        print_args(argc, argv);
    return 0;
}
