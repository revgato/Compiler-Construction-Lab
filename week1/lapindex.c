#include <stdio.h>
#include <string.h>
#define max_len 100
#define max_num 1000
int word_to_int(char **words, char *word);
void word_normalize(char *word);
int main()
{
    FILE *ptr, *ptr_stop;
    char word_prev[max_len];
    char word[max_len];
    char words[max_num][max_len];
    char words_stop[max_num][max_len];
    char c;
    int words_count[max_num] = {0};
    int words_index[max_num][max_len] = {0};
    int i, j;
    int count = 0, count_stop = 0, row = 1;
    ptr = fopen("vanban.txt", "r");
    if (ptr == NULL)
    {
        printf("Cannot open file vanban.txt!\n");
        return 1;
    }
    ptr_stop = fopen("stopw.txt", "r");
    if (ptr_stop == NULL)
    {
        printf("Cannot open file stopw.txt!\n");
        return 1;
    }
    //Doc file stopw.txt va luu ds tu vao mang words_stop
    while (fscanf(ptr_stop, "%s", word) == 1)
    {
        strcpy(words_stop[count_stop++], word);
    }
    //
    //Thiết lập word_prev
    fscanf(ptr, "%s", word_prev);
    fseek(ptr, 0, SEEK_SET);
    //
    while (fscanf(ptr, "%s", word) == 1)
    {
        word_normalize(word);
        //Check words_stop
        j = 0;
        for (i = 0; i < count_stop; i++)
        {
            if (strcmp(words_stop[i], word) == 0)
            {
                j = 1;
                break;
            }
        }
        if (j == 1)
        {
            fscanf(ptr, "%c", &c); //Check đang ở dòng mấy
            if (c == '\n')
            { //Neu c == '\n' thì tăng biến đếm dòng lên 1
                row++;
            }
            continue;
        }
//Check tên riêng

//
        i = -1;
        //Check trong words da co word hay chua
        for (j = 0; j < max_num; j++)
        {
            if (strcmp(words[j], word) == 0)
            {
                i = j;
                break;
            }
        }
        if (i == -1) //Neu chua co thi i = -1
        {
            words_count[count]++;
            strcpy(words[count], word);
            words_index[count][0] = row;
            count++;
        }
        else
        {
            words_count[i]++; //Neu da co thi words_count++
            for (j = 0; j < max_len; j++)
            {
                if (words_index[i][j] == 0) //Mảng word_index ban đầu toàn là số 0. => số khác 0 đầu tiên chính là index đã được ghi trước đó
                {
                    if (words_index[i][j - 1] == row) //Nếu 1 word xuất hiện nhiều hơn 1 lần trên cùng 1 dòng thì
                    {                                 //không lưu index của những lần xuất hiện sau.
                        break;
                    }
                    words_index[i][j] = row;
                    break;
                }
            }
        }
        fscanf(ptr, "%c", &c); //Check đang ở dòng mấy
        if (c == '\n')
        { //Neu c == '\n' thì tăng biến đếm dòng lên 1
            row++;
        }
    }
    for (i = 0; i < count; i++)
    {
        printf("%s %d", words[i], words_count[i]);
        j = 0;
        while (words_index[i][j] != 0)
        {
            printf(",%d", words_index[i][j++]);
        }
        printf("\n");
    }
    fclose(ptr);
    fclose(ptr_stop);
    return 0;
}
void word_normalize(char *word) //Chuyển đổi chữ hoa thành chữ thường, xoá kí tự lạ
{
    int i, j;
    for (i = 0; i < strlen(word); i++)
    {
        if (!((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')))
        {
            for (j = i; j < strlen(word); j++)
            {
                word[j] = word[j + 1];
            }
            i--;
            continue;
        }
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            word[i] -= ('A' - 'a');
        }
    }
}
void isName(char* word, char* word_prev){
    char c = word[0]
}
