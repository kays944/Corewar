.name "Loader"
.comment "Test ld and registers"

start:  live %1
        ld %42, r2
        ld %0, r3
        zjmp %:start