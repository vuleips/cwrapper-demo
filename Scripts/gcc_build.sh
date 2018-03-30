src=/src
src_obj=/src_obj
src_bin=/src_bin
outputlib_name=libKernelCWrapper.so

mkdir -p $src_obj
mkdir -p $src_bin

g++ -c -x c++ $src/c_wrapper.cpp -g2 -gdwarf-2 -o $src_obj/c_wrapper.o  \
    -Wall -Wswitch -W"no-deprecated-declarations" -W"empty-body" -Wconversion -W"return-type"   \
    -Wparentheses -W"no-format" -Wuninitialized -W"unreachable-code" -W"unused-function" -W"unused-value" \
    -W"unused-variable" -O0 -fno-strict-aliasing -fno-omit-frame-pointer -fpic \
    -fthreadsafe-statics -fexceptions -frtti -std=c++11

g++ -o $src_bin/$outputlib_name -Wl,--no-undefined -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack \
    -shared $src_obj/c_wrapper.o
