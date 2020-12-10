CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
        unit_test.cpp DueDateDecorator.cpp DueDateSort.cpp Project.cpp DateAddedSort.cpp ImportanceDecorator.cpp ImportanceSort.cpp Task.cpp
        )

ADD_EXECUTABLE(project
        DueDateDecorator.cpp DueDateSort.cpp Project.cpp DateAddedSort.cpp ImportanceDecorator.cpp ImportanceSort.cpp main.cpp Task.cpp
        )

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)