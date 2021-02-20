#=============================================================================
# Title:        Pseudo Random Number Generator Makefile.
# Algorithm:    Linear Feedback Shift Register (LFSR) 16-bit.
# Filename:     Makefile
# Platform:     Linux / Mac / Un*x
# Language:     Make
# Author:       Justin Lane (atari2600@jigglesoft.co.uk)
# Date:         2021-01-02 20:31
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

all: rndlfsr16-main
	@

rndlfsr16-main: rndlfsr16-main.c rndlfsr16.o
	$(CC) -c rndlfsr16-main.c -o rndlfsr16-main.o
	$(CC) -o rndlfsr16-main rndlfsr16-main.o rndlfsr16.o


rndlfsr16.o: rndlfsr16.c rndlfsr16.h
	$(CC) -c rndlfsr16.c -o rndlfsr16.o


run: all
	./rndlfsr16-main


clean:
	rm -f rndlfsr16-main rndlfsr16-main.o rndlfsr16.o

