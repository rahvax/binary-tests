DIR  = build
NAME = omega

compile: src/main.c src/binary.c | $(DIR)
	gcc -o $(DIR)/$(NAME) src/main.c src/binary.c
run: compile
	./$(DIR)/$(NAME)
$(DIR):
	@mkdir -p $(DIR)
