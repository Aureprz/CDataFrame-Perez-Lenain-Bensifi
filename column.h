#ifndef CDATAFRAME_PEREZ_LENAIN_BENSIFI_COLUMN_H
#define CDATAFRAME_PEREZ_LENAIN_BENSIFI_COLUMN_H

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

typedef union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
}COL_TYPE;

typedef struct COLUMN{
    char* title;
    unsigned int size;
    unsigned int max_size;
    ENUM_TYPE column_type;
    COL_TYPE **data;
    unsigned long long int *index;
    // index valid
    // 0 : no index
    //-1 : invalid index
    // 1 : valid index
    int valid_index;
    // direction de tri : Ascendant ou Descendant
    // 0 : ASC
    // 1 : DESC
    int sort_dir;
}COLUMN;


/**
* @brief: Initialize the column
* @param1: Type of the column
* @param2: Title of the column as a string
* @return: Pointer to the column
*/
COLUMN *create_column(ENUM_TYPE type, char *title);


/**
* @brief: Insert a new value into a column
* @param1: Pointer to the column
* @param2: Pointer to the value to insert
* @return: 1 if the value is correctly inserted 0 otherwise
*/
int insert_value(COLUMN *col, void *value);

/**
 * @brief: Delete a value in the column
 * @param1: Column
 * @param2: Position of the value the user wants to get rid of within the data column
 */
void delete_value_column(COLUMN *col, int location);


/**
* @brief: Free the space allocated by a column
* @param: Pointer to the column
*/
void delete_column(COLUMN **col);


/**
 * @brief: Convert a value into a string
 * @param1: Pointer to the column
 * @param2: Position of the value in the data array
 * @param3: The string in which the value will be written
 * @param4: Maximum size of the string
 */
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);


/**
 * @brief: Display the content of a column
 * @param: Pointer to the column to display
 */
void print_col(COLUMN* col);

/**
 * @brief:  Looks for a value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: 1 if the value exists, 0 otherwise
 */
int exist_col(COLUMN* col, char *value);

/**
 * @brief:  Shows the numbers of cells match with the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: number of cells equals to the value
 */
int cellsequal_col(COLUMN* col, char *value);

/**
 * @brief:  Shows the numbers of cells superior than the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: number of cells superior to the value
 */
int cellssup_col(COLUMN* col, char *value);

/**
 * @brief:  Shows the numbers of cells inferior than the value in the CDataFrame
 * @param1: Pointer to the CDataFrame
 * @param2: value wanted
 * @param3: value type
 * @return: number of cells inferior to the value
 */
int cellsinf_col(COLUMN* col, char *value);


/**
* @brief: Display the content of a sorted column
* @param: Pointer to a column
*/
void print_col_by_index(COLUMN *col);

/**
 * @brief: Create a column by inputs from the user
 * @return: Pointer to the said column
 */
COLUMN *create_col_user();

/**
 * @brief: Print values in a column
 * @param1: Column
 * @param2: Index
 */
void print_val_in_col(COLUMN* col , unsigned long long int index);

/**
 * @brief: Insert a new value into a column
 * @param: Column
 * @return: 1 if the value was insert inside the column, 0 otherwise
 */
int insert_user_val(COLUMN *col);

#endif //CDATAFRAME_PEREZ_LENAIN_BENSIFI_COLUMN_H
