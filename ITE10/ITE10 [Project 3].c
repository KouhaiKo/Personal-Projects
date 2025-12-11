#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert decimal to binary
void decimalToBinary(long long decimal) {
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }

    int isNegative = 0;
    if (decimal < 0) {
        isNegative = 1;
        decimal = -decimal;
    }

    // Convert to binary string
    char binary[65] = "";
    int index = 0;

    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }

    binary[index] = '\0';

    if (isNegative) {
        printf("Binary: -%s\n", binary);
    } else {
        printf("Binary: %s\n", binary);
    }
}

// Function to convert decimal to octal
void decimalToOctal(long long decimal) {
    if (decimal == 0) {
        printf("Octal: 0\n");
        return;
    }

    int isNegative = 0;
    if (decimal < 0) {
        isNegative = 1;
        decimal = -decimal;
    }

    char octal[23] = ""; // Maximum digits for 64-bit number in octal
    int index = 0;

    while (decimal > 0) {
        octal[index++] = (decimal % 8) + '0';
        decimal /= 8;
    }

    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = octal[i];
        octal[i] = octal[index - i - 1];
        octal[index - i - 1] = temp;
    }

    octal[index] = '\0';

    if (isNegative) {
        printf("Octal: -%s\n", octal);
    } else {
        printf("Octal: %s\n", octal);
    }
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(long long decimal) {
    if (decimal == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    int isNegative = 0;
    if (decimal < 0) {
        isNegative = 1;
        decimal = -decimal;
    }

    char hex[17] = "";
    int index = 0;

    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[index++] = remainder + '0';
        } else {
            hex[index++] = remainder - 10 + 'A';
        }
        decimal /= 16;
    }

    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - i - 1];
        hex[index - i - 1] = temp;
    }

    hex[index] = '\0';

    if (isNegative) {
        printf("Hexadecimal: -%s\n", hex);
    } else {
        printf("Hexadecimal: %s\n", hex);
    }
}

// Function to convert binary to decimal
long long binaryToDecimal(const char* binary) {
    long long decimal = 0;
    int length = strlen(binary);

    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal = decimal * 2 + 1;
        } else if (binary[i] == '0') {
            decimal = decimal * 2;
        } else {
            printf("Invalid binary digit: %c\n", binary[i]);
            return 0;
        }
    }

    return decimal;
}

// Function to convert octal to decimal
long long octalToDecimal(const char* octal) {
    long long decimal = 0;
    int length = strlen(octal);

    for (int i = 0; i < length; i++) {
        if (octal[i] >= '0' && octal[i] <= '7') {
            decimal = decimal * 8 + (octal[i] - '0');
        } else {
            printf("Invalid octal digit: %c\n", octal[i]);
            return 0;
        }
    }

    return decimal;
}

// Function to convert hexadecimal to decimal
long long hexadecimalToDecimal(const char* hex) {
    long long decimal = 0;
    int length = strlen(hex);

    for (int i = 0; i < length; i++) {
        char digit = toupper(hex[i]);
        if (digit >= '0' && digit <= '9') {
            decimal = decimal * 16 + (digit - '0');
        } else if (digit >= 'A' && digit <= 'F') {
            decimal = decimal * 16 + (digit - 'A' + 10);
        } else {
            printf("Invalid hexadecimal digit: %c\n", hex[i]);
            return 0;
        }
    }

    return decimal;
}

// Function to check if a string is a valid binary number
int isValidBinary(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a valid octal number
int isValidOctal(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '7') {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a valid decimal number
int isValidDecimal(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            if (i == 0 && str[i] == '-') {
                continue;
            }
            return 0;
        }
    }
    return 1;
}

// Function to check if a string is a valid hexadecimal number
int isValidHexadecimal(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = toupper(str[i]);
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
            return 0;
        }
    }
    return 1;
}

void displayMenu() {
    printf("\n========== BASE CONVERSION CALCULATOR ==========\n");
    printf("1. Convert from Binary\n");
    printf("2. Convert from Octal\n");
    printf("3. Convert from Decimal\n");
    printf("4. Convert from Hexadecimal\n");
    printf("5. Exit\n");
    printf("===============================================\n");
    printf("Enter your choice (1-5): ");
}

// Main function
int main() {
    int choice;
    char input[100];
    long long decimalValue;

    printf("Welcome to the Base Conversion Calculator!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: // Binary conversion
                printf("Enter a binary number: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline

                if (!isValidBinary(input)) {
                    printf("Error: Invalid binary number!\n");
                    break;
                }

                decimalValue = binaryToDecimal(input);
                printf("\nConversion Results:\n");
                printf("Decimal: %lld\n", decimalValue);
                decimalToOctal(decimalValue);
                decimalToHexadecimal(decimalValue);
                break;

            case 2: // Octal conversion
                printf("Enter an octal number: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                if (!isValidOctal(input)) {
                    printf("Error: Invalid octal number!\n");
                    break;
                }

                decimalValue = octalToDecimal(input);
                printf("\nConversion Results:\n");
                printf("Decimal: %lld\n", decimalValue);
                decimalToBinary(decimalValue);
                decimalToHexadecimal(decimalValue);
                break;

            case 3: // Decimal conversion
                printf("Enter a decimal number: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                if (!isValidDecimal(input)) {
                    printf("Error: Invalid decimal number!\n");
                    break;
                }

                decimalValue = atoll(input);
                printf("\nConversion Results:\n");
                decimalToBinary(decimalValue);
                decimalToOctal(decimalValue);
                decimalToHexadecimal(decimalValue);
                break;

            case 4: // Hexadecimal conversion
                printf("Enter a hexadecimal number: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;

                if (!isValidHexadecimal(input)) {
                    printf("Error: Invalid hexadecimal number!\n");
                    break;
                }

                decimalValue = hexadecimalToDecimal(input);
                printf("\nConversion Results:\n");
                printf("Decimal: %lld\n", decimalValue);
                decimalToBinary(decimalValue);
                decimalToOctal(decimalValue);
                break;

            case 5:
                printf("Thank you for using the Base Conversion Calculator!\n");
                return 0;

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
                break;
        }

        printf("\nPress Enter to continue...");
        getchar();
    }

    return 0;
}
