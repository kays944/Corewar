.name "Adder"
.comment "Test add and live"

start:  live %1
        add r1, r1, r2
        zjmp %:start
