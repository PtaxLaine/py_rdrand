from cpython cimport array
from libc.stdint cimport uint32_t, bool

cdef extern from "rdrand.h": 
    uint32_t rdrand_avilable()
    uint32_t rdrand_next()

cdef class RDRand:
    def __init__(self):
        if not rdrand_avilable():
            raise OSError('rdrand not avilable on this system')

    def __call__(self):
        return rdrand_next()
