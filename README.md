<h1 align="center">
  🚀 tester
</h1>

<p align="center">
  <a href="https://github.com/xaprier/tester/blob/main/LICENSE" target="blank">
    <img src="https://img.shields.io/github/license/xaprier/tester" alt="license" />
  </a>
</p>

<b>qt-nbc</b> is widget based qt program for converting number bases, calculating the operations on different number bases written with C++.

### 🛠️ Build Instructions for Linux/UNIX

First of all you have to get the source files with Git, If you don't have git you have to install it.

Clone the repository to your directory

```sh
git clone --recurse-submodules https://github.com/xaprier/qt-nbc.git
```

Enter the direcotry of the source code

```sh
cd qt-nbc
```

You can see the CMakeLists.txt which we use for build

```sh
cmake -G "Unix Makefiles" -B "build"
```

Than our Makefile is ready for build the source code. We have to access the directory of makefile and run make.

```sh
cd build && make -j $(nproc - 1)
```

Than our compiled program and libraries is ready for run in the directory of the makefile with the name "<b>qt-nbc</b>"
You can run the program with this command

```sh
./qt-nbc
```

### 📚 Dependencies

- Qt 5/6 Widgets
- CMake(for building the project)
- Git(for cloning repository and it's submodules)

## Documentation

<details>
<summary>Click for adjust</summary>

### Number Class

- Template Class for using Decimal, Octal, Binary, Hexadecimal as a Number
  - [Header file](https://github.com/xaprier/qt-nbc/blob/main/lib/Number.h)

### Binary/Octal/Decimal/Hexadecimal Class

- The Classes which includes the operations(+,-,_,/,%,+=,-=,_=,%=,=) in Number Bases
- [Binary Header file](https://github.com/xaprier/qt-nbc/blob/main/lib/Binary.h)
  - [Source files](https://github.com/xaprier/qt-nbc/blob/main/lib/Binary)
  - [Binary.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Binary/Binary.cpp) Constructors, converter functions, assignment operators
  - [dividing.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Binary/dividing.cpp) Dividing operators(/, /=)
  - [multiplying.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Binary/multiplying.cpp) Multiply operators(_,_=)
  - [remainder.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Binary/remainder.cpp) Remainder operators(%, %=)
  - [subtracting.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Binary/subtracting.cpp) Subtracting operators(-, -=)
  - [summing.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Binary/summing.cpp) Addition operators(+, +=)
- [Octal Header file](https://github.com/xaprier/qt-nbc/blob/main/lib/Octal.h)
  - [Source files](https://github.com/xaprier/qt-nbc/blob/main/lib/Octal)
  - [Octal.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Octal/Octal.cpp) Constructors, converter functions, assignment operators
  - [dividing.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Octal/dividing.cpp) Dividing operators(/, /=)
  - [multiplying.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Octal/multiplying.cpp) Multiply operators(_,_=)
  - [remainder.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Octal/remainder.cpp) Remainder operators(%, %=)
  - [subtracting.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Octal/subtracting.cpp) Subtracting operators(-, -=)
  - [summing.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Octal/summing.cpp) Addition operators(+, +=)
- [Decimal Header file](https://github.com/xaprier/qt-nbc/blob/main/lib/Decimal.h)
  - [Source files](https://github.com/xaprier/qt-nbc/blob/main/lib/Decimal)
  - [Decimal.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Decimal/Decimal.cpp) Constructors, converter functions, assignment operators
  - [dividing.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Decimal/dividing.cpp) Dividing operators(/, /=)
  - [multiplying.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Decimal/multiplying.cpp) Multiply operators(_,_=)
  - [remainder.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Decimal/remainder.cpp) Remainder operators(%, %=)
  - [subtracting.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Decimal/subtracting.cpp) Subtracting operators(-, -=)
  - [summing.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Decimal/summing.cpp) Addition operators(+, +=)
- [Hexadecimal Header file](Hexadecimal.h)
  - [Source files](https://github.com/xaprier/qt-nbc/blob/main/lib/Hexadecimal)
  - [Hexadecimal.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Hexadecimal/Hexadecimal.cpp) Constructors, converter functions, assignment operators
  - [dividing.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Hexadecimal/dividing.cpp) Dividing operators(/, /=)
  - [multiplying.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Hexadecimal/multiplying.cpp) Multiply operators(_,_=)
  - [remainder.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Hexadecimal/remainder.cpp) Remainder operators(%, %=)
  - [subtracting.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Hexadecimal/subtracting.cpp) Subtracting operators(-, -=)
  - [summing.cpp](https://github.com/xaprier/qt-nbc/blob/main/lib/Hexadecimal/summing.cpp) Addition operators(+, +=)

### Base Class

    - The base class which using for Polymorphism and Inheritance
    - Includes my algorithms for calculating sum, subtraction, multiplaction and the divide
    - Also includes the operator overloadings for logical operators
    - [Header file](https://github.com/xaprier/qt-nbc/blob/main/lib/Number/NumberBase.h)
    - [Source file](https://github.com/xaprier/qt-nbc/blob/main/lib/Number/Base/NumberBase.cpp)

### choose class

- Qt's MainWindow class which is starting at the beginning for selecting the operation and creating a dialog for that operation.

  - [Header file](https://github.com/xaprier/qt-nbc/blob/main/src/header-files/choose.h)
  - [Source file](https://github.com/xaprier/qt-nbc/blob/main/src/cpp-files/choose.cpp)
  - [UI file](https://github.com/xaprier/qt-nbc/blob/main/src/design-files/choose.ui)

### NBConverter class

- The form dialog class which is shows the converted number bases with using nbc class.

  - [Header file](https://github.com/xaprier/qt-nbc/blob/main/src/header-files/nbconverter.h)
  - [Source file](https://github.com/xaprier/qt-nbc/blob/main/src/cpp-files/nbconverter.cpp)
  - [UI file](https://github.com/xaprier/qt-nbc/blob/main/src/design-files/nbconverter.ui)

### NBCalculator class

- The form dialog class which is calculate the operation of user's request with using the nbc class

  - [Header file](https://github.com/xaprier/qt-nbc/blob/main/src/header-files/nbcalculator.h)
  - [Source file](https://github.com/xaprier/qt-nbc/blob/main/src/cpp-files/nbconverter.cpp)
  - [UI file](https://github.com/xaprier/qt-nbc/blob/main/src/design-files/nbcalculator.ui)

</details>
