#include "test.hpp"

#include <exception>

void Test::run() const {
    std::cout << "Running test for: " << name << std::endl;
    testFunction();
}

void Tester::addTest(const std::string& name, std::function<void()> testFunction) {
    tests.emplace_back(name, testFunction);
}

void Tester::addTestCase(const std::string& expected, const std::string& output, int test_case) {
    testCases.emplace_back(expected, output, test_case);
}

Tester::~Tester() {
    std::cout << "Running tests..." << std::endl;
    if (!tests.empty()) {
        for (const auto& test : tests) {
            try {
                test.run();
                std::cout << "Test \"" << test.getName() << "\" is successful" << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Test \"" << test.getName() << "\" failed: " << e.what() << std::endl;
            }
        }
    } else {
        std::cout << "No individual tests found" << std::endl;
    }

    std::cout << "Running test cases..." << std::endl;
    if (!testCases.empty()) {
        for (const auto& testCase : testCases) {
            testCase.run();
        }
    } else {
        std::cout << "No test cases found" << std::endl;
    }

    if (testCases.empty() && tests.empty()) {
        std::cout << "No tests or cases found" << std::endl;
    }
    std::cout << std::endl;
}
