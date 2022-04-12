cmake_minimum_required(VERSION 3.17.0)
project(TextEditor)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES TextEditor/Source.cpp)

FILE(GLOB SOURCE TextEditor/Source/*.cpp)

add_executable(TextEditor ${SOURCE} TextEditor/Source.cpp)

SET(TARGE_H

TextEditor/Headers/TStack.h
TextEditor/Headers/TDataCom.h
TextEditor/Headers/TDataValue.h
TextEditor/Headers/TText.h
TextEditor/Headers/TTextLink.h
)

SET(TARGET_SRC

TextEditor/Headers/TText.cpp
TextEditor/Headers/TTextLink.cpp
)