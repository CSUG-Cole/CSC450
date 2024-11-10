#include <algorithm>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <system_error>

bool
appendToFile(const std::string path, const std::string data, std::error_code& ec)
{
    /* Open file in append mode */
    std::ofstream file{};

    file.open(path, std::ios::app);

    /* Check if open succeeded thirg */
    if (!file.is_open())
    {
        ec = std::make_error_code(std::errc::no_such_file_or_directory);
        return false;
    }

    /* Append data to file */
    file << data;

    /* Check if write was successful */
    if (file.fail())
    {
        ec = std::make_error_code(std::errc::io_error);
        file.close();
        return false;
    }

    file.close();
    return true;
}

void
handleIOError(std::ofstream& out, std::ifstream& in, std::error_code& ec, std::errc code)
{
    ec = std::make_error_code(code);
    if (out.is_open()) out.close();
    if (in.is_open()) in.close();
}

bool
reverseFile(const std::string dest, const std::string src, std::error_code& ec)
{
    std::ofstream out{};
    std::ifstream in{};
    out.open(dest, std::ios::out);
    in.open(src, std::ios::in);

    /* Check for errors opening either file */
    if (!out.is_open() || !in.is_open())
    {
        handleIOError(out, in, ec, std::errc::no_such_file_or_directory);
        return false;
    }

    std::string data{std::istreambuf_iterator<char>(in),
                     std::istreambuf_iterator<char>()};

    if (in.fail() && !in.eof())
    {
        handleIOError(out, in, ec, std::errc::io_error);
        return false;
    }

    std::reverse(data.begin(), data.end());
    out << data;

    if (out.fail())
    {
        handleIOError(out, in, ec, std::errc::io_error);
        return false;
    }

    out.close();
    in.close();
    return true;
}

auto
main(int argc, char *argv[]) -> int
{
    /* Paths for output */
    std::string outPath{"CSC450_CT5_mod5.txt"};
    std::string reversedPath{"CSC450-mod5-reverse.txt"};

    /* Read user input */
    std::string input{};

    std::cout << "Enter text to save to '" << outPath << "': ";
    std::getline(std::cin, input);

    /* Append input to 'outPath' and save reversed copy to 'reversePath' */
    std::error_code ec{};
    if (!appendToFile(outPath, input, ec))
    {
        std::cerr << "Error when appending '" << input << "' to "
                  << outPath << "." << std::endl;
        std::cerr << ec.message() << "." << std::endl;
        return 1;
    }

    std::cout << "Appended '" << input << "' to " << outPath << "." << std::endl;

    if (!reverseFile(reversedPath, outPath, ec))
    {
        std::cout << "Error when reversing " << outPath << "." << std::endl;
        std::cerr << ec.message() << "." << std::endl;
        return 1;
    }

    std::cout << "Reveresed text in " << outPath << ", saved to " << reversedPath << "." << std::endl;

    return 0;
}
