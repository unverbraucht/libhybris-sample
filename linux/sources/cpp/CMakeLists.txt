cmake_minimum_required(VERSION 3.10)

# set the project name
project(HelloJniBrdige LANGUAGES C VERSION 1.0.1 DESCRIPTION "hellojni bridge")

include_directories(/opt/libhybris/include)
include_directories($ENV{JAVA_HOME}/include/)
include_directories($ENV{JAVA_HOME}/include/linux)
LINK_DIRECTORIES(/opt/libhybris/lib)

# add the executable
add_library(HelloJniBridge SHARED hellojni.c)

set_target_properties(HelloJniBridge PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1)
target_link_libraries(HelloJniBridge PUBLIC hybris-common)

INSTALL(TARGETS HelloJniBridge DESTINATION /usr/local/lib)