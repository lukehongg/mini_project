#include <stdio.h>
#include <string.h>
#include "manager.h"
int selectDataNum(Product *p, int count){
        int n;
        listProduct(p, count);
        printf("번호는?(취소:0)");
        scanf("%d",&n);
        return n;
}
// program내 기능을 선택하는 함수
int selectMenu(){
        int menu;
        printf("\n*** fruits ***\n");
        printf("1. 제품조회\n");
        printf("2. 제품추가\n");
        printf("3. 제품수정\n");
        printf("4. 제품삭제\n");
        printf("5. 파일저장\n");
        printf("6. 제품찾기(별점)\n");
        printf("7. 제품찾기(제품명)\n");
        printf("8. 제품찾기(가격)\n");
        printf("0. 종료\n");
        printf("==> 원하는 메뉴는? ");
        scanf("%d", &menu);
        return menu;
};
// 하나의 제품을 출력하는 함수
void listProduct(Product *p, int count){
        printf("\n*********************\n");
        for(int i=0; i<count; i++){
                if(p[i].price == -1) continue;
                printf("%1d. ", i+1);
                readProduct(p[i]);
        }
        printf("\n");
};
// 모든 제품 리스트를 출력하는 함수
// 등록된 제품정보를 수정하는 함수
void searchNumStars(Product *p, int count){
        int scnt =0;
        int star_count;
        printf("검색할 별의 수?(입력한 별의 수 이상의 제품조회) ");
        scanf("%d", &star_count);
        printf("\n*********************\n");
        for(int i=0; i<count; i++){
                if(p[i].price == -1) continue;
                if(p[i].stars >= star_count){
                        printf("%1d",i+1);
                        readProduct(p[i]);
                        scnt++;
                }
        }
        if(scnt==0) printf("==>검색된 제품 없음\n");
};
void searchProduct(Product *p, int count){
        int scnt =0;
        char name[40];
        printf("검색할 제품은?(입력한 제품조회) ");
        scanf(" %[^\n]s", name);
        printf("\n*********************\n");
        for(int i=0; i<count; i++){
                if(p[i].price == -1) continue;
                if(strstr(p[i].name, name)){
                        printf("%1d",i+1);
                        readProduct(p[i]);
                        scnt++;
                }
        }
        if(scnt==0) printf("==>검색된 제품 없음\n");
};
void searchPrice(Product *p, int count){

        int scnt =0;
        int price;
        printf("검색할 가격은?(입력한 가격 이하의 제품조회) ");
        scanf("%d", &price);
        printf("\n*********************\n");
        for(int i=0; i<count; i++){
                if(p[i].price == -1) continue;
                if(p[i].price <= price){
                        printf("%1d",i+1);
                        readProduct(p[i]);
                        scnt++;
                }
        }
        if(scnt==0) printf("==>검색된 제품 없음\n");
};
void saveData(Product *p,int count){
        file *fp;
        fp = fopen("product.txt","wt");

        for(int i=0; i<count; i++){
                if(p[i].price == -1) continue;
                fprintf(fp,"%d %d %d %s\n",p[i].price,p[i].stars,p[i].snum, p[i].name);
        }
        fclose(fp);
        printf("==> 저장됨\n");
};
int loadData(Product *p){
        int i=0;
        file *fp = fopen("product.txt","rt");
        for(; i<20; i++){
                fscanf(fp,"%d", &p[i].price);
                fscanf(fp,"%d", &p[i].stars);
                fscanf(fp,"%d", &p[i].snum);
                fscanf(fp," %[^\n]s",p[i].name);
                if(feof(fp)) break;
        }
        fclose(fp);
        if(i>0) printf("==> 로딩성공!\n");
        else printf("==>로딩실패!\n");
        return i;
};
