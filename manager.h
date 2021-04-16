#include "product.h"

int selectDataNum(Product *p, int count);
int selectMenu(); // Program내 기능을 선택하는 함수
void listProduct(Product *p, int count); // 모든 제품 리스트를 출력하는 함수
void searchNumStars(Product *p, int count);
void searchProduct(Product *p, int count);
void searchPrice(Product *p, int count);
void saveData(Product *p, int count);
int loadData(Product *p);
