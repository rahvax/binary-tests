DIR  = build
NAME = binary

compile: src/main.c src/binary.c | $(DIR)
	gcc -o $(DIR)/$(NAME) src/main.c src/binary.c -Wall -Wextra -Wpedantic
run: compile
	./$(DIR)/$(NAME)
$(DIR):
	@mkdir -p $(DIR)
