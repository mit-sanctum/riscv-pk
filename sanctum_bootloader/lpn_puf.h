#ifndef _LPN_PUF_H
#define _LPN_PUF_H

// Parameters for PUF
#define CSR_MPUFSELECT (0x7c0)
#define CSR_MPUFREADOUT (0x7c1)
#define CSR_MPUFDISABLE (0x7c2)

// Parameters for PUF-backed key provisioning/recovery
#define NUM_PUF_BITS (512)
#define NUM_KEY_BITS (128)
#define NUM_RETRIES (2)

// A is an NUM_PUF_BITS x NUM_KEY_BITS matrix
char* A = {
 #include "A512x128"
};

// Memory map
Using the following symbols
// MEM_ADDRESS_A
// MEM_ADDRESS_b
// MEM_ADDRESS_s

inline void disable_puf_until_reboot () {
  write_csr(CSR_MPUFDISABLE, 0x1);
}

inline void raw_puf_readout (unsigned int* e) {
  int i;
  for (i=0; i<NUM_PUF_BITS; i++) {
    write_csr(CSR_PUF_SELECT, i);
    e[i] = read_csr(CSR_PUF_READOUT);
  }
}

void provision(unsigned int* A, unsigned int* s, unsigned int* b) {
  // This should only be done once!
  //e' <-- PUF

  mat_vec_mul(unsigned int n, m, int *A, *b *result)


  putstring("PUF SECRET: ");
  int i;
  long p;
  for (i=0; i<512; i++) {
    write_csr(0x7c0, i);
    p = read_csr(0x7c1);
    if (((p>>63)&0x1) == 0) {
      putstring("0");
    } else {
      putstring("1");
    }
  }
  putstring("\n");

  //Compute b = A*b + e

}

void recover(unsigned int* A, unsigned int* s) {
  // e <-- PUF
  disable_puf_until_reboot();

  //retry this X times
  //  sample n rows of e --> e'

  //  Construct augmented matrix for b = As+e'
  //   (b-e') = As
  //  A|(b-e')

  //  Solve for s via gaussian ellimination
  //  Return if successful

  //Crash and burn in caser of failure
}

#endif // _LPN_PUF_H
