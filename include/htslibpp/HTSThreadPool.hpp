#ifndef __LIBHTSPP_HTS_THREADPOOL__
#define __LIBHTSPP_HTS_THREADPOOL__

extern "C" {
#include "htslib/sam.h"
#include "htslib/thread_pool.h"
}


class HTSThreadPool {
private:
  htsThreadPool p_{nullptr, 0};
public:
  HTSThreadPool() {}
 
  ~HTSThreadPool() {
    if (p_.pool) {
      hts_tpool_destroy(p_.pool);
    }
  }

  htsThreadPool& get_pool() { return p_; }
  bool init(int32_t num_threads) {
    p_.pool = hts_tpool_init(num_threads);
    return (p_.pool);
  }
};

#endif // __LIBHTSPP_HTS_THREADPOOL__
