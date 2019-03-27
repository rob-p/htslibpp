#ifndef __LIBHTSPP_BAM_RECORD__
#define __LIBHTSPP_BAM_RECORD__

extern "C" {
#include "htslib/sam.h"
}

class BamRecord {
private:
  bam1_t rec_;

public:
  BamRecord() {
    clear_core_(rec_.core);
    rec_.l_data = 0;
    rec_.m_data = 0;
    rec_.data = nullptr;
#ifndef BAM_NO_ID
    rec_.id = 0;
#endif // BAM_NO_ID
  }

  bam1_t& rec() { return rec_; }
  auto tid() const { return rec_.core.tid; }
  auto pos() const { return rec_.core.pos; }
  bool is_rev() const { return bam_is_rev(&rec_); }
  bool is_mate_rev() const { return bam_is_mrev(&rec_); }
  auto qname() { return bam_get_qname(&rec_); }
  auto cigar() { return bam_get_cigar(&rec_); }
  auto seq() { return bam_get_seq(&rec_); }
  auto qual() { return bam_get_qual(&rec_); }
  auto aux() { return bam_get_aux(&rec_); }
  auto len_aux() { return bam_get_l_aux(&rec_); }
  auto get_base(int i) { return bam_seqi(seq(), i); }

private:
  void clear_core_(bam1_core_t& core) {
    core.tid = 0;
    core.pos = 0;
    core.bin = 0;
    core.qual = 0;
    core.l_qname = 0;
    core.flag = 0;
    core.unused1 = 0;
    core.l_extranul = 0;
    core.n_cigar = 0;
    core.l_qseq = 0;
    core.mtid = 0;
    core.mpos = 0;
    core.isize = 0;
  }

};

#endif // __LIBHTSPP_BAM_RECORD__
