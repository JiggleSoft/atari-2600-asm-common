#=============================================================================
# Title:        Pseudo Random Number Generator Makefile.
# Algorithm:    Various Linear Feedback Shift Register (LFSR) Algorithms.
# Filename:     Makefile
# Platform:     Linux / Mac / Un*x
# Language:     Make
# Author:       Justin Lane (atari2600@jigglesoft.co.uk)
# Date:         2021-01-10 18:19
# Version:      2.0.0
#-----------------------------------------------------------------------------
# Copyright (c) 2021 Justin Lane
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#-----------------------------------------------------------------------------

all: rnd-main
	@

rnd-main: rnd-main.c rnd.o
	$(CC) -c rnd-main.c -o rnd-main.o
	$(CC) -o rnd-main rnd-main.o rnd.o


rnd.o: rnd.c rnd.h
	$(CC) -c rnd.c -o rnd.o


run: all
	./rnd-main


clean:
	rm -f rnd-main rnd-main.o rnd.o

