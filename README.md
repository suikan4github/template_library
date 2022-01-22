# template_library
A template library for C++ with CMake and GoogleTest

## Description
A CMake file template and sample C++ library which allows unit test by GoogleTest. This template Library is :
- Able to collaborate with [Visual Studio CODE](https://azure.microsoft.com/ja-jp/products/visual-studio-code/) editor.
- Build in [GoogleTest](https://github.com/google/googletest) which is downloaded automatically.
- "src" directory for application source code.
- "test" directory for unit tests. 
- std::thread aware. 
- Generate Doxygen document under doc/html during build. 
- Generate Gcov data files during test ( except Windows platform )
- Tested: 
    - Ubuntu 20.04  with GCC.
    - Windows 11 with Visual Studio C++ compiler.
    - WSL2 with VS CODE remote server.
- Automatically tested by GitHub Actions.
    - linux-latest, Debug ( With gcovr report )
    - linux-latest, Release
    - windows-latest, Debug
    - windows-latest, Release
## Screenshots

![](images/debug.png)

Fig.1 Source code debugging on VS CODE.

![](images/ctest.png)

Fig.2 CTest on VS CODE.

![](images/gcov.png)

Fig. 3 Code coverage visualization by [Gcov Viewer extension](https://marketplace.visualstudio.com/items?itemName=JacquesLucke.gcov-viewer).

![](images/gcovr.png)

Fig. 4 Code coverage report by the [GitHub Actions](https://github.com/suikan4github/template_library/runs/4761910409?check_suite_focus=true). 

## Requirement
### Ubuntu
- Ubuntu 20.04
- VS Code
- CMake 3.15 or newer
- Python 3
- g++
### Windows
- Windows 10 or 11
- VS Code
- CMake 3.15 or newer
- Python 3
- Microsoft Visual C++ compiler 
### WSL2
- Windows 10 or 11
- VS Code with [Remote Development extension pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack)
- CMake 3.15 or newer
- Python 3
- g++
- ca-certificates

## Usage
### Visual Studio CODE
Run the followings command inside this directory ( Where README.md exists) to start the VS CODE: 
```Shell
code .
```
Inside VS CODE, Type Ctrl-Shift-P to show the command pallet. And then, execute following command :
```
CMake: Configure
```
Now, you can build, run the executable and Ctest from the status bar of the VS CODE.

![](image/statusbar.png)
### Command line
Run the followings commands inside this directory ( Where README.md exists) : 
```Shell
mkdir build
cd build
cmake ..
cmake --build .
```
The executables are stored in the subdirectories: 
- build/src
- build/test

In the case of MS Visual Studio C, the executables are located under the build configuration subdirectories like :
- build/src/Debug, build/src/Release
- build/test/Debug, build/test/Release

To run the Ctest, type :
```Shell
ctest
```

When other application uses this library, you can add the source directory only. For example, let's assume we have application "foo" which has the template_library directory in its src directory.  
```
foo
├── CMakeLists.txt
├── src
│   ├── CMakeLists.txt
│   └── template_library
│       ├── CMakeLists.txt
│       ├── src
│       │   └── CMakeLists.txt
│       └── test
│           └── CMakeLists.txt
└── test
    └── CMakeLists.txt

```
In this case, foo/CMakeLists.txt must has following command : 
```
add_subdirectory("src/template_library/src")
```
The src/template_library should not be added as subdirectory. Otherwise, the settings of the project parameters may cause conflict. 

## Install
 
### Ubuntu
Run followings on the shell. 
```Shell
sudo snap install code --classic
sudo apt-get install build-essential cmake doxygen
```
- Note 1: After installing VS CODE, install the [C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) and the [Gcov Viewer extension](https://marketplace.visualstudio.com/items?itemName=JacquesLucke.gcov-viewer) to the VS CODE.
### Windows

Run followings on the PowerShell or Command . 
```PowerShell
winget install Microsoft.VisualStudioCode -e
winget install Kitware.CMake -e
winget install Microsoft.VisualStudio.2022.Community -e
winget install Git.Git -e
winget install Python.Python.3 -e
winget install doxygen -e
```
- Note 1: After installing VS CODE, install the [C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) and the [Gcov Viewer extension](https://marketplace.visualstudio.com/items?itemName=JacquesLucke.gcov-viewer) to the VS CODE.
- Note 2: The above winget install the CMake installer only. Run the CMake once and complete the installation.
- Note 3: The above wget install the VisualStudio launcher only. [Install the C++ workload](https://docs.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170) after winget installation.

After the installation, set the PATH environment variable for CMake, Visual Studio C and Git. 

### WSL2

Run followings on the PowerShell or Command to install the Visual Studio CODE editor. 
```PowerShell
winget install Microsoft.VisualStudioCode -e
```
Then, run followings on the Ubuntu shell. 
```Shell
sudo apt-get install build-essential cmake doxygen ca-certificates
```
- Note 1: After installing VS CODE, install the [C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) and the [Gcov Viewer extension](https://marketplace.visualstudio.com/items?itemName=JacquesLucke.gcov-viewer) to the VS CODE.


## Customize the library
To change the library name, edit the [src/parameter.cmake](src/parameter.cmake) and change following line : 
```CMake
set(MY_LIBRARY_NAME "template_library")
```
The quoted string is the library name. If the MY_LIBRARY_NAME is "foo", the library name becomes "libfoo.a" in GNU toolchain. So, client applications's ld command will have -lfoo parameter in the command line. 

## License
This project is shared with the [MIT License](LICENSE). 