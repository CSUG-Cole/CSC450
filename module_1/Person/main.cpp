/*
 * Create a simple C++ console application using Eclipse IDE that will accomplish the following:
 *
 *    First Name,
 *    Last Name,
 *    Street Address
 *    City
 *    Zip code
 *
 *    Prints the information for a fictional person.
 */

#include <algorithm>
#include <iostream>

class Person
{
public:
    /* Explicit Initializer */
    Person(std::string aFirstName,
           std::string aLastName,
           std::string aStreetAddress,
           std::string aCity,
           std::string aZipCode)
        : firstName{std::move(aFirstName)}
        , lastName{std::move(aLastName)}
        , streetAddress{std::move(aStreetAddress)}
        , city{std::move(aCity)}
        , zipCode{std::move(aZipCode)}
    {
        /* Nothing left to initialize. */
    }

    /* Default Initializer */
    Person(): Person{"FIRST_NAME", "LAST_NAME", "STREET_ADDRESS", "CITY", "ZIPCODE"} { }

    Person& setFirstName()
    {
        setData("First Name", firstName);
        return *this;
    };

    Person& setLastName()
    {
        setData("Last Name", lastName);
        return *this;
    };

    Person& setStreetAddress()
    {
        setData("Street Address", streetAddress);
        return *this;
    };

    Person& setCity()
    {
        setData("City", city);
        return *this;
    };

    Person& setZipCode()
    {
        setData("Zip Code", zipCode);
        if (isValidZipCode())
        {
            return *this;
        }
        else
        {
            std::cerr << "Zip Code should be 5 digits i.e., 94513." << std::endl;
            return setZipCode();
        }
    };

    void display()
    {
        /* Display the person in the same format you might address a letter.
         * Format was not specified in the assignment, but this is as good as anything else. */
        std::cout << std::endl
            << firstName << " " << lastName << std::endl
            << streetAddress << std::endl
            << city << " " << zipCode << std::endl;
    };

private:
    bool
    isValidZipCode()
    {
        return zipCode.length() == 5 && std::all_of(zipCode.begin(), zipCode.end(), ::isdigit);
    };

    void
    setData(const std::string& prompt, std::string& to)
    {
        std::cout << prompt << ": ";
        std::getline(std::cin, to);
    };

    std::string firstName;
    std::string lastName;
    std::string streetAddress;
    std::string city;
    std::string zipCode;
};

auto
main(int argc, char *argv[]) -> int
{

    Person person{};

    std::cout << "Please enter the following information for yourself, or someone you know:" << std::endl;
    person.setFirstName()
          .setLastName()
          .setStreetAddress()
          .setCity()
          .setZipCode()
          .display();

    return 0;
}
