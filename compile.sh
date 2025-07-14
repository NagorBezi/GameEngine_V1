#! /usr/bin/bash

g++ glad.c\
  games/game.cpp\
  engine/initWindow.cpp\
  engine/shaders.cpp\
  engine/textures.cpp\
  engine/stb_image_implementation.cpp\
  -ldl -lglfw -o program

