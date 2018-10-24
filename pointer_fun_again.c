/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 5
 * Title:						Pointer Fun Again
 * Author:					Jan Fischlmayr
 * ----------------------------------------------------------
 * Description:
 * An Exercise about values and pointers in C
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

struct PlayStruct {
  int int_value;
  double double_value;
  char a_string[64];
};

void print_struct(struct PlayStruct ps, struct PlayStruct* pps);
void change_struct(struct PlayStruct ps, struct PlayStruct* pps);
void print_string(char string_to_print[]);
void change_string(char string1[], char* p_string);

int main(int argc, char const *argv[])
{
    struct PlayStruct play_struct = {23, 18.24, "Fischlmayr"};
    struct PlayStruct play_struct_pointer_value = {12, 265.43, "Hello World"};
    struct PlayStruct* play_struct_pointer = &play_struct_pointer_value;
    /*
        I created an extra struct, because if i linked the pointer struct to the first struct,
        it would always change the value of the play_struct.
    */

    print_struct(play_struct, play_struct_pointer);

    change_struct(play_struct, play_struct_pointer);
    print_struct(play_struct, play_struct_pointer);
    /*
        Only the struct which the pointer was pointing at changed,
        because the values you give a method only get coppied and
        normaly wont change, except it is a pointer. The pointer is only an address
        and not a value, so it will overwrite the value at the given address.
        The value of an normal variable wont change, because it is local.
    */

    print_string(play_struct.a_string);
    char another_string[16] = "Hallo";
    change_string(play_struct.a_string, another_string);
    print_string(play_struct.a_string);
    print_string(another_string);
    /*
        The value of the struct didn't change, because it was only copied.
        The array on the otherside is only a pointer to the first value of the array.
    */
    return 0;
}

void print_struct(struct PlayStruct ps, struct PlayStruct* pps)
{
    printf("Values of struct ps: %d, %lf, %s\n", ps.int_value, ps.double_value, ps.a_string);
    printf("Values of struct pps: %d, %lf, %s\n", pps->int_value, pps->double_value, pps->a_string);
}

void change_struct(struct PlayStruct ps, struct PlayStruct* pps)
{
    ps.int_value = 34;
    ps.double_value = 123.4;
    strcpy(ps.a_string, "Jan");

    pps->int_value = 74;
    pps->double_value = 789.70;
    strcpy(pps->a_string, "Knabel");
}

void print_string(char string_to_print[])
{
    printf("%s\n", string_to_print);
}

void change_string(char string1[], char* p_string)
{
    string1[2]  = '\0';
    p_string[1] = '\0';
}
