#include <functional>
#include <iostream>
#include <vector>

class Test {
  public:
    Test(const std::string& name, std::function<void()> testFunction)
        : name(name), testFunction(testFunction) {}

    void run() const {
        std::cout << "Running test for: " << name << std::endl;
        testFunction();
    }

  private:
    std::string name;
    std::function<void()> testFunction;
};

class Tester {
  public:
    void addTest(const std::string& name, std::function<void()> testFunction) {
        tests.emplace_back(name, testFunction);
    }

    ~Tester() {
        std::cout << "Running tests..." << std::endl;
        for (const auto& test : tests) {
            test.run();
        }
    }

  private:
    std::vector<Test> tests;
};

// Example usage
void test1() {
    std::cout << "Test 1: Hello World!" << std::endl;
}

void test2() {
    std::cout << "Test 2: Goodbye World!" << std::endl;
}

int main() {
    Tester tester;
    tester.addTest("Test 1", test1);
    tester.addTest("Test 2", test2);
    // Tests will be run when the Tester object is destroyed
    return 0;
}
