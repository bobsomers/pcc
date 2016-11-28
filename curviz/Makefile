COMPILER=c++

FLAGS=-std=c++11 -Wall -Werror

INCLUDES=-Inanogui/include \
			   -Inanogui/ext/eigen \
			   -Inanogui/ext/glfw/include \
			   -Inanogui/ext/nanovg/src \
				 -I../libpcc/include

LIBS=-Lnanogui/build -lnanogui \
		 -Lnanogui/build/ext_build/glfw/src -lglfw3 \
		 -L../libpcc -lpcc

MACOS=-framework OpenGL \
		 	-framework Cocoa \
		 	-framework IOKit \
			-framework CoreFoundation \
			-framework CoreVideo

all: curviz

.PHONY: all deps depclean clean

deps:
	git submodule update --init --recursive
	mkdir -p nanogui/build
	pushd nanogui/build && \
		cmake -DNANOGUI_BUILD_EXAMPLE:BOOL=OFF -DNANOGUI_BUILD_PYTHON:BOOL=OFF -DNANOGUI_INSTALL:BOOL=OFF -DNANOGUI_BUILD_SHARED:BOOL=OFF .. && \
	 	make -j4 && \
		popd

depclean:
	rm -rf nanogui/build

curviz: curviz.o ../libpcc/libpcc.a
	$(COMPILER) $(FLAGS) $(LIBS) $(MACOS) -o curviz curviz.o

curviz.o: curviz.cpp
	$(COMPILER) $(FLAGS) $(INCLUDES) -c curviz.cpp

../libpcc/libpcc.a:
	make -C ../libpcc all

clean:
	rm -f *.o curviz
