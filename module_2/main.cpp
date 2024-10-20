#include <iostream>
#include <string>

void
concatUserStrings()
{
    std::string strOne{};
    std::string strTwo{};

    std::cout << "String one: ";
    std::getline(std::cin, strOne);
    std::cout << "String two: ";
    std::getline(std::cin, strTwo);

    std::cout << "Concatenated strings: '" << strOne << strTwo << "'" << std::endl;
}

auto
main(int argc, char *argv[]) -> int
{
    int TIMES_TO_LOOP = 3;

    for (int i = 0; i < TIMES_TO_LOOP; i++)
    {
        concatUserStrings();
    }

    return 0;
}
