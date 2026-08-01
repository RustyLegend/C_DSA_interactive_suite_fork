#include "bit_manipulation.h"
#include "safe_input.h"
#include <stdio.h>

void rightmost_set_bit_demo(void)
{
    while (1)
    {
        int n;
        int status = safe_input_int(&n,
                                    "\n\nRightmost Set Bit Operations demo"
                                    "\nenter an integer (between -1000 and 1000), "
                                    "enter '-1' to exit:- ",
                                    -1000, 1000);

        if (status == INPUT_EXIT_SIGNAL)
        {
            printf("\nExiting rightmost set bit demo.\n");
            return;
        }
        if (status == 0)
            continue;

        printf("\n\033[1;36m--- Visualizing Rightmost Set Bit Operations ---\033[0m\n");
        unsigned int un = (unsigned int)n;

        unsigned int rsb = get_rightmost_set_bit(n);
        unsigned int turned_off = turn_off_rightmost_set_bit(n);

        printf("  n              = ");
        print_binary_32_highlight(un, rsb, "\033[1;31m");
        printf("  (%d)\n", n);

        printf("  Rightmost Bit  = ");
        print_binary_32_highlight(rsb, rsb, "\033[1;32m");
        printf("  (%u)\n", rsb);

        printf("  n & (n - 1)    = ");
        print_binary_32_highlight(turned_off, 0, NULL);
        printf("  (%u)\n", turned_off);
        printf("--------------------------------------------------\n");
    }
}

void reverse_bits_demo(void)
{
    while (1)
    {
        int n;
        int status = safe_input_int(&n,
                                    "\n\nReverse Bits demo"
                                    "\nenter an unsigned integer (between 0 and 1000), "
                                    "enter '-1' to exit:- ",
                                    0, 1000);

        if (status == INPUT_EXIT_SIGNAL)
        {
            printf("\nExiting reverse bits demo.\n");
            return;
        }
        if (status == 0)
            continue;

        unsigned int un = (unsigned int)n;
        unsigned int result = 0;
        printf("\n\033[1;36m--- Visualizing 32-bit Reversal ---\033[0m\n");
        printf("\033[1;35mInitial n:\033[0m\n");
        print_binary_32(un);
        printf("\n\n\033[1;36mTracing reversal (showing every 8th step):\033[0m\n");

        for (int i = 0; i < 32; i++)
        {
            unsigned int bit = (un >> i) & 1;
            unsigned int highlight_mask_n = 1 << i;
            unsigned int highlight_mask_res = 1 << (31 - i);
            result = result | (bit << (31 - i));

            if (i % 8 == 0 || i == 31)
            {
                printf("\033[1;35mStep %2d: n = \033[0m", i + 1);
                print_binary_32_highlight(un, highlight_mask_n, "\033[1;31m");
                printf("  |  res = ");
                print_binary_32_highlight(result, highlight_mask_res, "\033[1;32m");
                printf("\n");
            }
        }

        printf("\n\033[1;32mFinal Reversed:\033[0m\n");
        print_binary_32(result);
        printf("\nreverse_bits(%d) = %u\n", n, result);
    }
}
