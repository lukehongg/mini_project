#include <stdio.h>
#include <string.h>
#include "product.h"

int createProduct(Product *p){
	printf("과일 이름은? ");
	scanf(" %[^\n]s",p->name);
	printf("가격은? ");
	scanf("%d",&p->price);
	printf("평점은?");
	scanf("%d",&p->stars);
	printf("총 평가수는?");
	scanf("%d",&p->snum);
	printf("==>추가성공!");
	return 1;
};
//하나의 제춤을 추가하는 함수
void readProduct(Product p){
	printf("%s\n%d원\n", p.name,p.price);
	for(int i=0; i<p.stars;i++) printf("@");
	printf("(%d개)", p.snum);
	printf("\n");
};
void updateProduct(Product *p){
	
	printf("새로운 과일 이름은? ");
	scanf(" %[^\n]s",p->name);
	printf("새로운 가격은? ");
	scanf("%d",&p->price);
	printf("새로운 평점은?");
	scanf("%d",&p->stars);
	printf("새로운 총 평가수는?");
	scanf("%d",&p->snum);
	printf("==>수정성공!");

};
int deleteProduct(Product *p){
	p->price=-1;
	printf("==>삭제됨\n");
	return 1;
};
