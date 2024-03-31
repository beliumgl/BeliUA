# CMakeList.txt : CMake project for BeliUA, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
add_compile_options(/bigobj) # Add /bigobj option for MSVC compiler


project ("BeliUA")

# Add source to this project's executable.
add_executable (BeliUA "BeliUA.cpp" "Menu/write.cpp" "Menu/doCommands.cpp" "Scripts/clear.cpp" "Scripts/Calculator/calculator.cpp" "Scripts/TimeToUnixConverter/converter.cpp" "Scripts/indevelopment.cpp" "Scripts/AutoClicker/autoclicker.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BeliUA PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
