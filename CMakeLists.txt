cmake_minimum_required(VERSION 3.22)

project(ProjectTP)

#find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

#qt5_add_resources(QT_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/gui.pro)

   # Найдите SFML и добавьте его путь к заголовочным файлам
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

   # Добавьте путь к библиотекам SFML
link_directories(${SFML_LIBRARY_DIR})


add_executable(ProjectTP main.cpp)

target_link_libraries(ProjectTP ncurses)
target_link_libraries(ProjectTP sfml-graphics)