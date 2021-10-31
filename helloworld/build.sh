#!/bin/bash

. ../upmem-2021.3.0-Linux-x86_64/upmem_env.sh

../upmem-2021.3.0-Linux-x86_64/bin/dpu-upmem-dpurte-clang -o helloworld helloworld.c

gcc --std=c99 helloworld_host.c -o helloworld_host -I ../upmem-2021.3.0-Linux-x86_64/include/dpu -L ../upmem-2021.3.0-Linux-x86_64/lib/ -ldpu -ldpuverbose

./helloworld_host