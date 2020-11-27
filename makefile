all:
	g++ -I./ insert_sort.cc quick_sort.cc quick_sort_test.cc
clean:
	rm a.out
