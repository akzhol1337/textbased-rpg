cmake_minimum_required(VERSION 3.17)
project(textbased_rpg)

set(CMAKE_CXX_STANDARD 14)

add_executable(textbased_rpg main.cpp view/Application.cpp view/Application.h model/entity/Character.cpp model/entity/Character.h model/entity/Item.cpp model/entity/Item.h model/entity/Country.cpp model/entity/Country.h model/entity/City.cpp model/entity/City.h)