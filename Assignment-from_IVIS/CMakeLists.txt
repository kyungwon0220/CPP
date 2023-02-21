# 요구되는 cmake 도구의 최소 버전
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름
project(Assignment02.a.01)

# 시행 파일 이름, main.cpp가 실행 파일을 생성>하는데 필요한 소스 파일 (참고로, 헤더 파일은 직접 추가하지 않는다.
add_executable(02.a.01 main.cpp)

# 헤더 파일 참조 문법
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
 # 끝에 ' /include ' 본 CmakeLists.txt 존재 폴더에 include  폴더를 만들어, 참조하겠다는

# ' #include <thread> ' // 쓰레드 라이브러리 사용을 위한 pthread 라이브러리 링크
target_link_libraries(02.a.01 PRIVATE pthread)
 # 헤더 파일과, 구현 내부에서 모두 사용한다면 : PUBLIC
 # 내부 구현에서만 사용하고, 헤더파일에서는 사용하지 않는다면 : PRIVATE
 # 헤더 파일에서만 사요하고, 내부 구현에서는 사용하지 않는다면 : INTERFACE