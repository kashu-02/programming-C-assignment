#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10 /* 盤面の大きさ */

typedef struct{
	int bomb;      /* 地雷の有無(0 → 無、1 → 有) */
	int bombCount; /* 周辺の地雷の数 */
	int open;      /* 開いているかどうか(0 → 閉、1 → 開) */
	int flag;      /* 旗の有無(0 → 無、1 → 有) */
}Status;

typedef struct{
	Status status[N][N]; /* 盤面 */
	int flagCount;       /* 全ての配置した旗の数 */
	int correctCount;    /* 正しい配置をした旗の数 */
	int bombs;           /* 設置する地雷の数 */
}Map;

void Initialize(Map*);
int Judge(Map*);
void View(Map);
void Open(Map*);

int main(){
	
	Map map;
	
	/* マップデータの初期化 */
	Initialize(&map);
	
	/* ゲームループ */
	while(1){
		/* 配置した旗の数と設置してある地雷の数を表示 */
		printf("\nFlag/Bomb:%d/%d\n", map.flagCount, map.bombs);
		View(map);
		if(Judge(&map) == 1)
			break;
	}
	
	Open(&map);
	View(map);
	
	return 0;
}

/*
 * マップデータの初期化を行う関数
 * 引数   : Map*
 * 戻り値 : なし
 */
void Initialize(Map *map){
	/* 変数宣言 */
	int i, j, x, y, tmp;
	
	/* 乱数による地雷数の設定 */
	srand((unsigned int)time(NULL));
	map->bombs = rand() % 10 + 5;
	
	map->flagCount = 0;
	map->correctCount = 0;
	
	/* 盤面(Status[N][N])内の要素の初期化 */
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			map->status[i][j].bomb = 0;
			map->status[i][j].open = 0;
			map->status[i][j].flag = 0;
		}
	}
	
	tmp = 0;
	while(1){
		/* 地雷を配置する位置を乱数で設定 */
		x = rand() % N;
		y = rand() % N;
		
		/* 配置箇所が被ってないかを確認 */
		if(map->status[x][y].bomb == 0){
			map->status[x][y].bomb = 1;
			tmp++;
		}
		if(tmp == map->bombs)
			break;
	}
	
	/* 周辺の地雷の数を検索 */
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			tmp = 0;
			for(x = -1; x < 2; x++){
				for(y = -1; y < 2; y++){
					if((i + x >= 0 && i + x < N) && (j + y >= 0 && j + y < N))
						tmp += map->status[i + x][j + y].bomb;
				}
			}
			map->status[i][j].bombCount = tmp;
		}
	}
}

/*
 * 座標を入力し、判定を行う関数
 * 引数   : Map*
 * 戻り値 : int(判定の結果: 0 → 続行, 1 → 終了)
 */
int Judge(Map *map){
	/* 変数宣言 */
	int i, x, y;
	
	/* 入力を行う
	 * 変数iに何をするか，xにX座標，yにY座標をそれぞれ入力
	 */
	printf("Input: i(0=open/1=flag) x y \nInput: ");

	scanf("%d", &i);
	if(i == EOF){
		return 1;
	
	scanf("%d %d", &x, &y);
	
	if(0 <= x && x < N && 0 <= y && y < N){
		/* 盤面を開くとき */
		if(i == 0){
			/* 指定された座標に旗が立っていなければ開く */
			if(map->status[x][y].flag == 0){
				map->status[x][y].open = 1;
				
				/* 開いた箇所に地雷があれば終了 */
				if(map->status[x][y].bomb == 1){
					printf("\nBOMB!!\n");
					return 1;
				}
			}
		}
		/* 旗を設置するとき */
		else if(i == 1){
			/* 指定された座標が開いてなければ旗の状態を変更 */
			if(map->status[x][y].open == 0){
				map->status[y][x].flag = !map->status[y][x].flag;
				/* 
				 * 旗を置いたとき旗の総数を増やし、削除したときは減らす。
				 * また、正しく旗が置かれているかも判定し、カウントする。
				 */
				if(map->status[y][x].flag == 1){
					map->flagCount++;
					if(map->status[y][x].bomb == 1){ //地雷上の時
						map->correctCount++;
          }
				}
				else{
					map->flagCount--;
					if(map->status[y][x].bomb == 1){ //地雷上の時
						map->correctCount--;
          }
					}
				}
			}
		}
	}
	
	/* クリア判定 */
	if(map->flagCount == map->bombs && map->correctCount == map->bombs){
		printf("\n--CLEAR--\n");
		return 1;
	}
	
	return 0;
}

/*
 * 盤面をコンソール上に表示する関数
 * 引数   : Map
 * 戻り値 : なし
 */
void View(Map map){
	/* 変数宣言 */
	int i, j;
	
	printf("\n");
	printf("\\ ");
	for(i = 0; i < N; i++){
		printf("%d", i);
	}
	
	printf("\n \\==========\n");
	for(i = 0; i < N; i++){
		printf("%d|",i);
		for(j = 0; j < N; j++){
			/* 開いていない時 */
			if(map.status[i][j].open == 0){
				if(map.status[i][j].flag == 1){
					printf("F");
				}
				else{
					printf("-");
				}
			}
			/* 開いている時 */
			else{
				if(map.status[i][j].bomb == 1){
					printf("x");
				}
				else{
					printf("%d", map.status[i][j].bombCount);
				}
			}
		}
		printf("|\n");
	}
	printf("  ==========\n\n");
	
}

/*
 * 盤面の地雷が配置してある箇所をすべて開く関数
 * 引数   : Map*
 * 戻り値 : なし
 */
void Open(Map *map){
	/* 変数宣言 */
	int i, j;
	
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(map->status[i][j].bomb == 1){
				map->status[i][j].open = 1;
			}
		}
	}
}

