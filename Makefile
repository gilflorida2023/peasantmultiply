all: ./peasant_multiply

peasant_multiply: peasant_multiply.c
	gcc '$<' -DMAIN=1  -o '$@'

clean:
	rm ./peasant_multiply
