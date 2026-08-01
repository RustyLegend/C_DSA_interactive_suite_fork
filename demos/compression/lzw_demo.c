#include "../utils/config.h"
#include "clear_screen.h"
#include "compression.h"
#include "cross_platform_timer.h"
#include "safe_input.h"

#include <stdio.h>
#include <string.h>

void lzw_demo(void)
{
    char input[256];
    char decoded[256];
    int encoded[512];

    while (1)
    {
        if (!is_instant())
            clear_screen();

        printf("\n\033[1;36m=== LZW COMPRESSION DEMO ===\033[0m\n");
        printf("Demonstrates LZW Encoding and Decoding.\n\n");

        printf("1. Compress String\n");
        printf("2. Decompress Last Result\n");
        printf("3. Reset\n");
        printf("Enter option (-1 to exit): ");

        static int encoded_len = 0;
        static int has_encoded = 0;

        int choice;
        int status = safe_input_int(&choice, "", 1, 3);

        if (status == INPUT_EXIT_SIGNAL || choice == -1)
            break;

        if (status != 1)
            continue;

        switch (choice)
        {
            case 1:
            {
                printf("\nEnter input string: ");

                if (fgets(input, sizeof(input), stdin) == NULL)
                    break;

                input[strcspn(input, "\n")] = '\0';

                encoded_len = lzw_encode(input, encoded, 512);

                if (encoded_len < 0)
                {
                    printf("\nEncoding Failed!\n");
                    sleep_seconds(1.5f);
                    break;
                }

                has_encoded = 1;

                printf("\nOriginal : %s\n", input);
                printf("Encoded  : ");

                for (int i = 0; i < encoded_len; i++)
                    printf("%d ", encoded[i]);

                printf("\n");

                sleep_seconds(2.0f);
                break;
            }

            case 2:
            {
                if (!has_encoded)
                {
                    printf("\nNo compressed data available!\n");
                    sleep_seconds(1.5f);
                    break;
                }

                if (lzw_decode(encoded, encoded_len, decoded, sizeof(decoded)) < 0)
                {
                    printf("\nDecoding Failed!\n");
                    sleep_seconds(1.5f);
                    break;
                }

                printf("\nDecoded String : %s\n", decoded);

                sleep_seconds(2.0f);
                break;
            }

            case 3:
            {
                encoded_len = 0;
                has_encoded = 0;
                input[0] = '\0';
                decoded[0] = '\0';

                printf("\nDemo Reset Successfully!\n");
                sleep_seconds(1.0f);
                break;
            }
        }
    }
}