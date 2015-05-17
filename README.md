# TSPLIB Parser
A C++ parser/lexer for instances of TSPLIB and GTSPLIB.

## Description
The [Traveling Salesman Problem library (TSPLIB)](http://www.iwr.uni-heidelberg.de/groups/comopt/software/TSPLIB95/) is a collection of example problem data for the [Traveling Salesman Problem](http://en.wikipedia.org/wiki/Travelling_salesman_problem), for which a particular file format has been devised. The [Generalized Traveling Salesman Problem library (GTSPLIB)](http://www.cs.nott.ac.uk/~dxk/gtsp.html) adds a few pieces of information to that.

Many file reader variants can be found, each implementing a subset of the file specification. This repository is aimed to combine effort and eventually create a parser that can read all kinds of TSPLIB and GTSPLIB instances.

Bison/Flex parser for TSPLIB and GTSPLIB instances

## Issues

Please report any issues or feature requests on GitHub. If you have a contribution, you are welcome to send a Pull Request!

## Development

If you want to develop this parser, simply clone this Git and install Bison and Flex. For Windows users, see [Bison](http://gnuwin32.sourceforge.net/packages/bison.htm) and [Flex](http://gnuwin32.sourceforge.net/packages/flex.htm).