#=============================================================================
# Title:        Missile Aiming 2D Vector Calculator Makefile.
# Algorithm:    Calculate specific magnitude vector between two co-ordinates.
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

all: aim-main
	@

aim-main: aim-main.c aim.o
	$(CC) -c aim-main.c -o aim-main.o
	$(CC) -o aim-main aim-main.o aim.o


aim.o: aim.c aim.h
	$(CC) -c aim.c -o aim.o


run: all
	./aim-main


clean:
	rm -f aim-main aim-main.o aim.o

