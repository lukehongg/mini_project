#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"
#include "manager.h"

int main(){
        Product p[20];
        int function;
        int count=0;

	FILE *fp = fopen("product.txt","rt");
        if(fp == NULL) printf("\n==> 파일이 없습니다.");
        else {
                fclose(fp);
                count = loadData(p);
        }
#ifdef DEBUG
	printf("==> DEBUGMODE\n");
#endif
	while(1){
                function = selectMenu();
                if(function == 0) break;
                if(function == 1 || function == 3 || function == 4 ||
                function == 6 || function == 7 || function == 8){
                        if(count == 0){
                                printf("==> 데이터가 없습니다.\n");
                                continue;
                        }
                }
                if(function == 1) listProduct(p,count);
                else if(function == 2) count += createProduct(&p[count]);
                else if(function == 3){
                        int n = selectDataNum(p,count);
                        if(n == 0){
                                printf("==> 취소됨\n");
                                continue;
                        }
                        updateProduct(&p[n-1]);
                }
                else if(function == 4){
                        int n = selectDataNum(p, count);
                        if(n == 0){
                                printf("==> 취소됨\n");
                                continue;
                        }
                        int delOK;
                        printf("정말로 삭제하시겠습니까? (삭제:1");
                        scanf("%d",&delOK);
                        if(delOK == 1){
                                deleteProduct(&p[n-1]);
                        }
                }
		else if(function == 5) saveData(p,count);
                else if(function == 6) searchNumStars(p, count);
                else if(function == 7) searchProduct(p, count);
                else if(function == 8) searchPrice(p, count);
        }
        printf("==>종료\n");
        return 0;
}

