all:
	g++ -I./ insert_sort.cc quick_sort.cc quick_sort_test.cc
clean:
	rm a.out *.so *.o
binary:
	gcc -fPIC binary_module.c -o binary_module.so -shared -I/usr/include/python3.8/ -lpython3.8
