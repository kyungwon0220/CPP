cmake_minimum_required(VERSION 3.10) // 요구되는 cmake 도구의 최소 버전

project(Tutorial) // 프로젝트 이름

add_executable(Tutorial tutorial.cpp) // 시행 파일 이름, main.cpp가 실행 파일을 생성하는데 필요한 소스 파일 (참고로, 헤더 파일은 직접 추가하지 않는다.
