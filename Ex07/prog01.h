/* 個人レコード */
typedef struct {
    char familyname[20]; /* 苗字 */
    char firstname[20];  /* 名前 */
    int birthday[3];     /* 誕生日（要素0: 西暦, 要素1: 月, 要素2:日） */
}Record;