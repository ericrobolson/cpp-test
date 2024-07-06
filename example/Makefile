main: main.cpp FORCE
	@g++ -std=c++17 -Wall -Werror -Wno-unused-private-field -o main main.cpp && ./main

test: main
	@g++ -std=c++17 -DCPP_UNIT_TEST -Wall -Werror -Wno-unused-private-field -o main main.cpp && ./main

clean: FORCE
	@rm -f main

FORCE:

