#! /usr/bin/bash

g++ glad.c\
  games/game.cpp\
  engine/Window.cpp\
  engine/shaders.cpp\
  engine/textures.cpp\
  engine/stb_image_implementation.cpp\
  -ldl -lglfw -o program

