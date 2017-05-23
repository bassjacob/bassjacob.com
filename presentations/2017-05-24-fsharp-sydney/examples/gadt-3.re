eval Zero; /* 0 */

eval (Succ Zero); /* 1 */

eval (Succ (Succ Zero)); /* 2 */

eval (Bool false); /* false */

eval IsZero (Zero); /* true */

eval IsZero (Succ Zero); /* false */

eval (If (IsZero Zero) (Succ Zero) Zero); /* 1 */
