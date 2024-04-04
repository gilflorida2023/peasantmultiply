# Modified Russian Peasant multiply

## Multiply without multiplication

```text
$ ./peasant_multiply
Remember: Multiplicand × Multiplier = Product
Multiply using the MODIFIED Russian peasant multipliction.(Only addition needed.)
Usage: ./peasant_multiply multiplicand multiplier
Add the numbers in left column marked with asterisk and it totals the multiplicand.
Doubling 1, produces the powers of two.
Add the numbers in right column marked with asterisk and it totals the product.
Created by doubling the multiplier.
./peasant_multiply 10 10
Russian peasant multiply: 10 x 10
        1                      10
        2       *              20
        4                      40
        8       *              80
======================
2 + 8 = 10
======================
NO MULTIPLY ANSWER 20 + 80 = 100
======================
CHECK ANSWER 10 x 10 = 100


** Limited by 64-bit integers

```

## Compile

```bash
    gcc peasant_multiply.c -DMAIN=1 -o peasant_multiply
    #or 
    make
```

## Usage

```text
$ ./peasant_multiply 10 50
Modified Russian peasant multiply: 10 x 50
        1                      50
        2       *             100
        4                     200
        8       *             400
======================
2 + 8 = 10
======================
NO MULTIPLY ANSWER 100 + 400 = 500
======================
CHECK ANSWER 10 x 50 = 500
```
