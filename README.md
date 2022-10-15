# Socials

<p align="center"> <a href="https://discord.com/users/xaprier#6129" target="_blank" rel="noreferrer"><img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/discord.svg" width="32" height="32" /></a> <a href="https://www.github.com/xaprier" target="_blank" rel="noreferrer"><img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/github.svg" width="32" height="32" /></a> <a href="http://www.instagram.com/xaprier.dev" target="_blank" rel="noreferrer"><img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/instagram.svg" width="32" height="32" /></a> <a href="https://www.linkedin.com/in/seymen-kalkan-819b01220" target="_blank" rel="noreferrer"><img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/linkedin.svg" width="32" height="32" /></a> <a href="https://twitter.com/xaprier_dev" target="_blank" rel="noreferrer"><img src="https://raw.githubusercontent.com/danielcranney/readme-generator/main/public/icons/socials/twitter.svg" width="32" height="32" /></a></p>

# About qt-nbc

Coded a Qt application with C++ which is converting number bases, calculating the operations on different number bases.

### Recording code sessions and uploaded to YouTube playlist 
<a href="https://www.youtube.com/playlist?list=PLUWaeJl-QWIKn5Faxk4OtXYQWpuSaOQGr" target="_blank">Click for playlist!</a>

# Build - Explained for only UNIX&Linux OS

## Requirements

- Qt5 or Qt6 Widgets
  - https://wiki.qt.io/Install_Qt_5_on_Ubuntu
- Compiler and Linker for C++, Make system for build the project

  - Ubuntu and Debian Based OS:

  ```sh
    sudo apt-get install gcc cmake make && sudo apt-get update
  ```

  - Arch based OS:

  ```sh
    sudo pacman -Syu gcc cmake make
  ```

  - Fedora based OS:

  ```sh
    sudo dnf install gcc cmake make
  ```

## Building

First of all you have to get the source files with Git, If you don't have git you have to install it.

Clone the repository to your directory

```sh
git clone https://github.com/xaprier/qt-nbc.git
```

Enter the direcotry of the source code

```sh
cd qt-notepad/src
```

You can see the CMakeLists.txt which we use for build

Build the makefile with CMake, if you don't have cmake you have to install it.

```sh
cmake -G "Unix Makefiles" -B "../build"
```

Than our Makefile is ready for build the source code. We have to access the directory of makefile and run make.

```sh
cd ../build && make
```

Than our compiled program is ready for run in the directory of the makefile with the name "qt-nbc"
You can run the program with this command

```sh
./qt-nbc
```

# Documentation

## nbc class

- A class which includes number base converting functions
- Only used C++'s main features.
- It can be easily useable on console applications and more...

  - [Header file](https://github.com/xaprier/qt-nbc/blob/main/src/header-files/nbc.h)
  - [Source file](https://github.com/xaprier/qt-nbc/blob/main/src/cpp-files/nbc.cpp)

## choose class

- Qt's MainWindow class which is starting at the beginning for selecting the operation and creating a dialog for that operation.

  - [Header file](https://github.com/xaprier/qt-nbc/blob/main/src/header-files/choose.h)
  - [Source file](https://github.com/xaprier/qt-nbc/blob/main/src/cpp-files/choose.cpp)
  - [UI file](https://github.com/xaprier/qt-nbc/blob/main/src/design-files/choose.ui)

## NBConverter class

- The form dialog class which is shows the converted number bases with using nbc class.

  - [Header file](https://github.com/xaprier/qt-nbc/blob/main/src/header-files/nbconverter.h)
  - [Source file](https://github.com/xaprier/qt-nbc/blob/main/src/cpp-files/nbconverter.cpp)
  - [UI file](https://github.com/xaprier/qt-nbc/blob/main/src/design-files/nbconverter.ui)

## NBCalculator class

- The form dialog class which is calculate the operation of user's request with using the nbc class

  - [Header file](https://github.com/xaprier/qt-nbc/blob/main/src/header-files/nbcalculator.h)
  - [Source file](https://github.com/xaprier/qt-nbc/blob/main/src/cpp-files/nbconverter.cpp)
  - [UI file](https://github.com/xaprier/qt-nbc/blob/main/src/design-files/nbcalculator.ui)
