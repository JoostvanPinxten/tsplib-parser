# TSPLIB Parser [![Build Status](https://travis-ci.org/JoostvanPinxten/tsplib-parser.svg?branch=master)](https://travis-ci.org/JoostvanPinxten/tsplib-parser)
A C++ parser/lexer for instances of TSPLIB and GTSPLIB.

## Description
The [Traveling Salesman Problem library (TSPLIB)](http://www.iwr.uni-heidelberg.de/groups/comopt/software/TSPLIB95/) is a collection of example problem data for the [Traveling Salesman Problem](http://en.wikipedia.org/wiki/Travelling_salesman_problem), for which a particular file format has been devised. The [Generalized Traveling Salesman Problem library (GTSPLIB)](http://www.cs.nott.ac.uk/~dxk/gtsp.html) adds a few pieces of information to that.

Many file reader variants can be found, each implementing a subset of the file specification. This repository is aimed to combine effort and eventually create a parser that can read all kinds of TSPLIB and GTSPLIB instances.

Bison/Flex parser for TSPLIB and GTSPLIB instances

## Issues

Please report any issues or feature requests on GitHub. If you have a contribution, you are welcome to send a Pull Request!

## Development

If you want to develop this parser, simply clone this Git and install Bison and Flex. For Windows users, see [WinFlexBison](http://sourceforge.net/projects/winflexbison/).

Run `git submodule update --recursive` to download the dependencies to other Git modules.

The project compiles with MinGW 4.9.1 and the Qt Make system under Windows. It uses [Google Test](https://github.com/google/googletest/tree/master/googletest) for some integration and unit-testing facilities.

Before compiling, you will need to point to the `flex++` and `bison++` executables, so that qmake can generate the lexer and parser components. This is typically done through the environment variables of your shell, or the build system (e.g. Qt Creator).
To use the Qt makefiles, run `qmake` followed by `make` in the root directory. Under Windows, you can use the [winflexbison](https://sourceforge.net/projects/winflexbison/) binaries.
