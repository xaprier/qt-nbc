#include "test.hpp"

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
    if (tests.size() > 0) {
        std::cout << "Running tests..." << std::endl;
        for (const auto& test : tests) {
            test.run();
        }
    }

    if (testCases.size() > 0) {
        std::cout << "Running test cases..." << std::endl;
        for (const auto& testCase : testCases) {
            testCase.run();
        }
    }

    if (testCases.empty() && tests.empty()) {
        std::cout << "No tests and cases found" << std::endl;
    }
}