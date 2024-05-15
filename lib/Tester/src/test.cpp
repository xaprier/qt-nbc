#include "test.hpp"

#include <exception>

void Test::run() const {
    std::cout << "Running test for: " << name << std::endl;
    testFunction();
}

void Tester::addTest(const std::string& name, std::function<void()> testFunction) {
    tests.emplace_back(name, testFunction);
}

void Tester::addTestCase(const std::string& expected, const std::string& output) {
    testCases.emplace_back(expected, output);
}

Tester::~Tester() {
    if (!tests.empty()) {
        std::cout << "Running tests" << std::endl;
        for (const auto& test : tests) {
            try {
                test.run();
                std::cout << "Test \"" << test.getName() << "\" is successful" << std::endl
                          << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Test \"" << test.getName() << "\" failed: " << e.what() << std::endl
                          << std::endl;
            }
        }
    }

    if (!testCases.empty()) {
        std::cout << "Running test cases" << std::endl;
        for (std::size_t c = 0; c < testCases.size(); c++) {
            testCases.at(c).run();
            std::cout << "Test case " << c + 1 << " is successful" << std::endl;
        }
    }
}
