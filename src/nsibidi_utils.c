#include <stdlib.h>
#include <string.h>
#include "nsibidi_utils.h"

char* digit_to_nsibidi(int digit) {
    char* symbols[] = {
        "人", "禾", "火", "衛", "子", "男", "女", "境", "接", "鋭"
    };
    
    if (digit < 0 || digit > 9) {
        char* result = malloc(4);
        strcpy(result, "？");
        return result;
    }
    
    char* result = malloc(strlen(symbols[digit]) + 1);
    strcpy(result, symbols[digit]);
    return result;
}
