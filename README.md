# template_library
A template library for C++ with CMake and GoogleTest

## Description
A CMake file template and sample C++ library which allows unit test by GoogleTest. This template Library is :
- Able to collaborate with [Visual Studio CODE](https://azure.microsoft.com/ja-jp/products/visual-studio-code/) editor.
- Build in [GoogleTest](https://github.com/google/googletest) which is downloaded automatically.
- "src" directory for application source code.
- "test" directory for unit tests. 
- std::thread aware. 
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
 Follow the [Usage section of the Template Application](https://github.com/suikan4github/template_application#usage) to build.

When other application uses this library, it can add the source directory only. For example, let's assume we have application "foo" which has the template_library directory in its src directory.  
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
 Follow the [Install section of the Template Application](https://github.com/suikan4github/template_application#install).

## Customize the library
To change the library name, edit the [src/parameter.cmake](src/parameter.cmake) and change following line : 
```CMake
set(MY_LIBRARY_NAME "template_library")
```
The quoted string is the library name. If the MY_LIBRARY_NAME is "foo", the library name becomes "libfoo.a" in GNU toolchain. So, client applications's ld command will have -lfoo parameter in the command line. 

## License
This project is shared with the [MIT License](LICENSE). 