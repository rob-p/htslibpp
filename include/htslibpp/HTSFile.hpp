#ifndef __LIBHTSPP_HTS_FILE__
#define __LIBHTSPP_HTS_FILE__

extern "C" {
#include "htslib/sam.h"
}

#include <iostream>
#include "htslibpp/HTSRecord.hpp"

enum class HTS_FILE_MODE : uint8_t {
  READ = 0,
  WRITE = 1,
  APPEND = 2,
  READ_WRITE = 3
};

std::string to_string(HTS_FILE_MODE m) {
  switch (m) {
  case HTS_FILE_MODE::READ:
    return "r";
  case HTS_FILE_MODE::WRITE:
    return "w";
  case HTS_FILE_MODE::APPEND:
    return "a";
  case HTS_FILE_MODE::READ_WRITE:
    return "rw";
  }
}

class HTSFile {
private:
  htsFile* fh_;
  bam_hdr_t* hdr_;
  bool valid_{false};

public:
  HTSFile() : fh_(nullptr), hdr_(nullptr) {}

  HTSFile(const std::string& fname, HTS_FILE_MODE m) {
    auto ms = to_string(m);
    fh_ = hts_open(fname.c_str(), ms.c_str());
    if (fh_ == NULL) {
      // determine how we want to deal with this
      std::cerr << "failed to open file " << fname << "\n";
    } else {
      hdr_ = sam_hdr_read(fh_);
      if (hdr_ == NULL) {
        std::cerr << "couldn't read header for file " << fname << "\n";
      }
      valid_ = true;
    }
  }

  HTSFile(const char* fname, HTS_FILE_MODE m) : HTSFile(std::string(fname), m) {}

  ~HTSFile() {
    if (hdr_) { bam_hdr_destroy(hdr_); }
    if (fh_) { hts_close(fh_); }
  }

  int get_next_record(HTSRecord& r) {
    return sam_read1(fh_, hdr_, &r.rec());
  }

};

#endif // __LIBHTSPP_HTS_FILE__
