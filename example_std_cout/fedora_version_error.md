fedora에서 빌드 한 것은 우분투20 에 카피할 경우,, 역시 버전이 높아서 호환이 안 된다. 
```
/usr/bin/ld: /usr/local/lib/std_cout/libstd_cout.so: undefined reference to `std::ios_base_library_init()@GLIBCXX_3.4.32'
```


단,  
ubuntu20 에서 빌드 후 테스트
```
$ cmake ..
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/myuser/Workspace/example_std_cout/build
$ make
[ 50%] Building CXX object CMakeFiles/example_std_cout.dir/src/main.cpp.o
[100%] Linking CXX executable example_std_cout
[100%] Built target example_std_cout
$ ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  example_std_cout  Makefile
$ ./example_std_cout 
hello
hello world
ERROR: unknown
```
우분투 20 에서 빌드한 파일을 복사만 해서 사용할 경우에 fedora 에서도 문제 없이 잘 된다.

