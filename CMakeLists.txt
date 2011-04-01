cmake_minimum_required(VERSION 2.6)

project(qwt_test)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/Modules")

find_package(Qt4 COMPONENTS QtCore QtGui QtSql Qt3Support REQUIRED)
find_package(Qwt)

include(${QT_USE_FILE})

set(QWT_TEST_HDRS
	barchart_item.h)

set(QWT_TEST_SRCS
	barchart_item.cpp
	main.cpp)

set(PERFTRACK_GUI_UI)

QT4_WRAP_UI(qwt_test_gui_ui ${QWT_TEST_GUI_UI})
QT4_AUTOMOC(${QWT_TEST_GUI_SRCS})

include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${Qwt5_INCLUDE_DIR})

add_executable(qwt_test ${QWT_TEST_SRCS} ${qwt_test_gui_ui})
target_link_libraries(qwt_test ${QT_LIBRARIES} ${Qwt5-Qt4_LIBRARY})

