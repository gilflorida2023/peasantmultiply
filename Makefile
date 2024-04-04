all: ./peasant_multiply

peasant_multiply: peasant_multiply.c
	gcc '$<' -o '$@'

clean:
	rm ./peasant_multiply
