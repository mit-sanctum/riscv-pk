
#ifndef _TRNG_H
#define _TRNG_H

#define CSR_TRNG 0xcc0

inline int get_trng_word() {
  return read_csr(CSR_TRNG);
}

#endif // _TRNG_H
