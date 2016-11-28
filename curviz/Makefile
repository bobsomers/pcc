COMPILER=c++
FLAGS=-std=c++11 -Wall -Werror \
			-Inanogui/include \
			-Inanogui/ext/eigen \
			-Inanogui/ext/glfw/include \
			-Inanogui/ext/nanovg/src \
			-Lnanogui/build -lnanogui \
			-Lnanogui/build/ext_build/glfw/src -lglfw3
MACOS=-framework OpenGL -framework Cocoa -framework IOKit -framework CoreFoundation -framework CoreVideo

all: app

deps:
	git submodule update --init --recursive
	mkdir -p nanogui/build
	pushd nanogui/build && \
		cmake -DNANOGUI_BUILD_EXAMPLE:BOOL=OFF -DNANOGUI_BUILD_PYTHON:BOOL=OFF -DNANOGUI_INSTALL:BOOL=OFF -DNANOGUI_BUILD_SHARED:BOOL=OFF .. && \
	 	make -j4 && \
		popd

depclean:
	rm -rf nanogui/build

app:
	$(COMPILER) $(FLAGS) $(MACOS) -o curviz curviz.cpp
