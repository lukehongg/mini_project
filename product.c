#include "product.h"

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
int selectDataNum(Product *p, int count){
	int n;
	listProduct(p, count);
	printf("번호는?(취소:0)");
	scanf("%d",&n);
	return n;
}
// Program내 기능을 선택하는 함수
int selectMenu(){
	int menu;
	printf("\n*** Fruits ***\n");
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
// 등록된 제품정보를 수정하는 함수
int deleteProduct(Product *p){
	p->price=-1;
	printf("==>삭제됨\n");
	return 1;
};
// 등록된 제품을 삭제하는 함수
void saveData(Product *p,int count){
	FILE *fp;
	fp = fopen("product.txt","wt");

	for(int i=0; i<count; i++){
		if(p[i].price == -1) continue;
		fprintf(fp,"%d %d %d %s\n",p[i].price,p[i].stars,p[i].snum, p[i].name);
	}
	fclose(fp);
	printf("==> 저장됨\n");
};
// File에 등록된 제품 리스트를 저장하는 함수
int loadData(Product *p){
	int count =0, i=0;
	FILE *fp = fopen("product.txt","rt");
	for(; i<20; i++){
		fscanf(fp,"%d", &p[i].price);
		fscanf(fp,"%d", &p[i].stars);
		fscanf(fp,"%d", &p[i].snum);
		fscanf(fp," %[^\n]s",p[i].name);	
		if(feof(fp)) break;
	}
	fclose(fp);
	printf("==> 로딩성공!\n");
	return i;	
};
//File에서 저장된 제품 리스트를 program내에 있는 리스트에 불러오는 함수
//검색
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
// 별점개수를 이용하여 제품(들)을 검색하는 함수 (별점 3점 이상)
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
// 제품무게를 이용하여 제품(들)을 검색하는 함수 (1kg 이상)
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
// 제품가격을 이용하여 제품(들)을 검색하는 함수 (10000원 이상)
