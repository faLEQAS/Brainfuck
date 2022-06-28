#include <stdio.h>
#include <string.h>


typedef unsigned char byte;

const int mem_size = 30000;

byte memory[mem_size] = {};

const char* code = "++>+++++[<+>-]++++++++[<++++++>-]<.";

byte* data_ptr = memory;
char* instruction_ptr = (char*)code;
char* prev_bracket = nullptr;


int main(void)
{
    for (int i = 0; i < strlen(code); i++)
    {
        char instruction = *instruction_ptr;
        
        switch (instruction)
        {
            case '>':
            {
                data_ptr++;
            } break;
            
            case '<':
            {
                data_ptr--;
            } break;
            
            case '+':
            {
                *data_ptr += 1;
            } break;
            
            case '-':
            {
                *data_ptr -= 1;
            } break;
            
            case '.':
            {
                printf("%d\n", (byte)(*data_ptr));
            } break;
            
            case ',':
            {
                *data_ptr = getchar();
            } break;
            
            case '[':
            {
                if ((*data_ptr) == 0)
                {
                    for (int j = i; j < strlen(code); j++)
                    {
                        if (code[j] == ']')
                        {
                            instruction_ptr = (char*)code + j;
                        }
                    }
                }
            } break;
            
            case ']':
            {
                if ((*data_ptr) != 0)
                {
                    for (int j = i; j >= 0; j--)
                    {
                        if (code[j] == '[')
                        {
                            instruction_ptr = (char*)code + j;
                        }
                    }
                }
            } break;
        }
        
        instruction_ptr++;
    }
    return 0;
}