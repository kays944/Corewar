.name "Forker"
.comment "Fork and live"

start:  fork %:live
        zjmp %:start
live:   live %1
        zjmp %:live
