/**
 * @author George Papamichail
 */
#ifndef esp_now_HR_utils_h
#define esp_now_HR_utils_h

#include <cstddef>
#include <Arduino.h>

#include "esp_now_HR_enums.h"

/**
 * @brief   Create a struct that contains the data of the message
 */
typedef struct {
    char type;                      ///< Type of the message (character).
    char msg_char[STRING_LENGTH];   ///< Array to hold character message.
    int msg_int;                    ///< Integer message.
    float msg_float;                ///< Float message.
    bool msg_bool;                  ///< Boolean message.
} data;


typedef union{
    int i;      ///< Integer type.
    short s;    ///< Short type.
    long l;     ///< Long type.
    float f;    ///< Float type.    
    double d;   ///< Double type.    
    char c;     ///< Character type.
    bool b;     ///< Boolean type.
    data dt;    ///< Data structure.    

    int* i_ptr;     ///< Pointer to an integer type.
    short* s_ptr;   ///< Pointer to a short type.    
    long* l_ptr;    ///< Pointer to a long type.    
    float* f_ptr;   ///< Pointer to a float type.        
    double* d_ptr;  ///< Pointer to a double type.        
    char* c_ptr;    ///< Pointer to a character type.    
    bool* b_ptr;    ///< Pointer to a boolean type.    
    data* dt_ptr;   ///< Pointer to a data structure.        
} msg_union;


// Specialization for arrays
/**
 * @brief   Specialization for arrays
 */
typedef struct{
    MSG_VARIABLE_TYPE type; ///< Type of the message variable.                      
    bool array;             ///< Flag indicating if the message is an array.    
    size_t size;            ///< Size of the message (number of elements).        
    msg_union msg;          ///< Union to hold different message types.        
} msg_struct;

/**
 * @brief Function to set data parameters in the data structure.
 * @param new_struct Pointer to the data structure to be modified.
 * @param type The type of message to set.
 * @param new_char Character array to set in the message.
 * @param new_int Integer value to set in the message.
 * @param new_float Float value to set in the message.
 * @param new_bool Boolean value to set in the message.
 */
void Set_Data_parameters(data *new_struct, char type, char new_char[], int new_int, float new_float, bool new_bool);

/**
 * @brief Function to convert MAC address to a string.
 * @param mac Pointer to the MAC address.
 * @return String representation of the MAC address.
 */
String getMACtoSTRING(uint8_t *mac);

/**
 * @brief Function to convert string to MAC address.
 * @param text String representation of the MAC address.
 * @param new_mac Pointer to store the converted MAC address.
 */
void getSTRINGtoMAC(String text, uint8_t *new_mac);

#endif