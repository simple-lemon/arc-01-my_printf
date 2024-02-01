#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    for (int current_char = ' '; current_char <= 'z'; current_char++) {
        char current_char_as_char = (char)current_char;
        int count = 0;

        for (int arg_index = 1; arg_index < argc; arg_index++) {
            for (int char_index = 0; char_index < strlen(argv[arg_index]); char_index++) {
            
                if (argv[arg_index][char_index] == current_char_as_char) {
                    count++;
                }
            }
        }
        if (count > 0) {
            printf("%c:%d\n", current_char_as_char, count);
        }
    }

    return 0;
}