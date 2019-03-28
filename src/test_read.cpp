extern "C" {
#include "htslib/sam.h"
}

#include "htslibpp/HTSFile.hpp"
#include "htslibpp/HTSRecord.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  const char* fn = argv[1];

  try {
    HTSThreadPool p; p.init(5);
    HTSFile f(fn, HTS_FILE_MODE::READ);
    f.set_thread_pool(p);

    HTSRecord b;

    int r = 0;
    while ( (r = f.get_next_record(b)) >= 0) {
      std::cerr << b.tid() << "\n";
    }
    std::cerr << "sizeof b = " << sizeof(b) << "\n";
  } catch (std::exception& e) {
    std::cerr << "EXCEPTION : [" << e.what() << "]\n";
    return 1;
  }
  return 0;
}
