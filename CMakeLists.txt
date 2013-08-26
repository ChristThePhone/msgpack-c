CMAKE_MINIMUM_REQUIRED (VERSION 2.6.4)
PROJECT (msgpack)

SET (VERSION 0.5.8)
SET (VERSION_MAJOR 0)
SET (VERSION_MINOR 5)

SET (prefix ${CMAKE_INSTALL_PREFIX})
SET (exec_prefix "\${prefix}")
SET (libdir "\${exec_prefix}/lib")
SET (includedir "\${prefix}/include")

OPTION (MSGPACK_CXX11 "Using c++11 compiler" OFF)

IF (MSGPACK_CXX11)
   IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
      SET (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
   ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
      SET (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
   ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
      MESSAGE ( FATAL_ERROR "MSVC doesn't support C++11 yet.")
   ENDIF ()
ENDIF ()

FIND_PACKAGE (GTest)
FIND_PACKAGE (ZLIB)
FIND_PACKAGE (Threads)
IF (GTEST_FOUND AND ZLIB_FOUND AND THREADS_FOUND)
	OPTION (MSGPACK_BUILD_TESTS "Build msgpack tests." ON)
ENDIF ()


# Files to copy

MACRO (COPY_FILE SOURCE DESTINATION)
	# COPY_FILE (readme.txt dir1/dir2/) would add new target
	# that will copy readme.txt to dir1/dir2 where dir1 will be located
	# in current binary directory.
	ADD_CUSTOM_COMMAND (
		OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${DESTINATION}/${SOURCE}
		COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/${DESTINATION}
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE} ${CMAKE_CURRENT_BINARY_DIR}/${DESTINATION}/${SOURCE}
	)
ENDMACRO ()

IF (MSGPACK_CXX11)
   COPY_FILE (cpp11/zone.hpp src/msgpack/zone.hpp)
   COPY_FILE (cpp11/define.hpp src/msgpack/type/define.hpp)
   COPY_FILE (cpp11/tuple.hpp src/msgpack/type/tuple.hpp)
ENDIF ()

OPTION (MSGPACK_ENABLE_CXX "Enable C++ interface." ON)

INCLUDE (CheckCXXSourceCompiles)
CHECK_CXX_SOURCE_COMPILES ("
#include <bits/atomicity.h>
int atomic_sub(int i) { return __gnu_cxx::__exchange_and_add(&i, -1) - 1; }
int atomic_add(int i) { return __gnu_cxx::__exchange_and_add(&i, 1) + 1; }
int main(int argc, char * argv[])
{
	atomic_sub(1);
	atomic_add(1);
}
" MSGPACK_ENABLE_GCC_CXX_ATOMIC)

IF (MSGPACK_ENABLE_CXX)
	LIST (APPEND msgpack_SOURCES
		src/object.cpp
	)
ENDIF ()

IF (MSGPACK_ENABLE_GCC_CXX_ATOMIC)
	LIST (APPEND msgpack_SOURCES
		src/gcc_atomic.cpp
	)
ENDIF ()


LIST (APPEND msgpack_SOURCES
	src/unpack.c
	src/objectc.c
	src/version.c
	src/vrefbuffer.c
	src/zone.c
)

LIST (APPEND msgpack_HEADERS
	src/msgpack/pack_define.h
	src/msgpack/pack_template.h
	src/msgpack/unpack_define.h
	src/msgpack/unpack_template.h
	src/msgpack/sysdep.h
	src/msgpack/sbuffer.h
	src/msgpack/version.h
	src/msgpack/vrefbuffer.h
	src/msgpack/zbuffer.h
	src/msgpack/pack.h
	src/msgpack/unpack.h
	src/msgpack/object.h
	src/msgpack/zone.h
)

IF (MSGPACK_ENABLE_CXX)
	LIST (APPEND msgpack_HEADERS
		src/msgpack.hpp
		src/msgpack/sbuffer.hpp
		src/msgpack/vrefbuffer.hpp
		src/msgpack/zbuffer.hpp
		src/msgpack/pack.hpp
		src/msgpack/unpack.hpp
		src/msgpack/object.hpp
		src/msgpack/zone.hpp
		src/msgpack/type.hpp
		src/msgpack/type/bool.hpp
		src/msgpack/type/deque.hpp
		src/msgpack/type/float.hpp
		src/msgpack/type/fixint.hpp
		src/msgpack/type/int.hpp
		src/msgpack/type/list.hpp
		src/msgpack/type/map.hpp
		src/msgpack/type/nil.hpp
		src/msgpack/type/pair.hpp
		src/msgpack/type/raw.hpp
		src/msgpack/type/set.hpp
		src/msgpack/type/string.hpp
		src/msgpack/type/vector.hpp
		src/msgpack/type/tuple.hpp
		src/msgpack/type/define.hpp
		src/msgpack/type/tr1/unordered_map.hpp
		src/msgpack/type/tr1/unordered_set.hpp
	)
ENDIF ()

IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	SET_SOURCE_FILES_PROPERTIES(${msgpack_SOURCES} PROPERTIES LANGUAGE CXX)
ENDIF ()

EXECUTE_PROCESS (
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/src/msgpack
)

CONFIGURE_FILE (
	src/msgpack/version.h.in
	${CMAKE_CURRENT_BINARY_DIR}/src/msgpack/version.h
)
CONFIGURE_FILE (
	src/msgpack/version.hpp.in
	${CMAKE_CURRENT_BINARY_DIR}/src/msgpack/version.hpp
)

CONFIGURE_FILE (
	msgpack.pc.in
	msgpack.pc
	@ONLY
)

INCLUDE_DIRECTORIES (
	./
	src/
	src/msgpack/
	${CMAKE_CURRENT_BINARY_DIR}/src/
	${CMAKE_CURRENT_BINARY_DIR}/src/msgpack/
)

ADD_LIBRARY (msgpack SHARED
	${msgpack_SOURCES}
	${msgpack_HEADERS}
)

ADD_LIBRARY (msgpack-static STATIC
	${msgpack_SOURCES}
	${msgpack_HEADERS}
)

SET_TARGET_PROPERTIES (msgpack-static PROPERTIES OUTPUT_NAME "msgpack")
SET_TARGET_PROPERTIES (msgpack PROPERTIES IMPORT_SUFFIX "_import.lib")
SET_TARGET_PROPERTIES (msgpack PROPERTIES SOVERSION 3 VERSION 3.0.0)

IF (MSGPACK_BUILD_TESTS)
	ENABLE_TESTING ()
	ADD_SUBDIRECTORY (test)
ENDIF ()

INSTALL (TARGETS msgpack msgpack-static DESTINATION lib)
INSTALL (DIRECTORY src/msgpack DESTINATION include)
INSTALL (FILES src/msgpack.h src/msgpack.hpp DESTINATION include)
INSTALL (FILES msgpack.pc DESTINATION lib/pkgconfig)

# Doxygen
FIND_PACKAGE (Doxygen)
IF (DOXYGEN_FOUND)
	ADD_CUSTOM_TARGET (
		doxygen_c
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile_c
		COMMAND ${CMAKE_COMMAND} -E echo "FILE_PATTERNS      = *.h" >> ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile_c
		COMMAND ${CMAKE_COMMAND} -E echo "OUTPUT_DIRECTORY   = doc_c" >> ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile_c
		COMMAND ${CMAKE_COMMAND} -E echo "PROJECT_NAME       = \"MessagePack for C\"" >> ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile_c
		COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile_c
		VERBATIM
	)
	ADD_CUSTOM_TARGET (
		doxygen_cpp
		COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile_cpp
		COMMAND ${CMAKE_COMMAND} -E echo "FILE_PATTERNS      = *.hpp" >> ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile_cpp
		COMMAND ${CMAKE_COMMAND} -E echo "OUTPUT_DIRECTORY   = doc_cpp" >> ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile_cpp
		COMMAND ${CMAKE_COMMAND} -E echo "PROJECT_NAME       = \"MessagePack for C++\"" >> ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile_cpp
		COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile_cpp
		VERBATIM
	)
	ADD_CUSTOM_TARGET (
		doxygen
		DEPENDS doxygen_c doxygen_cpp
	)
ENDIF ()