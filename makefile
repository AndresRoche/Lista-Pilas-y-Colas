FLAG = -Wall -Wextra -Werror -std=c++98 -O3

#all: test_node test_dobleNode test_dqueue test_stack test_list main clean

all: main clean

test_node:
	g++ test/test_node.cpp -o out $(FLAG)
	@./out

test_dobleNode:
	g++ test/test_dobleNode.cpp -o out $(FLAG)
	@./out

test_dqueue:
	g++ test/test_dqueue.cpp -o out $(FLAG)
	@./out

test_stack:
	g++ test/test_stack.cpp -o out $(FLAG)
	@./out

test_list:
	g++ test/test_list.cpp -o out $(FLAG)
	@./out

main:
	g++ main.cpp -o out 
	@./out

clean:
	@rm -f out