#! /usr/bin/bash

g++ games/game.cpp engine/initWindow.cpp engine/shaders.cpp glad.c -ldl -lglfw -o program

