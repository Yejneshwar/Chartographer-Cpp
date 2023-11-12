cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ChartoGrapher-Cpp")

if(NOT isWorkspace)
	message("Adding GRPC and Protos...")
	include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/AddGrpcAndProtos.cmake)
	ADD_GRPC_AND_PROTOS("ProtoFiles" "ChartographMessenger")
endif()

# Add source to this project's executable.
add_library (ChartoGrapher-Cpp  "Chartographer-Cpp.cpp" "Chartographer-Cpp.h")
target_link_libraries(ChartoGrapher-Cpp PRIVATE grpc++)
target_link_libraries(ChartoGrapher-Cpp PRIVATE ChartoGraphMessenger)


#executable for testing
add_executable (ChartoGrapher-CppTest "Chartographer-Cpp-Test.cpp")
target_link_libraries(ChartoGrapher-CppTest ChartoGrapher-Cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ChartoGrapher-Cpp PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.