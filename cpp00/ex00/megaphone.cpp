#include <iostream>
#include <string>
#include <cctype>

void    print_args(int argc, char **argv)
{
    std::string curr_arg;

    for (int i = 1; i < argc; i++)
    {
        curr_arg = argv[i];
        for (size_t j = 0; j < curr_arg.length(); j++) 
		{
        	if (islower(curr_arg[j]))
        	    curr_arg[j] = toupper(curr_arg[j]);
    	}
        std::cout << curr_arg;
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