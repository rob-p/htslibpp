extern "C" {
#include "htslib/sam.h"
}

#include "htslibpp/HTSFile.hpp"
#include "htslibpp/HTSRecord.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  const char* fn = argv[1];

  HTSFile f(fn, HTS_FILE_MODE::READ);
  HTSRecord b;

  int r = 0;
  while ( (r = f.get_next_record(b)) >= 0) {
    std::cerr << b.tid() << "\n";
  }
  std::cerr << "sizeof b = " << sizeof(b) << "\n";
  return 0;
}
