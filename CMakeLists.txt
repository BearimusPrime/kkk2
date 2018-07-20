cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME ATM)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

set(HEADER
    Dispatcher.h
    Component.h
    Bank.h
    Message.h
	MessagePort.h
  )

set(SOURCE
    Bank.cpp
  )

add_executable(${PROJECT_NAME} main.cpp ${HEADER} ${SOURCE})

target_link_libraries(${PROJECT_NAME} pthread gtest gmock)
