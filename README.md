<h1 align="center">
  🚀 qt-nbc
</h1>

<p align="center">
  <a href="https://github.com/xaprier/qt-nbc/blob/main/LICENSE" target="blank">
    <img src="https://img.shields.io/github/license/xaprier/qt-nbc" alt="license" />
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
