#!/bin/bash

. ../upmem-2021.3.0-Linux-x86_64/upmem_env.sh

../upmem-2021.3.0-Linux-x86_64/bin/dpu-upmem-dpurte-clang -o vector_add_kernel vector_add_kernel.c

g++ --std=c++11 vector_add_host.cpp -o vector_add_host -I ../upmem-2021.3.0-Linux-x86_64/include/dpu -L ../upmem-2021.3.0-Linux-x86_64/lib/ -ldpu -ldpuverbose

./vector_add_host