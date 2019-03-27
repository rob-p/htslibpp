extern "C" {
#include "htslib/sam.h"
}

#include "htslibpp/BamRecord.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  const char* fn = argv[1];

  samFile *in;
  bam_hdr_t *h;
  BamRecord b;

  in = sam_open(fn, "r");
  h = sam_hdr_read(in);
  int r = 0;

  while ( (r = sam_read1(in, h, &b.rec())) >= 0) {
    std::cerr << b.tid() << "\n";
  }
  std::cerr << "sizeof b = " << sizeof(b) << "\n";

  bam_hdr_destroy(h);
  sam_close(in);
  return 0;
}
