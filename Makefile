all: app

.PHONY: all deps lib app clean run

deps:
	make -C curviz deps

lib:
	make -C libpcc all

app: lib
	make -C curviz all

clean:
	make -C libpcc clean
	make -C curviz clean

run: app
	./curviz/curviz
