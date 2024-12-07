project(common-qt6ct)

#extract version from qt6ct.h
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/qt6ct.h"
     QT6CT_VERSION_DATA REGEX "^#define[ \t]+QT6CT_VERSION_[A-Z]+[ \t]+[0-9]+.*$")

if(QT6CT_VERSION_DATA)
  foreach(item IN ITEMS MAJOR MINOR)
    string(REGEX REPLACE ".*#define[ \t]+QT6CT_VERSION_${item}[ \t]+([0-9]+).*"
       "\\1" QT6CT_VERSION_${item} ${QT6CT_VERSION_DATA})
  endforeach()
  set(QT6CT_VERSION "${QT6CT_VERSION_MAJOR}.${QT6CT_VERSION_MINOR}")
  set(QT6CT_SOVERSION "${QT6CT_VERSION_MAJOR}")
  message(STATUS "qt6ct version: ${QT6CT_VERSION}")
else()
  message(FATAL_ERROR "invalid header")
endif()

add_definitions(-DQT6CT_LIBRARY)

set(app_SRCS
  qt6ct.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)

add_library(common-qt6ct SHARED ${app_SRCS})
set_target_properties(common-qt6ct PROPERTIES VERSION ${QT6CT_VERSION})
target_link_libraries(common-qt6ct PRIVATE Qt6::Gui)
install(TARGETS common-qt6ct DESTINATION ${CMAKE_INSTALL_BINDIR})
