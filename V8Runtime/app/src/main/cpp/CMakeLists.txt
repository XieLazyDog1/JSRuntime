# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("v8runtime")

MESSAGE(STATUS "## ANDROID_NDK_ROOT: " ${ANDROID_NDK_ROOT})
set(COMMON_CMAKE_ARGUMENTS "-nostdinc++ -std=c++14  -Werror -Wno-unused-result -mstackrealign -fexceptions -fno-builtin-stpcpy -fno-rtti -D_LIBCPP_ABI_VERSION=Cr -D_LIBCPP_ENABLE_NODISCARD -D_LIBCPP_ABI_UNSTABLE -DV8_31BIT_SMIS_ON_64BIT_ARCH -DV8_31BIT_SMIS_ON_64BIT_ARCH -DV8_ENABLE_REGEXP_INTERPRETER_THREADED_DISPATCH -DV8_EMBEDDED_BUILTINS")

if("${ANDROID_ABI}" MATCHES "arm64-v8a$" OR "${ANDROID_ABI}" MATCHES "x86_64$")
    # Enable pointer compression on 64 bit platforms
    set(COMMON_CMAKE_ARGUMENTS "${COMMON_CMAKE_ARGUMENTS} -DV8_COMPRESS_POINTERS")
endif()

set(CMAKE_CXX_FLAGS "${COMMON_CMAKE_ARGUMENTS} -g")

include_directories(
        include
        include/libc++
        ../../../libs/${ANDROID_ABI}/include
)


# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        v8runtime

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ValueConverter.cpp
        Utils.cpp
        JSRuntimeException.cpp
        JSRuntime.cpp
        native-lib.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library(system-z z)
find_library(system-android android)
find_library( # Sets the name of the path variable.
        log-lib
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        v8runtime

        # Links the target library to the logw library
        # included in the NDK.
        ${PROJECT_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libzip.a
        ${PROJECT_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libv8.a

        ${system-z}
        ${system-android}
        ${log-lib})