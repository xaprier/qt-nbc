#ifndef TEST_HPP
#define TEST_HPP

#include <cassert>
#include <functional>
#include <iostream>

class Test {
  public:
    Test(const std::string& name, std::function<void()> testFunction)
        : name(name), testFunction(testFunction) {}

    void run() const;

  private:
    std::string name;
    std::function<void()> testFunction;
};

class TestCase {
  public:
    TestCase(const std::string& expected, const std::string& output, int test_case)
        : expected(expected), output(output), test_case(test_case) {}

    void run() const {
        if (expected == output) {
            std::cout << "Test " << test_case << " is successful!" << std::endl;
        } else {
            std::cerr << "Test " << test_case << " is unsuccessful!!" << std::endl;
            std::cout << "Expected : " << expected << "\n"
                      << "Output : " << output << std::endl;
            assert(expected == output);
        }
    }

  private:
    std::string expected;
    std::string output;
    int test_case;
};

class Tester {
  public:
    void addTest(const std::string& name, std::function<void()> testFunction);
    void addTestCase(const std::string& expected, const std::string& output, int test_case);
    ~Tester();

  private:
    std::vector<Test> tests;
    std::vector<TestCase> testCases;
};

#endif  // TEST_HPP