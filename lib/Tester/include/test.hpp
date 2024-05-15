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
    [[nodiscard]] std::string getName() const { return name; }

  private:
    std::string name;
    std::function<void()> testFunction;
};

class TestCase {
  public:
    TestCase(const std::string& expected, const std::string& output)
        : expected(expected), output(output) {}

    void run() const {
        if (expected != output) {
            std::cout << "Expected : " << expected << "\n"
                      << "Output : " << output << std::endl;
            assert(expected == output);
        }
    }

  private:
    std::string expected;
    std::string output;
};

class Tester {
  public:
    void addTest(const std::string& name, std::function<void()> testFunction);
    void addTestCase(const std::string& expected, const std::string& output);
    ~Tester();

  private:
    std::vector<Test> tests;
    std::vector<TestCase> testCases;
};

#endif  // TEST_HPP