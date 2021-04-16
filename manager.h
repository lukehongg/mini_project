#include <stdio.h>
#include <string.h>

typedef struct{
    char name[40];
    int price;
    int stars;
    int snum;
} Product;
int selectDataNum(Product *p, int count);
int selectMenu(); // Program내 기능을 선택하는 함수
int createProduct(Product *p);  //하나의 제춤을 추가하는 함수
void readProduct(Product p); // 하나의 제품을 출력하는 함수
void listProduct(Product *p, int count); // 모든 제품 리스트를 출력하는 함수
void updateProduct(Product *p); // 등록된 제품정보를 수정하는 함수
int deleteProduct(Product *p); // 등록된 제품을 삭제하는 함수
void searchNumStars(Product *p, int count);
