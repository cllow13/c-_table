# CMakeList.txt: проект CMake для c++_table; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (c++_table "c++_table.cpp" "c++_table.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET c++_table PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
