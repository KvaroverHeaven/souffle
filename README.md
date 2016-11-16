
# Soufflé

[![Build Status](https://travis-ci.org/oracle/souffle.svg?branch=master)](https://travis-ci.org/oracle/souffle)

Soufflé is a translator of declarative Datalog programs into the C++ language.  Soufflé is used as a domain-specific language for static program analysis, over large code bases with millions of lines of code.  Soufflé aims at producing high-performance C++ code that can be compiled with the native compiler on the target machine.  

## Features of Soufflé

*   Efficient translation to parallel C++ of Datalog programs
*   Extended semantics of Safe Datalog, e.g., permitting unbounded recursions with numbers 
*   Simple component model for Datalog specifications 
*   Recursively defined record types for tuples 
*   Static type system for attributes

## Documentation 

https://github.com/oracle/souffle/wiki

## Contributors

https://github.com/oracle/souffle/wiki/Contributors

## How to get Soufflé
 
Use git to obtain the source code of Soufflé. 

    $ git clone git://github.com/oracle/souffle.git

## Mailing list

There is no mailing list to talk about Soufflé at the moment. It will be established soon. 

## How to compile and install 

Follow the steps below to compile and install Soufflé on a UNIX system:


1.  G++ 4.8 or newer is recommended to compile Soufflé. 

2.  Run `sh ./bootstrap` to generate configure files 

3.  For Linux users, skip this step. MAC OS X does not have C++/OpenMP nor a bison version 3.0.2 installed.
    We recommend [brew](http://brew.sh) to install the required tools to build Soufflé. Run the following commands prior to executing `./configure`:
```
     brew update                
     brew reinstall gcc --without-multilib                
     brew install bison                
     export CXX=/usr/local/bin/g++-5                
     export CXXFLAGS=-fopenmp                
     export SOUFFLECPP=/usr/local/bin/cpp-5
     export BISON=/usr/local/opt/bison/bin/bison
```

4.  Run `./configure`

5.  Run `make` to build the executable of Soufflé

6.  Test the executable with `make check` to check whether the compilation of Soufflé succeeded.

7.  Run `make install`

    This command will create the directories and install files in `${DESTDIR}${prefix}` for system-wide use in your system.

## License

See [LICENSE](https://github.com/souffle-lang/souffle/blob/master/LICENSE).
