/*
 * Program: Create a C++ program that asks the user to enter three integer
 * values as input. Store the values into three different variables. For each
 * variable, create an integer pointer to dynamic memory. Display the contents of
 * the variables and pointers. In your program, be sure to use the new operator and
 * delete operators to management memory.
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

void
printError()
{
    std::cerr << "Input only numbers, i.e., '9' and not 'nine'." << std::endl;
}

int
readInt()
{
    /* Checking if input stream is usable. */
    if (std::cin.bad())
    {
        std::cout << "Input stream corrupted." << std::endl;
        return -1;
    }
    else if (std::cin.eof())
    {
        std::cout << "Input stream reached end of file." << std::endl;
        return -1;
    }

    /* Prompt the user and read input. */
    std::cout << "Please enter an integer: ";
    std::string input{};
    std::getline(std::cin, input);

    /* Adjust starting iterator when '-' found in first position. */
    std::string::const_iterator cbegin = input.cbegin();
    if (input.length() > 0 && input[0] == '-')
    {
        cbegin++;
    }

    /* Check input for any non-digit characters. `isdigit` requires unsigned char. */
    if (!std::all_of(cbegin, input.cend(),
                     [](unsigned char c) { return std::isdigit(c); }))
    {
        /* Display an error and reprompt the user. */
        printError();
        return readInt();
    }

    /* Return converted text to an integer. */
    return std::atoi(input.c_str());
}

auto
main(int argc, char *argv[]) -> int
{
    /* Create the three pointers. */
    int *first  = new int;
    int *second = new int;
    int *third  = new int;

    /* Store an int in the pointers. */
    *first  = readInt();
    *second = readInt();
    *third  = readInt();

    /* Display the pointer address and value contained there. */
    std::cout << first  << " contains " << *first  << std::endl
              << second << " contains " << *second << std::endl
              << third  << " contains " << *third  << std::endl;

    /* Free the allocated memory for the pointers. */
    delete first;
    delete second;
    delete third;

    return 0;
}
