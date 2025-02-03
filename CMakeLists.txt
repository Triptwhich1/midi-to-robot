cmake_minimum_required(VERSION 3.29)
project(midi_robot C)

set(CMAKE_C_STANDARD 11)

add_executable(midi_robot
    speaker-from-midi.c)
