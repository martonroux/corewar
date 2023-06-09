.name "all funcs test"
.comment ""

begin:
live %345
ld %456789, r4
ld 456789, r4
st r3, r9
st r4, 67889
add r4, r5, r6
sub r7, r8, r9
and r1, r2, r3
and 34567, r2, r3
and %98856, r2, r3
and r1, 34567, r3
and r1, %4567891, r3
and r1, 34567, r3
or r1, r2, r3
or 34567, r2, r3
or %98856, r2, r3
or r1, 34567, r3
or r1, %4567891, r3
or r1, 34567, r3
xor r1, r2, r3
xor 34567, r2, r3
xor %98856, r2, r3
xor r1, 34567, r3
xor r1, %4567891, r3
xor r1, 34567, r3
zjmp %4568445
zjmp %:begin
ldi r1, r2, r16
ldi 517282, %65273, r4
sti r6, 76283, %76823
fork %73289
lld 17682, r3
lld %78394, r5
lldi 27839, %17328, r4
lfork %:begin
aff r5