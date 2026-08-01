#include "bit_manipulation.h"
#include "safe_input.h"
#include <stdio.h>

void basic_bit_ops_demo(void)
{
    while (1)
    {
        int n;
        int n_status = safe_input_int(&n,
                                      "\n\nBasic Bit Operations demo"
                                      "\nenter an integer to operate on (between -1000 and 1000), "
                                      "enter '-1' to exit:- ",
                                      -1000, 1000);

        if (n_status == INPUT_EXIT_SIGNAL)
        {
            printf("\nExiting basic bit ops demo.\n");
            return;
        }
        if (n_status == 0)
            continue;

        int k;
        int k_status =
            safe_input_int(&k, "\nenter bit position k (0-30), enter '-1' to exit:- ", 0, 30);

        if (k_status == INPUT_EXIT_SIGNAL)
        {
            printf("\nExiting basic bit ops demo.\n");
            return;
        }
        if (k_status == 0)
            continue;

        printf("\n\033[1;36m--- Results for n = %d, k = %d ---\033[0m\n", n, k);
        printf("  set_bit(%d, %d)    = \033[1;32m%d\033[0m\n", n, k, set_bit(n, k));
        printf("  clear_bit(%d, %d)  = \033[1;31m%d\033[0m\n", n, k, clear_bit(n, k));
        printf("  toggle_bit(%d, %d) = \033[1;33m%d\033[0m\n", n, k, toggle_bit(n, k));
        printf("  check_bit(%d, %d)  = \033[1;35m%d\033[0m\n", n, k, check_bit(n, k));
        printf("\033[1;36m-------------------------------\033[0m\n");
    }
}
