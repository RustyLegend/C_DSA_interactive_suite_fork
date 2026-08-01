#include "bit_manipulation.h"
#include "safe_input.h"
#include <stdio.h>

void find_unique_demo(void)
{
    while (1)
    {
        int n;
        int n_status =
            safe_input_int(&n,
                           "\n\nFind Unique Element (XOR) demo"
                           "\nenter the number of elements in the array (between 1 and 20), "
                           "enter '-1' to exit:- ",
                           1, 20);

        if (n_status == INPUT_EXIT_SIGNAL)
        {
            printf("\nExiting find unique demo.\n");
            return;
        }
        if (n_status == 0)
            continue;

        int arr[20];
        int valid = 1;

        for (int i = 0; i < n; i++)
        {
            printf("\nenter element %d (between -1000 and 1000), "
                   "enter '-1' to exit:- ",
                   i + 1);
            int elem_status = safe_input_int(&arr[i], NULL, -1000, 1000);

            if (elem_status == INPUT_EXIT_SIGNAL)
            {
                printf("\nExiting find unique demo.\n");
                return;
            }
            if (elem_status == 0)
            {
                valid = 0;
                break;
            }
        }

        if (!valid)
            continue;

        printf("\n\033[1;36m--- Visualizing Unique Element (XOR) ---\033[0m\n");
        int running_xor = 0;
        for (int i = 0; i < n; i++)
        {
            printf("\033[1;35mStep %d: processing arr[%d] = %d\033[0m\n", i + 1, i, arr[i]);
            printf("  Current XOR = ");
            print_binary_32((unsigned int)running_xor);
            printf("  (%d)\n", running_xor);

            printf("  arr[%d]      = ", i);
            print_binary_32((unsigned int)arr[i]);
            printf("  (%d)\n", arr[i]);

            printf("  ---------------------------------------\n");

            int next_xor = running_xor ^ arr[i];
            unsigned int flipped_bits = (unsigned int)(running_xor ^ next_xor);

            printf("  New XOR     = ");
            print_binary_32_highlight((unsigned int)next_xor, flipped_bits, "\033[1;32m");
            printf("  (%d)\n\n", next_xor);

            running_xor = next_xor;
            printf("Press Enter to continue...\n");
            press_enter_to_continue();
        }

        printf("\033[1;32mFinal Unique Element: %d\033[0m\n", running_xor);
    }
}

void generate_subsets_demo(void)
{
    while (1)
    {
        int n;
        int n_status =
            safe_input_int(&n,
                           "\n\nGenerate Subsets (Bitmasking) demo"
                           "\nenter the number of elements in the set (between 1 and 10), "
                           "enter '-1' to exit:- ",
                           1, 10);

        if (n_status == INPUT_EXIT_SIGNAL)
        {
            printf("\nExiting generate subsets demo.\n");
            return;
        }
        if (n_status == 0)
            continue;

        int arr[10];
        int valid = 1;

        for (int i = 0; i < n; i++)
        {
            printf("\nenter element %d (between -100 and 100), "
                   "enter '-1' to exit:- ",
                   i + 1);
            int elem_status = safe_input_int(&arr[i], NULL, -100, 100);

            if (elem_status == INPUT_EXIT_SIGNAL)
            {
                printf("\nExiting generate subsets demo.\n");
                return;
            }
            if (elem_status == 0)
            {
                valid = 0;
                break;
            }
        }

        if (!valid)
            continue;

        printf("\n\033[1;36m--- Visualizing Subset Generation (Bitmasking) ---\033[0m\n");
        int total_subsets = (1 << n);

        for (int mask = 0; mask < total_subsets; mask++)
        {
            printf("Mask %3d: ", mask);
            print_binary_32_highlight((unsigned int)mask, (unsigned int)mask, "\033[1;33m");
            printf("\033[1;32mSubset:   { \033[0m");
            for (int j = 0; j < n; j++)
            {
                if (mask & (1 << j))
                {
                    printf("\033[1;33m%d \033[0m", arr[j]);
                }
            }
            printf("\033[1;32m}\033[0m\n\n");

            if ((mask + 1) % 8 == 0 && (mask + 1) != total_subsets)
            {
                printf("Press Enter to continue...\n");
                press_enter_to_continue();
            }
        }
        printf("\033[1;32mAll %d subsets generated.\033[0m\n", total_subsets);
    }
}
