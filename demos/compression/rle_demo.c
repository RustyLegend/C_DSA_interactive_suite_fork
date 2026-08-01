#include "../utils/config.h"
#include "clear_screen.h"
#include "compression.h"
#include "cross_platform_timer.h"
#include "safe_input.h"

#include <stdio.h>
#include <string.h>

void rle_demo(void)
{
    char input[256];
    char encoded[512];
    char decoded[256];

    while (1)
    {
        if (!is_instant())
            clear_screen();

        printf("\n\033[1;36m=== RUN-LENGTH ENCODING (RLE) DEMO ===\033[0m\n");
        printf("Demonstrates Run-Length Encoding and Decoding.\n\n");

        printf("1. Encode String\n");
        printf("2. Decode Last Result\n");
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

                encoded_len = rle_encode(input, encoded, strlen(input), sizeof(encoded));

                if (encoded_len < 0)
                {
                    printf("\nEncoding Failed!\n");
                    sleep_seconds(1.5f);
                    break;
                }

                has_encoded = 1;

                printf("\nOriginal : %s\n", input);
                printf("Encoded  : %s\n", encoded);

                sleep_seconds(2.0f);
                break;
            }

            case 2:
            {
                if (!has_encoded)
                {
                    printf("\nNo encoded data available!\n");
                    sleep_seconds(1.5f);
                    break;
                }

                if (rle_decode(encoded, encoded_len, decoded, sizeof(decoded)) < 0)
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
                input[0] = '\0';
                encoded[0] = '\0';
                decoded[0] = '\0';
                encoded_len = 0;
                has_encoded = 0;

                printf("\nDemo Reset Successfully!\n");
                sleep_seconds(1.0f);
                break;
            }
        }
    }
}