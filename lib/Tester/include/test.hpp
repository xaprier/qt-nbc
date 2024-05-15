#ifndef TEST_HPP
#define TEST_HPP

#include <cassert>
#include <functional>
#include <iostream>

class Test {
  public:
    Test(std::string name, std::function<void()> testFunction)
        : name(std::move(name)), testFunction(std::move(testFunction)) {}

    void run() const;
    [[nodiscard]] std::string getName() const { return name; }

  private:
    std::string name;
    std::function<void()> testFunction;
};

class TestCase {
  public:
    TestCase(std::string expected, std::string output)
        : expected(std::move(expected)), output(std::move(output)) {}

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
    // Default constructor
    Tester() = default;

    // Copy constructor
    Tester(const Tester& other) : tests(other.tests), testCases(other.testCases) {}

    // Copy assignment operator
    Tester& operator=(const Tester& other) {
        if (this != &other) {
            // Implement copy assignment logic here
            tests = other.tests;
            testCases = other.testCases;
        }
        return *this;
    }

    // Move constructor
    Tester(Tester&& other) noexcept : tests(std::move(other.tests)), testCases(std::move(other.testCases)) {}

    // Move assignment operator
    Tester& operator=(Tester&& other) noexcept {
        if (this != &other) {
            // Implement move assignment logic here
            tests = std::move(other.tests);
            testCases = std::move(other.testCases);
        }
        return *this;
    }

    void addTest(const std::string& name, std::function<void()> testFunction);
    void addTestCase(const std::string& expected, const std::string& output);
    ~Tester();

  private:
    std::vector<Test> tests;
    std::vector<TestCase> testCases;
};

#endif  // TEST_HPP