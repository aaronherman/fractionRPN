rpn: stack.o rpn.o fraction.o
	c++ -g -o rpn rpn.o stack.o fraction.o
stack.o: stack.cpp stack.h
	c++ -g -c stack.cpp
rpn.o: rpn.cpp stack.h
	c++ -g -c rpn.cpp
fraction.o: fraction.cpp fraction.h
	c++ -g -c fraction.cpp
clean:
	rm *.o
	rm rpn
