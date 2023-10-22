#include <iostream>
#include <fstream>
#include <string>

class PERSON {
protected:
    std::string name;
    int age;

public:
    PERSON(const std::string& n, int a) : name(n), age(a) {}

    // Stream output and input methods
    friend std::ostream& operator<<(std::ostream& os, const PERSON& person) {
        os << "Name: " << person.name << ", Age: " << person.age;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, PERSON& person) {
        is >> person.name >> person.age;
        return is;
    }
};

class EMPLOYEE : public PERSON {
private:
    std::string position;

public:
    EMPLOYEE(const std::string& n, int a, const std::string& pos) : PERSON(n, a), position(pos) {}

    // Stream output and input methods for EMPLOYEE
    friend std::ostream& operator<<(std::ostream& os, const EMPLOYEE& employee) {
        os << static_cast<const PERSON&>(employee) << ", Position: " << employee.position;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, EMPLOYEE& employee) {
        is >> static_cast<PERSON&>(employee) >> employee.position;
        return is;
    }
};

int main() {
    EMPLOYEE employee("John", 30, "Manager");

    // Output information to the stream
    std::cout << "Employee information: " << employee << std::endl;

    // Input information from the stream
    EMPLOYEE new_employee(" ", 0, " ");
    std::cout << "Enter information for a new employee: ";
    std::cin >> new_employee;
    std::cout << "You entered: " << new_employee << std::endl;

    // Write information to a file
    std::ofstream file("employee.txt");
    file << new_employee;
    file.close();

    // Read information from the file
    std::ifstream file_read("employee.txt");
    EMPLOYEE read_employee(" ", 0, " ");
    file_read >> read_employee;
    file_read.close();
    std::cout << "Employee information from the file: " << read_employee << std::endl;

    return 0;
}
