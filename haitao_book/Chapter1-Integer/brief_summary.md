### interger_division:
1. The positive and negative boundaries of int type are different; (postitive: 2<sup>31</sup>-1; negative: -2<sup>31</sup>);
2. When calculating values, be careful to check for extraboundary if additions and multiplications occur;
3. Use 0x number well;
### add_binary:
1. Use strings to simulate binary addition;
2. Pay attention to the carry digit at the end of the loop;
### count_bits:
1. Understand the meaning of `i & (i-1)` \ `i & 1` \ `i >> 1`;
2. Identify positive or negative: `i & 1`;
3. The result of integer type divided by two: `i >> 1`;
### single_number:
1. Repeat values are added up, and each bit in result can be divisible by the number of repetitions;
### max_product:
1. Use binary bit as hash table
2. Use `|` operation between bit-hashs instead of comparison loop;
