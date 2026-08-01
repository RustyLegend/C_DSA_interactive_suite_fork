#include "bit_manipulation.h"
#include "safe_input.h"
#include <stdio.h>

void bitwise_visualizer_demo(void)
{
    while (1)
    {
        int a;
        int a_status = safe_input_int(&a,
                                      "\n\nBitwise Multi-Number Visualizer"
                                      "\nenter first integer A (between -1000 and 1000), "
                                      "enter '-1' to exit:- ",
                                      -1000, 1000);

        if (a_status == INPUT_EXIT_SIGNAL)
        {
            printf("\nExiting bitwise visualizer demo.\n");
            return;
        }
        if (a_status == 0)
            continue;

        int b;
        int b_status = safe_input_int(&b,
                                      "\nenter second integer B (between -1000 and 1000), "
                                      "enter '-1' to exit:- ",
                                      -1000, 1000);

        if (b_status == INPUT_EXIT_SIGNAL)
        {
            printf("\nExiting bitwise visualizer demo.\n");
            return;
        }
        if (b_status == 0)
            continue;

        unsigned int ua = (unsigned int)a;
        unsigned int ub = (unsigned int)b;

        printf("\n");
        printf("  A = ");
        print_binary_32(ua);
        printf("  (%d)\n", a);

        printf("  B = ");
        print_binary_32(ub);
        printf("  (%d)\n", b);

        printf("  ");
        for (int i = 0; i < 43; i++)
        {
            printf("-");
        }
        printf("\n");

        printf("\033[1;32mA&B = \033[0m");
        print_binary_32(ua & ub);
        printf("  (%d)\n", a & b);

        printf("\033[1;33mA|B = \033[0m");
        print_binary_32(ua | ub);
        printf("  (%d)\n", a | b);

        printf("\033[1;35mA^B = \033[0m");
        print_binary_32(ua ^ ub);
        printf("  (%d)\n", a ^ b);

        printf("\n");
    }
}
