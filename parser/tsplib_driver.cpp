#include "tsplib_driver.h"
#include "tsplib_parser.hpp"

tsplib_driver::tsplib_driver ()
  : trace_scanning (false), trace_parsing (false)
{
  variables["one"] = 1;
  variables["two"] = 2;
}

tsplib_driver::~tsplib_driver ()
{
}

int
tsplib_driver::parse (const std::string &f)
{
  file = f;
  scan_begin ();
  yy::tsplib_parser parser (*this);
  parser.set_debug_level (trace_parsing);
  int res = parser.parse ();
  scan_end ();
  return res;
}

void
tsplib_driver::error (const yy::location& l, const std::string& m)
{
  std::cerr << l << ": " << m << std::endl;
}

void
tsplib_driver::error (const std::string& m)
{
  std::cerr << m << std::endl;
}

