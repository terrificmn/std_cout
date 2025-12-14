# STD_COUT
template functions using std::cout with color  
특별한 기능은 없고 ㅋ 그냥 색깔 표시되어 print를 할 수 있는 기능  
- info 흰색   
- good 초록색  
- warnDev 청록색  
- warn 노란색  
- error 빨간색   
> warn, error 는 cerr 

**cpp 버전: c++17 이상**

## quick installation
다운받은 std_cout_v{version}_ubuntu20.tar.xz 압축을 풀어준다.   
> ubuntu 20.04 에서 빌드 버전, 상위 버전인 ubuntu 22, fedora 40 등에서 호환 잘 됨  

```shell
tar xvf std_cout_v1.0.2_ubuntu20.tar.xz
```
> version 확인

설치
```shell
cd ready-install
./gether.sh install
```
> 압축이 풀린 ready-install 의 README.md 파일 참고  
설치 후 ready-install은 삭제해도 된다   


## build
깃 클론 후 직접 빌드 할 경우  

```shell
git clone https://github.com/terrificmn/std_cout.git
```

build 디렉토리 만든 후 빌드
```shell
~/std_cout
mkdir build; cd build
cmake ..
make
```
/usr/local 이하에 설치
```shell
sudo make install
```

## example_std_cout
간단한 사용법  
example_std_cout 디렉토리에서 빌드 후 테스트 가능 하다.  

example 사용 빌드  
```shell
cd example_std_cout/
mkdir build; cd build
cmake ..
make
```

실행
```shell
./example_std_cout
```
> 물론 std_cout 빌드 및 install 이 된 후 사용해야 한다

## 내 프로젝트에서 사용 시 CMakeLists.txt
내 프로젝트에서 libstd_cout 링크를 해서 사용하려면..  
find_package, target_link_libraries, target_include_directories 정도 사용 해주면 된다.
```cmake
find_package(std_cout REQUIRED)

target_link_libraries(my_pkg PRIVATE ${STD_COUT_LIBRARIES})
target_include_directories(my_pkg PRIVATE ${STD_COUT_INCLUDE_DIR})
```
example_std_cout 의 CMakeLists.txt 파일을 참고

## g++ 빌드 시
libstd_cout 라이브러리를 설치한 후에  g++ 을 이용해서 빌드할 경우에 
link를 -L 과 -l 옵션으로 지정해준다.  

*-L /path/to/std_cout_library -l 라이브러리이름*  

실제 사용 예
```
g++ -std=c++17 main.cpp -o my_proc -L/usr/local/lib/std_cout -lstd_cout
```

이렇게 하면 라이브러리를 잘 찾아서 빌드가 잘 됨.  

빌드가 완료된 후에는 LD_LIBRARY_PATH 변수에 라이브러리 디렉토리를 추가해줘야  
실행시에도 문제가 없다.   
터미널을 열고 
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/std_cout
```

이후 실행파일을 실행해주면 된다. 
> 단, 해당 터미널에서만 유효하며, 계속 사용하려면 ~/.bashrc 파일에 넣거나,    
*/etc/ld.so.conf.d/ 이하에 conf 파일을 만들어서 사용하거나*    
CMakeLists.txt 를 사용해서 빌드해준다.(아래),


## StdCout class 설명
example_std_cout 이하의 src 디렉토리의 main.cpp 파일을 참고  

StdCout 클래스 객체를 만든 후에  
info(), good(), warnDev(), warn(), error() 메소드를 사용하면 된다.  

primitive type의 변수를 파라미터로 넘기는 것을 지원하며,  
여러개를 넘길 경우에는 ,(콤마)로 구분해서 넘겨줄 수가 있다.  
> const char*, std::string, int, bool, double   
지원 안되는 것들은 미리 컴파일 단계에서 에러 발생   

```cpp
StdCout cout;
cout.info("hello");
cout.info("1234");
cout.info(10.0);
cout.info(true);
cout.info(false);
std::cout << std::endl;

cout.good("successful");
cout.good("4321");
cout.good(20.0);
cout.good(false);
cout.good(true);
cout.good("complete!", 2, "times");
std::cout << std::endl;

cout.warn("warn", "world");
float a = 1.5;
bool b = true;
int c = 10;
cout.warn("hello", "world", "a:", a, "b:", b, "c:", c);
std::cout << std::endl;

cout.warnDev("warnDev", "dev-world");
a = 101.5;
b = false;
c = 30;
cout.warnDev("dev", "warning", "a:", a, "b:", b, "c:", c);
cout.warnDev("warning", "green", "a:", a, "b:", b, "c:", c, "res:", true);
std::cout << std::endl;

cout.error("ERROR" ": unknown");
std::string world = "WORLD";
a = 3.14;
b = false;
c = 100;
cout.error("hello", world, "a:", a, "b:", b, "c:", c, "res:", false);
```

## 버전
version 1.2.3    
c++17  
by *Gunther*