#! /usr/bin/bash

g++ glad.c\
  games/game.cpp\
  engine/Window.cpp\
  engine/textures.cpp\
	engine/shaders.cpp\
  engine/input.cpp\
  engine/stb_image_implementation.cpp\
  -ldl -lglfw -o program

