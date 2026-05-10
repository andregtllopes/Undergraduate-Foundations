#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <math.h>

#define STARS 1000
#define L_ALIENS1 5
#define C_ALIENS1 6
#define L_ALIENS2 6
#define C_ALIENS2 6
#define L_ALIENS3 6
#define C_ALIENS3 7

const float FPS = 100;  

const int DISTNAVES_X = 50;
const int DISTNAVES_Y = 30;

const int SCREEN_X = 960;
const int SCREEN_Y = 550;

const int GRASS_Y = 65;
const int GROUND_Y = 55;

const int SIZEC_X = 50;
const int SIZEC_Y = 50;

const int SIZEA_X = 50;
const int SIZEA_Y = 25;


// LÊ O RECORDE ATUAL DO ARQUIVO "record.txt"
int ler_recorde() {
    FILE *arq = fopen("record.txt", "r"); 
    int recorde_lido = 0;

    // Se o arquivo não existir ou não puder ser aberto, arq será NULL.
    // Nesse caso, o recorde inicial é 0.
    if (arq == NULL) {
        printf("Arquivo de recorde não encontrado. Começando com 0.\n");
        return 0;
    }

    // Lê o número do arquivo e armazena na variável
    fscanf(arq, "%d", &recorde_lido);

    // Fecha o arquivo após a leitura
    fclose(arq);

    printf("Recorde atual lido do arquivo: %d\n", recorde_lido);
    return recorde_lido;
}


// SALVA O VALOR FINAL DO RECORDE NO ARQUIVO
void salvar_recorde(int recorde_final) {
    FILE *arq = fopen("record.txt", "w"); // "w" = write (escrever/sobrescrever)

    // Se houver um erro ao abrir para escrita, apenas informa e sai.
    if (arq == NULL) {
        fprintf(stderr, "Erro ao tentar salvar o recorde!\n");
        return;
    }

    // Escreve o valor do recorde no arquivo
    fprintf(arq, "%d", recorde_final);

    // Fecha o arquivo para garantir que a escrita foi concluída
    fclose(arq);
    printf("\nRecorde de %d salvo com sucesso!\n", recorde_final);
}

//DESENHAR MENU
void draw_menu(float A[], float B[],ALLEGRO_FONT *fonte_botoes){
	
	al_clear_to_color(al_map_rgb(17,17,76));
	int i;
	for (i=0;i<STARS;i++){
		al_draw_filled_rectangle(A[i],B[i], 
						A[i]+3, B[i]+3,
   						al_map_rgb(255,255,255));
		B[i] = B[i] + 0.05;
		A[i] = A[i] + 0.05;
	}

	al_draw_filled_rectangle(0, SCREEN_Y-GRASS_Y, 
							SCREEN_X, SCREEN_Y-GROUND_Y,
   							al_map_rgb(0, 155, 0));
	al_draw_filled_rectangle(0, SCREEN_Y-GROUND_Y, 
							SCREEN_X, SCREEN_Y,
   							al_map_rgb(135,62,35));	

							
	al_draw_filled_rounded_rectangle(SCREEN_X/2-350, SCREEN_Y/2-170, 
							SCREEN_X/2+350, SCREEN_Y/2+170,
							30,30,
   							al_map_rgb(12, 12, 52));	
							
							
	al_draw_filled_rounded_rectangle(SCREEN_X/2-274, SCREEN_Y/2-44, 
							SCREEN_X/2+274, SCREEN_Y/2+44,
							30,30,
   							al_map_rgb(255,255,255));	

							
	al_draw_filled_rounded_rectangle(SCREEN_X/2-270, SCREEN_Y/2-40, 
							SCREEN_X/2+270, SCREEN_Y/2+40,
							30,30,
   							al_map_rgb(0,0,0));	

    al_draw_text(fonte_botoes,                    
                 al_map_rgb(230, 230, 250),            
                 SCREEN_X / 2,                         
                 SCREEN_Y / 2 - 10,                    
                 ALLEGRO_ALIGN_CENTRE,                 
                 "PLAY");


	al_draw_text(fonte_botoes,                       
				al_map_rgb(252, 75, 8),             
				SCREEN_X / 2,                          
				SCREEN_Y / 2 - 120,
				ALLEGRO_ALIGN_CENTRE,
				"SPACE INVADERS");
	
}



//DESENHAR MENU DE LEVELS
void draw_levels(float A[], float B[],ALLEGRO_FONT *fonte_botoes){
	
	al_clear_to_color(al_map_rgb(17,17,76));
	int i;
	for (i=0;i<STARS;i++){
		al_draw_filled_rectangle(A[i],B[i], 
						A[i]+3, B[i]+3,
   						al_map_rgb(255,255,255));
		B[i] = B[i] + 0.05;
		A[i] = A[i] + 0.05;
	}

	al_draw_filled_rectangle(0, SCREEN_Y-GRASS_Y, 
							SCREEN_X, SCREEN_Y-GROUND_Y,
   							al_map_rgb(0, 155, 0));
	al_draw_filled_rectangle(0, SCREEN_Y-GROUND_Y, 
							SCREEN_X, SCREEN_Y,
   							al_map_rgb(135,62,35));	

							
	al_draw_filled_rounded_rectangle(SCREEN_X/2-450, SCREEN_Y/2-170, 
							SCREEN_X/2+450, SCREEN_Y/2+170,
							30,30,
   							al_map_rgb(12, 12, 52));	
							
							
	al_draw_filled_rounded_rectangle(SCREEN_X/2-274, SCREEN_Y/2-44, 
							SCREEN_X/2+274, SCREEN_Y/2+44,
							30,30,
   							al_map_rgb(255,255,255));	


							
// --- Botão 1: Level 1 (Esquerda) ---
// Borda branca
al_draw_filled_rounded_rectangle(SCREEN_X/2 - 374, SCREEN_Y/2 - 44,
                                 SCREEN_X/2 - 146, SCREEN_Y/2 + 44,
                                 15, 15, al_map_rgb(255, 255, 255));
// Botão preto
al_draw_filled_rounded_rectangle(SCREEN_X/2 - 370, SCREEN_Y/2 - 40,
                                 SCREEN_X/2 - 150, SCREEN_Y/2 + 40,
                                 15, 15, al_map_rgb(0, 0, 0));
// Texto do botão
al_draw_text(fonte_botoes, al_map_rgb(230, 230, 250),
             SCREEN_X/2 - 265, SCREEN_Y/2 - 15,
             ALLEGRO_ALIGN_CENTRE, "Level 1");


// --- Botão 2: Level 2 (Centro) ---
// Borda branca
al_draw_filled_rounded_rectangle(SCREEN_X/2 - 114, SCREEN_Y/2 - 44,
                                 SCREEN_X/2 + 114, SCREEN_Y/2 + 44,
                                 15, 15, al_map_rgb(255, 255, 255));
// Botão preto
al_draw_filled_rounded_rectangle(SCREEN_X/2 - 110, SCREEN_Y/2 - 40,
                                 SCREEN_X/2 + 110, SCREEN_Y/2 + 40,
                                 15, 15, al_map_rgb(0, 0, 0));
// Texto do botão
al_draw_text(fonte_botoes, al_map_rgb(230, 230, 250),
             SCREEN_X/2-5, SCREEN_Y/2 - 15,
             ALLEGRO_ALIGN_CENTRE, "Level 2");


// --- Botão 3: Level 3 (Direita) ---
// Borda branca
al_draw_filled_rounded_rectangle(SCREEN_X/2 + 146, SCREEN_Y/2 - 44,
                                 SCREEN_X/2 + 374, SCREEN_Y/2 + 44,
                                 15, 15, al_map_rgb(255, 255, 255));
// Botão preto
al_draw_filled_rounded_rectangle(SCREEN_X/2 + 150, SCREEN_Y/2 - 40,
                                 SCREEN_X/2 + 370, SCREEN_Y/2 + 40,
                                 15, 15, al_map_rgb(0, 0, 0));
// Texto do botão
al_draw_text(fonte_botoes, al_map_rgb(230, 230, 250),
             SCREEN_X/2 + 255, SCREEN_Y/2 - 15,
             ALLEGRO_ALIGN_CENTRE, "Level 3");
		
// --- Botão de Sair (Canto Superior Esquerdo) ---
al_draw_filled_rounded_rectangle(SCREEN_X/2 - 370, SCREEN_Y/2 - 160,
                                 SCREEN_X/2 - 200, SCREEN_Y/2 - 90,
                                 8, 8, al_map_rgb(0, 0, 0));

// Texto do botão
al_draw_text(fonte_botoes, al_map_rgb(230, 230, 250),
             SCREEN_X/2 - 290, SCREEN_Y/2 - 135,
             ALLEGRO_ALIGN_CENTRE,
             "EXIT");

}

//DESENHAR TELA DE VITORIA
void draw_victory_screen(float A[], float B[],ALLEGRO_FONT *fonte_botoes){
	
	al_clear_to_color(al_map_rgb(17,17,76));
	int i;
	for (i=0;i<STARS;i++){
		al_draw_filled_rectangle(A[i],B[i], 
						A[i]+3, B[i]+3,
   						al_map_rgb(255,255,255));
		B[i] = B[i] + 0.05;
		A[i] = A[i] + 0.05;
	}

	al_draw_filled_rectangle(0, SCREEN_Y-GRASS_Y, 
							SCREEN_X, SCREEN_Y-GROUND_Y,
   							al_map_rgb(0, 155, 0));
	al_draw_filled_rectangle(0, SCREEN_Y-GROUND_Y, 
							SCREEN_X, SCREEN_Y,
   							al_map_rgb(135,62,35));	

							
	al_draw_filled_rounded_rectangle(SCREEN_X/2-350, SCREEN_Y/2-170, 
							SCREEN_X/2+350, SCREEN_Y/2+170,
							30,30,
   							al_map_rgb(12, 12, 52));	
							
							
	al_draw_filled_rounded_rectangle(SCREEN_X/2-274, SCREEN_Y/2-44, 
							SCREEN_X/2+274, SCREEN_Y/2+44,
							30,30,
   							al_map_rgb(255,255,255));	
	al_draw_filled_rounded_rectangle(SCREEN_X/2-274, SCREEN_Y/2+56, 
							SCREEN_X/2+274, SCREEN_Y/2+144,
							30,30,
   							al_map_rgb(255,255,255));	

							
	al_draw_filled_rounded_rectangle(SCREEN_X/2-270, SCREEN_Y/2-40, 
							SCREEN_X/2+270, SCREEN_Y/2+40,
							30,30,
   							al_map_rgb(0,0,0));	

    al_draw_text(fonte_botoes,                    
                 al_map_rgb(230, 230, 250),            
                 SCREEN_X / 2,                         
                 SCREEN_Y / 2 - 10,                    
                 ALLEGRO_ALIGN_CENTRE,                 
                 "PLAY AGAIN");


	al_draw_filled_rounded_rectangle(SCREEN_X/2-270, SCREEN_Y/2+60, 
							SCREEN_X/2+270, SCREEN_Y/2+140,
							30,30,
   							al_map_rgb(0,0,0));	
							
    al_draw_text(fonte_botoes,                       
                 al_map_rgb(230, 230, 250),             
                 SCREEN_X / 2,                          
                 SCREEN_Y / 2 + 90,
                 ALLEGRO_ALIGN_CENTRE,
                 "EXIT");


	al_draw_text(fonte_botoes,                       
				al_map_rgb(252, 75, 8),             
				SCREEN_X / 2,                          
				SCREEN_Y / 2 - 120,
				ALLEGRO_ALIGN_CENTRE,
				"VICTORY");
	
}


//DESENHAR TELA DE DERROTA
void draw_defeat(float A[], float B[],ALLEGRO_FONT *fonte_botoes){
	
	al_clear_to_color(al_map_rgb(17,17,76));
	int i;
	for (i=0;i<STARS;i++){
		al_draw_filled_rectangle(A[i],B[i], 
						A[i]+3, B[i]+3,
   						al_map_rgb(255,255,255));
		B[i] = B[i] + 0.05;
		A[i] = A[i] + 0.05;
	}

	al_draw_filled_rectangle(0, SCREEN_Y-GRASS_Y, 
							SCREEN_X, SCREEN_Y-GROUND_Y,
   							al_map_rgb(0, 155, 0));
	al_draw_filled_rectangle(0, SCREEN_Y-GROUND_Y, 
							SCREEN_X, SCREEN_Y,
   							al_map_rgb(135,62,35));	

							
	al_draw_filled_rounded_rectangle(SCREEN_X/2-350, SCREEN_Y/2-170, 
							SCREEN_X/2+350, SCREEN_Y/2+170,
							30,30,
   							al_map_rgb(12, 12, 52));	
							
							
	al_draw_filled_rounded_rectangle(SCREEN_X/2-274, SCREEN_Y/2-44, 
							SCREEN_X/2+274, SCREEN_Y/2+44,
							30,30,
   							al_map_rgb(255,255,255));	
	al_draw_filled_rounded_rectangle(SCREEN_X/2-274, SCREEN_Y/2+56, 
							SCREEN_X/2+274, SCREEN_Y/2+144,
							30,30,
   							al_map_rgb(255,255,255));	

							
	al_draw_filled_rounded_rectangle(SCREEN_X/2-270, SCREEN_Y/2-40, 
							SCREEN_X/2+270, SCREEN_Y/2+40,
							30,30,
   							al_map_rgb(0,0,0));	

    al_draw_text(fonte_botoes,                    
                 al_map_rgb(230, 230, 250),            
                 SCREEN_X / 2,                         
                 SCREEN_Y / 2 - 10,                    
                 ALLEGRO_ALIGN_CENTRE,                 
                 "PLAY AGAIN");


	al_draw_filled_rounded_rectangle(SCREEN_X/2-270, SCREEN_Y/2+60, 
							SCREEN_X/2+270, SCREEN_Y/2+140,
							30,30,
   							al_map_rgb(0,0,0));	
							
    al_draw_text(fonte_botoes,                       
                 al_map_rgb(230, 230, 250),             
                 SCREEN_X / 2,                          
                 SCREEN_Y / 2 + 90,
                 ALLEGRO_ALIGN_CENTRE,
                 "EXIT");


	al_draw_text(fonte_botoes,                       
				al_map_rgb(252, 75, 8),             
				SCREEN_X / 2,                          
				SCREEN_Y / 2 - 120,
				ALLEGRO_ALIGN_CENTRE,
				"DEFEAT");
	
}

//PARTE GERAR ALIEN
typedef struct alien{
	float x, y;
	ALLEGRO_COLOR color;
	float x_vel, y_vel;
	int vivo;
	float sizeX,sizeY;
}alien;
//LEVEL 1
void initalien1(alien *alien, float x, float y){
	alien->x = x;
	alien->y = y;
	alien->color = al_map_rgb(rand()%256,rand()%256,rand()%256);
	alien->x_vel = 0.5;
	alien->y_vel = DISTNAVES_Y;
	alien->vivo = 1;
	alien->sizeX = 70;
	alien->sizeY = 40;
}

void exibealien1(alien aliens[L_ALIENS1][C_ALIENS1]){
	int i,j;
	for (i=0;i<L_ALIENS1;i++){
		for (j=0;j<C_ALIENS1;j++){
			if(aliens[i][j].vivo==1)
				al_draw_filled_rectangle(aliens[i][j].x, aliens[i][j].y, 
										aliens[i][j].x+SIZEA_X, aliens[i][j].y + SIZEA_Y, 
										aliens[i][j].color);
		}
	}
}

void geraraliens1(alien aliens [L_ALIENS1][C_ALIENS1]){
	int i,j;
	for (i=0;i<L_ALIENS1;i++){
		for (j=0;j<C_ALIENS1;j++){
			initalien1(&aliens[i][j], j*(SIZEA_X+DISTNAVES_X),i*(SIZEA_Y+DISTNAVES_Y));
		}
	}
}

//Move alien 

int verificaaliens1(alien aliens[L_ALIENS1][C_ALIENS1]){
	int i,j;
	for (i=0;i<L_ALIENS1;i++){
		for (j=0;j<C_ALIENS1;j++){
			if((aliens[i][j].x + SIZEA_X + aliens[i][j].x_vel > SCREEN_X)||(aliens[i][j].x + aliens[i][j].x_vel < 0))
				if (aliens[i][j].vivo == 1)
					return 1;
		}
	}
	return 0;
}

void andaA1(alien aliens[L_ALIENS1][C_ALIENS1]){
	int i,j;
	if(verificaaliens1(aliens)){
		for (i=0;i<L_ALIENS1;i++){
			for (j=0;j<C_ALIENS1;j++){
				aliens[i][j].y += aliens[i][j].y_vel;
				aliens[i][j].x_vel *= -1;
			}
		}
	}
	for (i=0;i<L_ALIENS1;i++){
		for (j=0;j<C_ALIENS1;j++){
			aliens[i][j].x += aliens[i][j].x_vel;
		}
	}
}

//LEVEL 2
void initalien2(alien *alien, float x, float y){
	alien->x = x;
	alien->y = y;
	alien->color = al_map_rgb(rand()%256,rand()%256,rand()%256);
	alien->x_vel = 0.7;
	alien->y_vel = DISTNAVES_Y;
	alien->vivo = 1;
	alien->sizeX = 70;
	alien->sizeY = 40;
}

void exibealien2(alien aliens[L_ALIENS2][C_ALIENS2]){
	int i,j;
	for (i=0;i<L_ALIENS2;i++){
		for (j=0;j<C_ALIENS2;j++){
			if(aliens[i][j].vivo==1)
				al_draw_filled_rectangle(aliens[i][j].x, aliens[i][j].y, 
										aliens[i][j].x+SIZEA_X, aliens[i][j].y + SIZEA_Y, 
										aliens[i][j].color);
		}
	}
}

void geraraliens2(alien aliens [L_ALIENS2][C_ALIENS2]){
	int i,j;
	for (i=0;i<L_ALIENS2;i++){
		for (j=0;j<C_ALIENS2;j++){
			initalien2(&aliens[i][j], j*(SIZEA_X+DISTNAVES_X),i*(SIZEA_Y+DISTNAVES_Y));
		}
	}
}

//Move alien 

int verificaaliens2(alien aliens[L_ALIENS2][C_ALIENS2]){
	int i,j;
	for (i=0;i<L_ALIENS2;i++){
		for (j=0;j<C_ALIENS2;j++){
			if((aliens[i][j].x + SIZEA_X + aliens[i][j].x_vel > SCREEN_X)||(aliens[i][j].x + aliens[i][j].x_vel < 0))
				if (aliens[i][j].vivo == 1)
					return 1;
		}
	}
	return 0;
}

void andaA2(alien aliens[L_ALIENS2][C_ALIENS2]){
	int i,j;
	if(verificaaliens2(aliens)){
		for (i=0;i<L_ALIENS2;i++){
			for (j=0;j<C_ALIENS2;j++){
				aliens[i][j].y += aliens[i][j].y_vel;
				aliens[i][j].x_vel *= -1;
			}
		}
	}
	for (i=0;i<L_ALIENS2;i++){
		for (j=0;j<C_ALIENS2;j++){
			aliens[i][j].x += aliens[i][j].x_vel;
		}
	}
}
//LEVEL 3
void initalien3(alien *alien, float x, float y){
	alien->x = x;
	alien->y = y;
	alien->color = al_map_rgb(rand()%256,rand()%256,rand()%256);
	alien->x_vel = 1;
	alien->y_vel = DISTNAVES_Y;
	alien->vivo = 1;
	alien->sizeX = 70;
	alien->sizeY = 40;
}

void exibealien3(alien aliens[L_ALIENS3][C_ALIENS3]){
	int i,j;
	for (i=0;i<L_ALIENS3;i++){
		for (j=0;j<C_ALIENS3;j++){
			if(aliens[i][j].vivo==1)
				al_draw_filled_rectangle(aliens[i][j].x, aliens[i][j].y, 
										aliens[i][j].x+SIZEA_X, aliens[i][j].y + SIZEA_Y, 
										aliens[i][j].color);
		}
	}
}

void geraraliens3(alien aliens [L_ALIENS3][C_ALIENS3]){
	int i,j;
	for (i=0;i<L_ALIENS3;i++){
		for (j=0;j<C_ALIENS3;j++){
			initalien3(&aliens[i][j], j*(SIZEA_X+DISTNAVES_X),i*(SIZEA_Y+DISTNAVES_Y));
		}
	}
}

//Move alien 

int verificaaliens3(alien aliens[L_ALIENS3][C_ALIENS3]){
	int i,j;
	for (i=0;i<L_ALIENS3;i++){
		for (j=0;j<C_ALIENS3;j++){
			if((aliens[i][j].x + SIZEA_X + aliens[i][j].x_vel > SCREEN_X)||(aliens[i][j].x + aliens[i][j].x_vel < 0))
				if (aliens[i][j].vivo == 1)
					return 1;
		}
	}
	return 0;
}

void andaA3(alien aliens[L_ALIENS3][C_ALIENS3]){
	int i,j;
	if(verificaaliens3(aliens)){
		for (i=0;i<L_ALIENS3;i++){
			for (j=0;j<C_ALIENS3;j++){
				aliens[i][j].y += aliens[i][j].y_vel;
				aliens[i][j].x_vel *= -1;
			}
		}
	}
	for (i=0;i<L_ALIENS3;i++){
		for (j=0;j<C_ALIENS3;j++){
			aliens[i][j].x += aliens[i][j].x_vel;
		}
	}
}

//Se bateu no alien retorna 1.
int hitbox(alien alien,float x, float y){
	if(x >= alien.x && x<=alien.x+SIZEA_X && y >= alien.y && y <= alien.y + SIZEA_Y)
		return 1;
	return 0;
}



//PARTE GERAR CANHAO
typedef struct canhao{
	float x;
	ALLEGRO_COLOR color;
	int type;
	int vel;
	int esq, dir;
	int super1;	// 1:Super Tiro por 5 seg
 	int super2;// 2: Double Tiro por 5 seg 
	int super3; // 3: 
}canhao;


void initcanhao(canhao *canhao){
	canhao->x = SCREEN_X/2;
	canhao->color = al_map_rgb(0,0,255);
	canhao->vel = 1;
	canhao->esq = 0;
	canhao->dir = 0;
	canhao->super1 = 0;
	canhao->super2 = 0;
	canhao->super3 = 0;
}

void exibecanhao(canhao canhao){
	al_draw_filled_triangle(canhao.x, SCREEN_Y-GROUND_Y-SIZEC_Y, 
							canhao.x+SIZEC_X, SCREEN_Y-GROUND_Y-3,
   							canhao.x-SIZEC_X, SCREEN_Y-GROUND_Y-3, 
							canhao.color);
}

//Move canhão

void anda(canhao *canhao){
	if ((canhao->esq == 1)&&(canhao->dir == 0)&&(canhao->x-SIZEC_X != 0))
		canhao->x -= canhao->vel;
	else if ((canhao->esq == 0)&&(canhao->dir == 1)&&(canhao->x+SIZEC_X != SCREEN_X))
		canhao->x += canhao->vel;
}

//Gerar tiro

typedef struct tiro{
	float x, y;
	ALLEGRO_COLOR color;
	int ativo;
	int vel;
	float r;
	char type;
}tiro;

void iniciatiro(tiro * tiro){
	tiro->ativo = 0;
}

void dartiro(tiro * tiro, canhao canhao){
	if (tiro->ativo == 0){
		tiro->x = canhao.x;
		tiro->y = SCREEN_Y-GROUND_Y-SIZEC_Y;
		tiro->color =  al_map_rgb(rand()%256,rand()%256,rand()%256);
		tiro->ativo = 1;
		tiro->vel = 1;
		tiro->r = 5;
		tiro->type = 'c';
	}
}

void supertiro(tiro * tiro, canhao canhao){
	if (tiro->ativo == 0 && canhao.super1 == 1){
		tiro->x = canhao.x;
		tiro->y = SCREEN_Y-GROUND_Y-SIZEC_Y;
		tiro->color =  al_map_rgb(rand()%256,rand()%256,rand()%256);
		tiro->ativo = 1;
		tiro->vel = 6;
		tiro->r = 15;
		tiro->type = 's';
	}
}

void andaT(tiro * tiro){
	if (tiro->ativo==1){
		tiro->y -= tiro->vel;
		if(tiro->y < 2){
			tiro->color=al_map_rgb(255,0,0);
			tiro->ativo=0;
		}
	}
}

void exibetiro(tiro tiro){
	if(tiro.ativo==1 && tiro.type == 'c')
		al_draw_filled_circle(tiro.x, tiro.y, tiro.r, tiro.color);
	else if(tiro.ativo==1 && tiro.type == 's')
		al_draw_filled_circle(tiro.x, tiro.y, tiro.r, al_map_rgb(rand()%256,rand()%256,rand()%256));
}

//retorna 1 se uma coordenada encosta no tiro
int hitboxtiro(tiro tiro, float x, float y){
	float vetorX = x - tiro.x;
	float vetorY = y - tiro.y;
	if (pow(vetorX,2) + pow(vetorY,2) <= pow(tiro.r,2)){
		return 1;
	}
	return 0;
}

// retorna 1 se qualquer quina do alien encostar na bola que compoe o tiro
int tiroacertalien(tiro tiro, alien alien){
	if (hitboxtiro(tiro, alien.x, alien.y)||hitboxtiro(tiro, alien.x+alien.sizeX, alien.y)
	||hitboxtiro(tiro, alien.x, alien.y+alien.sizeY)||hitboxtiro(tiro, alien.x+alien.sizeX, alien.y+alien.sizeY))
		return 1;
	return 0;
}



//Gerar e exibir token de superpower
typedef struct super{
	int type;
	float x,y;
	float vel;
	float r;
	ALLEGRO_COLOR color;
}super;

void initsuper(super *s) {
    s->type = 0; 
    s->x = 0;
    s->y = 0;
    s->r = 0;
    s->vel = 0;
}
void gerarsuper(int s, super *super, alien alien){
	super->x = alien.x+SIZEA_X/2;
	super->y = alien.y+SIZEA_Y/2;
	super ->r = 10;
	super ->vel = 0.5;
	if (s == 1){
		super->type = 1;
		super -> color = al_map_rgb(255,0,0);
	}
	else if(s == 2){
		super->type = 2;
		super -> color = al_map_rgb(0,0,255);
	}
	else if(s == 3){
		super->type = 3;
		super -> color = al_map_rgb(0,255,0);
	}
	else{
		super->type = 0;
	}
}

void andaS(super * super){
	if (super->type!=0){
		super->y += super->vel;
		if(super->y > SCREEN_Y-GRASS_Y){
			super->type = 0;
		}
	}
}

void exibesuper(super super){
	if(super.type!=0)
		al_draw_filled_circle(super.x, super.y, super.r, super.color);
}

int hitboxsuper(super super, float x, float y){
	float vetorX = x - super.x;
	float vetorY = y - super.y;
	if (pow(vetorX,2) + pow(vetorY,2) <= pow(super.r,2)){
		return 1;
	}
	return 0;
}

void colidesuper(super *super, canhao *canhao,
				ALLEGRO_TIMER *timer1, ALLEGRO_TIMER *timer2,ALLEGRO_TIMER *timer3){
	if (hitboxsuper(*super,canhao->x,SCREEN_Y-GROUND_Y-SIZEC_Y)&&super->type != 0){
		switch (super->type){
			case 1:
				canhao->super1 = 1;
                al_set_timer_count(timer1, 0);
                al_start_timer(timer1);
				break;
			case 2:
				canhao->super2 = 1;
                al_set_timer_count(timer2, 0);
                al_start_timer(timer2);
				break;
			case 3:
				canhao->super3 = 1;
                al_set_timer_count(timer3, 0);
                al_start_timer(timer3);
				break;
			default:
				break;
		}
		super->type = 0;
	}
}

void verificacooldown(canhao *canhao,	ALLEGRO_TIMER *timer1, 
					ALLEGRO_TIMER *timer2,ALLEGRO_TIMER *timer3){

	float t1 = (float)(al_get_timer_count(timer1)/FPS);
	float t2 = (float)(al_get_timer_count(timer2)/FPS);
	float t3 = (float)(al_get_timer_count(timer3)/FPS);

	if (t1>=5){
		canhao->super1 = 0;
	}
	if (t2>=5){
		canhao->super2 = 0;
	}
	if (t3>=5){
		canhao->super3 = 0;
		
	}
}



//PARTE GERAR CENÁRIOS

void amanhece(ALLEGRO_TIMER *timer, ALLEGRO_COLOR *coratual){
		*coratual = al_map_rgb(0+fmin(244,2.44*(float)al_get_timer_count(timer)/(int)FPS)
							,0+fmin(158,1.58*(float)al_get_timer_count(timer)/(int)FPS), 
							 0+fmin(18,0.18*(float)al_get_timer_count(timer)/(int)FPS));
}


void draw_scenario(float A[], float B[],ALLEGRO_COLOR color, int pontos, ALLEGRO_FONT *fonte_botoes, canhao canhao, int recorde){	
	al_clear_to_color(color);

	int i;
	for (i=0;i<STARS;i++){
		al_draw_filled_rectangle(A[i],B[i], 
						A[i]+3, B[i]+3,
   						al_map_rgb(255,255,255));
		//move as estrelas para baixo
		B[i] = B[i] + 0.05;
	}

	al_draw_filled_rectangle(0, SCREEN_Y-GRASS_Y, 
							SCREEN_X, SCREEN_Y-GROUND_Y,
   							al_map_rgb(0, 155, 0));
	al_draw_filled_rectangle(0, SCREEN_Y-GROUND_Y, 
							SCREEN_X, SCREEN_Y,
   							al_map_rgb(135,62,35));	
    char string_pontos[10];
	snprintf(string_pontos, 10, "%d", pontos);//funcao que converte nossa int %d para uma string que sera armazenada em string_pontos
	al_draw_text(fonte_botoes, al_map_rgb(230, 230, 250),
             70, SCREEN_Y - GROUND_Y/1.5,
             ALLEGRO_ALIGN_CENTRE, string_pontos);

    char string_recorde[10];
    snprintf(string_recorde, 20, "Record: %d", recorde);
    al_draw_text(fonte_botoes, al_map_rgb(255, 215, 0), 
                 SCREEN_X - 150, 30,
                 ALLEGRO_ALIGN_CENTRE, string_recorde);

	if (canhao.super1){
			al_draw_text(fonte_botoes, al_map_rgb(0, 0, 250),
			250, SCREEN_Y - GROUND_Y/1.5,
			ALLEGRO_ALIGN_CENTRE, "Power 1");
	}
	else if (canhao.super1 == 0){
			al_draw_text(fonte_botoes, al_map_rgb(0, 0, 0),
			250, SCREEN_Y - GROUND_Y/1.5,
			ALLEGRO_ALIGN_CENTRE, "Power 1");
	}
	if (canhao.super2){
		al_draw_text(fonte_botoes, al_map_rgb(0, 0, 250),
        500, SCREEN_Y - GROUND_Y/1.5,
        ALLEGRO_ALIGN_CENTRE, "Power 2");
	}
	else if (canhao.super2 == 0){
		al_draw_text(fonte_botoes, al_map_rgb(0, 0, 0),
        500, SCREEN_Y - GROUND_Y/1.5,
        ALLEGRO_ALIGN_CENTRE, "Power 2");
	}

	if (canhao.super3){
		al_draw_text(fonte_botoes, al_map_rgb(0, 0, 250),
        750, SCREEN_Y - GROUND_Y/1.5,
        ALLEGRO_ALIGN_CENTRE, "Power 3" );
	}
	else if (canhao.super3 == 0){
		al_draw_text(fonte_botoes, al_map_rgb(0, 0, 0),
        750, SCREEN_Y - GROUND_Y/1.5,
        ALLEGRO_ALIGN_CENTRE, "Power 3" );
	}
}

void fillX(float V[], int n){
	int i;
	for(i=0;i<n;i++)
		V[i] = rand()%(SCREEN_X+999)-1000;
}

void fillY(float V[], int n){
	int i;
	for(i=0;i<n;i++)
		V[i] =   rand()%(SCREEN_Y-GRASS_Y+999)-1000;
}

void draw_victory(float A[], float B[]){
	al_clear_to_color(al_map_rgb(155, 155, 0));
	int i;
	for (i=0;i<STARS;i++){
		al_draw_filled_rectangle(A[i],B[i], 
						A[i]+3, B[i]+3,
   						al_map_rgb(255,255,255));
	}
	al_draw_filled_rectangle(0, SCREEN_Y-GRASS_Y, 
							SCREEN_X, SCREEN_Y-GROUND_Y,
   							al_map_rgb(0, 155, 0));
	al_draw_filled_rectangle(0, SCREEN_Y-GROUND_Y, 
							SCREEN_X, SCREEN_Y,
   							al_map_rgb(135,62,35));	
}

//COLISAO ENTRE ALIEN E TIRO
void verificacolisao1(tiro *tiro, alien aliens [L_ALIENS1][C_ALIENS1], super* super, canhao *canhao){
	int i,j;
	for(i=0;i<L_ALIENS1;i++){
		for(j=0;j<C_ALIENS1;j++){
			if ((hitbox(aliens[i][j],tiro->x,tiro->y) && tiro->ativo == 1 && aliens[i][j].vivo == 1)
				||(tiroacertalien(*tiro, aliens[i][j]) && tiro->ativo == 1 && aliens[i][j].vivo == 1)){
				if (canhao->super3 == 0){
					tiro->ativo = 0;
				}
				canhao->super3 = 0;
				aliens[i][j].vivo = 0;
				if (super->type == 0)
					gerarsuper(rand()%3+1,super, aliens[i][j]);
				return;
			}
		}
	}
}
//COLISAO ENTRE ALIEN E CANHAO OU ALIEN E CHÃO
int perdeu1(alien aliens [L_ALIENS1][C_ALIENS1], canhao canhao){
	int i,j;
	for(i=0;i<L_ALIENS1;i++){
		for(j=0;j<C_ALIENS1;j++){
			if ((hitbox(aliens[i][j],canhao.x,SCREEN_Y-GROUND_Y-SIZEC_Y) && aliens[i][j].vivo == 1)||(aliens[i][j].y+SIZEA_Y >= SCREEN_Y-GRASS_Y && aliens[i][j].vivo == 1)){
				return 1;
			}
		}
	}
	return 0;
}	
//PONTUACAO
int pontuacao1(alien aliens[L_ALIENS1][C_ALIENS1]){
	int i,j;
	int pontos = 0;
	for(i=0;i<L_ALIENS1;i++){
		for(j=0;j<C_ALIENS1;j++){
			if (aliens[i][j].vivo == 0){
				pontos ++;
			}
		}
	}
	return pontos;
}

//COLISAO ENTRE ALIEN E CANHAO OU ALIEN E CHÃO
int perdeu2(alien aliens[L_ALIENS2][C_ALIENS2], canhao canhao){
	int i,j;
	for(i=0;i<L_ALIENS2;i++){
		for(j=0;j<C_ALIENS2;j++){
			if ((hitbox(aliens[i][j],canhao.x,SCREEN_Y-GROUND_Y-SIZEC_Y) && aliens[i][j].vivo == 1)||(aliens[i][j].y+SIZEA_Y >= SCREEN_Y-GRASS_Y && aliens[i][j].vivo == 1)){
				return 1;
			}
		}
	}
	return 0;
}	
//PONTUACAO
int pontuacao2(alien aliens[L_ALIENS2][C_ALIENS2]){
	int i,j;
	int pontos = 0;
	for(i=0;i<L_ALIENS2;i++){
		for(j=0;j<C_ALIENS2;j++){
			if (aliens[i][j].vivo == 0){
				pontos ++;
			}
		}
	}
	return pontos;
}	

void verificacolisao2(tiro *tiro, alien aliens [L_ALIENS2][C_ALIENS2], super* super, canhao *canhao){
	int i,j;
	for(i=0;i<L_ALIENS2;i++){
		for(j=0;j<C_ALIENS2;j++){
			if ((hitbox(aliens[i][j],tiro->x,tiro->y) && tiro->ativo == 1 && aliens[i][j].vivo == 1)
				||(tiroacertalien(*tiro, aliens[i][j]) && tiro->ativo == 1 && aliens[i][j].vivo == 1)){
				if (canhao->super3 == 0){
					tiro->ativo = 0;
				}
				canhao->super3 = 0;
				aliens[i][j].vivo = 0;
				if (super->type == 0)
					gerarsuper(rand()%3+1,super, aliens[i][j]);
				return;
			}
		}
	}
}


//COLISAO ENTRE ALIEN E CANHAO OU ALIEN E CHÃO
int perdeu3(alien aliens[L_ALIENS3][C_ALIENS3], canhao canhao){
	int i,j;
	for(i=0;i<L_ALIENS3;i++){
		for(j=0;j<C_ALIENS3;j++){
			if ((hitbox(aliens[i][j],canhao.x,SCREEN_Y-GROUND_Y-SIZEC_Y) && aliens[i][j].vivo == 1)||(aliens[i][j].y+SIZEA_Y >= SCREEN_Y-GRASS_Y && aliens[i][j].vivo == 1)){
				return 1;
			}
		}
	}
	return 0;
}	
//PONTUACAO
int pontuacao3(alien aliens[L_ALIENS3][C_ALIENS3]){
	int i,j;
	int pontos = 0;
	for(i=0;i<L_ALIENS3;i++){
		for(j=0;j<C_ALIENS3;j++){
			if (aliens[i][j].vivo == 0){
				pontos ++;
			}
		}
	}
	return pontos;
}	

void verificacolisao3(tiro *tiro, alien aliens [L_ALIENS3][C_ALIENS3], super* super, canhao *canhao){
	int i,j;
	for(i=0;i<L_ALIENS3;i++){
		for(j=0;j<C_ALIENS3;j++){
			if ((hitbox(aliens[i][j],tiro->x,tiro->y) && tiro->ativo == 1 && aliens[i][j].vivo == 1)
				||(tiroacertalien(*tiro, aliens[i][j]) && tiro->ativo == 1 && aliens[i][j].vivo == 1)){
				if (canhao->super3 == 0){
					tiro->ativo = 0;
				}
				canhao->super3 = 0;
				aliens[i][j].vivo = 0;
				if (super->type == 0)
					gerarsuper(rand()%3+1,super, aliens[i][j]);
				return;
			}
		}
	}
}
//Main do Game 
 
int main(){
    int recorde;
    int pontos_atuais = 0; 
	int i,j;
	tiro tiro1;
	tiro tiro2;
	canhao canhao;
	alien aliens1[L_ALIENS1][C_ALIENS1];
	alien aliens2[L_ALIENS2][C_ALIENS2];
	alien aliens3[L_ALIENS3][C_ALIENS3];
	super super;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_TIMER *cooldown1 = NULL;
	ALLEGRO_TIMER *cooldown2 = NULL;
	ALLEGRO_TIMER *cooldown3 = NULL;
	ALLEGRO_COLOR skycolor;
	ALLEGRO_FONT *fonte_botoes = NULL;
	float starsX[STARS];
	fillX(starsX,STARS);
	float starsY[STARS];
	fillY(starsY,STARS);
	char estadodejogo;
    ALLEGRO_AUDIO_STREAM *musica_fundo = NULL; 


   
	//----------------------- rotinas de inicializacao ---------------------------------------
    
	//inicializa o Allegro
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	//inicializa o módulo de primitivas do Allegro
    if(!al_init_primitives_addon()){
		fprintf(stderr, "failed to initialize primitives!\n");
        return -1;
    }	
   
	//cria um temporizador que incrementa uma unidade a cada 1.0/FPS segundos
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	cooldown1 = al_create_timer(1.0 / FPS);
	if(!cooldown1) {
		fprintf(stderr, "failed to create cooldown1 timer!\n");
		al_destroy_timer(timer); // Destrua o que já foi criado
		return -1;
	}
	cooldown2 = al_create_timer(1.0 / FPS);
	if(!cooldown2) {
		fprintf(stderr, "failed to create cooldown2 timer!\n");
		al_destroy_timer(timer);
		al_destroy_timer(cooldown1);
		return -1;
	}
	cooldown3 = al_create_timer(1.0 / FPS);
	if(!cooldown3) {
		fprintf(stderr, "failed to create cooldown3 timer!\n");
		al_destroy_timer(timer);
		al_destroy_timer(cooldown1);
		al_destroy_timer(cooldown2);
		return -1;
	}
 
	//cria uma tela com dimensoes de SCREEN_X, SCREEN_Y pixels
	display = al_create_display(SCREEN_X, SCREEN_Y);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	//instala o teclado
	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to install keyboard!\n");
		return -1;
	}
	
	//instala o mouse
	if(!al_install_mouse()) {
		fprintf(stderr, "failed to initialize mouse!\n");
		return -1;
	}

 	//cria a fila de eventos
	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		return -1;
	}
	    // Inicializa o addon de áudio
    if(!al_install_audio()){
        fprintf(stderr, "failed to initialize audio!\n");
        return -1;
    }

    // Inicializa o addon que carrega os codecs de áudio (OGG, MP3, etc)
    if(!al_init_acodec_addon()){
        fprintf(stderr, "failed to initialize audio codecs!\n");
        return -1;
    }

    // "Reserva" canais de áudio para tocar sons. 1 é suficiente para a música.
    if (!al_reserve_samples(1)){
        fprintf(stderr, "failed to reserve samples!\n");
        return -1;
    }

    // Carrega o arquivo de áudio. Troque "sua_musica.ogg" pelo nome do seu arquivo.
    musica_fundo = al_load_audio_stream("battle.ogg", 4, 1024);
    if (!musica_fundo) {
        fprintf(stderr, "audio stream not loaded!\n" );
		al_destroy_display(display);
        return -1;
    }
	al_init_primitives_addon();
	al_init_font_addon();    
	al_init_ttf_addon();

	al_set_audio_stream_playmode(musica_fundo, ALLEGRO_PLAYMODE_LOOP);

    al_attach_audio_stream_to_mixer(musica_fundo, al_get_default_mixer());

    recorde = ler_recorde();


	//registra na fila os eventos de tela (ex: clicar no X na janela)
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//registra na fila os eventos de tempo: quando o tempo altera de t para t+1
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	//registra na fila os eventos de teclado (ex: pressionar uma tecla)
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	//registra na fila os eventos de mouse (ex: clicar em um botao do mouse)
	al_register_event_source(event_queue, al_get_mouse_event_source());  	
	//inicia o temporizador	
	al_start_timer(timer);
	//inicia o canhao

	fonte_botoes = al_load_font("Heroes Legend.ttf", 30, 0);


	estadodejogo = 'M';

	while(estadodejogo != 'E') {
		ALLEGRO_EVENT ev;
		//espera por um evento e o armazena na variavel de evento ev
		al_wait_for_event(event_queue, &ev);

		switch(estadodejogo){

			case 'M':
				if(ev.type == ALLEGRO_EVENT_TIMER) {
					draw_menu(starsX,starsY,fonte_botoes);
				}

				if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);
						if(ev.mouse.x >= SCREEN_X/2-270 && ev.mouse.x<=SCREEN_X/2+270 
							&& ev.mouse.y >= SCREEN_Y/2-40 && ev.mouse.y <= SCREEN_Y/2+40){
								estadodejogo = 'L';
						}					
				}

				//se o tipo de evento for o fechamento da tela (clique no x da janela)
				if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
					estadodejogo = 'E';
				}

				break;

			case 'L':
				if(ev.type == ALLEGRO_EVENT_TIMER) {
					draw_levels(starsX,starsY,fonte_botoes);
				}

				if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);

					// --- Verifica clique no Botão LEVEL 1 ---
					if(ev.mouse.x >= (SCREEN_X/2 - 370) && ev.mouse.x <= (SCREEN_X/2 - 150) 
						&& ev.mouse.y >= (SCREEN_Y/2 - 40) && ev.mouse.y <= (SCREEN_Y/2 + 40)){
							estadodejogo = '1';
							initcanhao(&canhao);
	
							geraraliens1(aliens1);

							iniciatiro(&tiro1);

							iniciatiro(&tiro2);

							initsuper(&super);
							
					}

					// --- Verifica clique no Botão LEVEL 2 ---
					if(ev.mouse.x >= (SCREEN_X/2 - 110) && ev.mouse.x <= (SCREEN_X/2 + 110)
						&& ev.mouse.y >= (SCREEN_Y/2 - 40) && ev.mouse.y <= (SCREEN_Y/2 + 40)){
							estadodejogo = '2';
							initcanhao(&canhao);
	
							geraraliens2(aliens2);

							iniciatiro(&tiro1);

							iniciatiro(&tiro2);

							initsuper(&super);
					}
					
					// --- Verifica clique no Botão LEVEL 3 ---
					if(ev.mouse.x >= (SCREEN_X/2 + 150) && ev.mouse.x <= (SCREEN_X/2 + 370)
						&& ev.mouse.y >= (SCREEN_Y/2 - 40) && ev.mouse.y <= (SCREEN_Y/2 + 40)){
							estadodejogo = '3';
							initcanhao(&canhao);
	
							geraraliens3(aliens3);

							iniciatiro(&tiro1);

							iniciatiro(&tiro2);

							initsuper(&super);
					}
					
					// --- Verifica clique no Botão EXIT ---
					if(ev.mouse.x >= (SCREEN_X/2 - 370) && ev.mouse.x <= (SCREEN_X/2 - 200)
						&& ev.mouse.y >= (SCREEN_Y/2 - 160) && ev.mouse.y <= (SCREEN_Y/2 - 90)){
							estadodejogo = 'M';
					}
				}

				//se o tipo de evento for o fechamento da tela (clique no x da janela)
				if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
					estadodejogo = 'E';
				}

				break;
			

			case 'V':
				if(ev.type == ALLEGRO_EVENT_TIMER) {
                	draw_victory_screen(starsX, starsY, fonte_botoes);
            	}

            	if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                	printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);
				
					// Coordenadas do botão "PLAY AGAIN" (as mesmas do botão "PLAY" do menu)
					if(ev.mouse.x >= SCREEN_X/2-270 && ev.mouse.x <= SCREEN_X/2+270
					&& ev.mouse.y >= SCREEN_Y/2-40 && ev.mouse.y <= SCREEN_Y/2+40){
						estadodejogo = 'L'; // Volta para a tela de seleção de nível
					}

					// Coordenadas do botão "EXIT" (as mesmas do botão "OPTIONS" do menu)
					if(ev.mouse.x >= SCREEN_X/2-270 && ev.mouse.x <= SCREEN_X/2+270
					&& ev.mouse.y >= SCREEN_Y/2+60 && ev.mouse.y <= SCREEN_Y/2+140){
						estadodejogo = 'E'; // Sai do jogo
					}
				}

				//se o tipo de evento for o fechamento da tela (clique no x da janela)
				if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
					estadodejogo = 'E';
				}
				break;

			case'D':
				if(ev.type == ALLEGRO_EVENT_TIMER) {
                	draw_defeat(starsX, starsY, fonte_botoes);
            	}

            	if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
                	printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);
				
					// Coordenadas do botão "PLAY AGAIN" (as mesmas do botão "PLAY" do menu)
					if(ev.mouse.x >= SCREEN_X/2-270 && ev.mouse.x <= SCREEN_X/2+270
					&& ev.mouse.y >= SCREEN_Y/2-40 && ev.mouse.y <= SCREEN_Y/2+40){
						estadodejogo = 'L'; // Volta para a tela de seleção de nível
					}

					// Coordenadas do botão "EXIT" (as mesmas do botão "OPTIONS" do menu)
					if(ev.mouse.x >= SCREEN_X/2-270 && ev.mouse.x <= SCREEN_X/2+270
					&& ev.mouse.y >= SCREEN_Y/2+60 && ev.mouse.y <= SCREEN_Y/2+140){
						estadodejogo = 'E'; // Sai do jogo
					}
				}

				//se o tipo de evento for o fechamento da tela (clique no x da janela)
				if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
					estadodejogo = 'E';
				}
				break;



			case '1'://CASO PLAYING, O JOGO ESTA RODANDO NIVEL 1
				//se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
				if(ev.type == ALLEGRO_EVENT_TIMER) {
	                pontos_atuais = pontuacao1(aliens1); // Atualiza a pontuação da rodada
			        if (pontos_atuais > recorde) {
                        recorde = pontos_atuais;
                    }
					//atualiza a tela (quando houver algo para mostrar)
					al_flip_display();

					amanhece(timer,&skycolor);
					//função para desenhar o cenário do game
					draw_scenario(starsX,starsY,skycolor, pontuacao1(aliens1), fonte_botoes, canhao, recorde);
					//atualiza a posição do canhao
					anda(&canhao);

					andaA1(aliens1);
					exibealien1(aliens1);
					//desenha o canhão
					exibecanhao(canhao);

					andaT(&tiro1);
					andaT(&tiro2);
				
					exibetiro(tiro1);
					exibetiro(tiro2);

					verificacolisao1(&tiro1,aliens1,&super,&canhao);
					verificacolisao1(&tiro2,aliens1,&super,&canhao);
					exibesuper(super);
					andaS(&super);
					colidesuper(&super,&canhao,cooldown1,cooldown2,cooldown3);
					verificacooldown(&canhao,cooldown1,cooldown2,cooldown3);
				

					if (perdeu1(aliens1, canhao)){
						al_flip_display();
						draw_scenario(starsX,starsY,skycolor, pontuacao1(aliens1),fonte_botoes, canhao, recorde);
						exibecanhao(canhao);
						exibealien1(aliens1);
						al_rest(3.0);
						estadodejogo = 'D';
					}
					if (pontuacao1(aliens1)==C_ALIENS1*L_ALIENS1){
						estadodejogo = 'V';
					}

					if(al_get_timer_count(timer)%(int)FPS == 0)
						printf("\n%d segundos se passaram...", (int)(al_get_timer_count(timer)/FPS));
					}
					//se o tipo de evento for o fechamento da tela (clique no x da janela)
					else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
						estadodejogo = 'E';
					}
					//se o tipo de evento for um clique de mouse
					else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
						printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);
						

					}
				//se o tipo de evento for um pressionar de uma tecla
				else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
					//imprime qual tecla foi
					printf("\ncodigo tecla: %d", ev.keyboard.keycode);

					switch (ev.keyboard.keycode){
					case ALLEGRO_KEY_A:
						canhao.esq = 1;
						break;
					case ALLEGRO_KEY_D:
						canhao.dir = 1;
						break;
					case ALLEGRO_KEY_SPACE:
						if (tiro1.ativo && canhao.super2){
							dartiro(&tiro2, canhao);
						}
						else{
							dartiro(&tiro1, canhao);
						}
						break;
					case ALLEGRO_KEY_C:
						if (tiro1.ativo && canhao.super2){
							supertiro(&tiro2, canhao);
						}
						else{
							supertiro(&tiro1, canhao);
						}
						break;
					default:
						break;
					}
				}
				
				else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
					//imprime qual tecla foi
					printf("\ncodigo tecla: %d", ev.keyboard.keycode);

					switch (ev.keyboard.keycode){
					case ALLEGRO_KEY_A:
						canhao.esq = 0;
						break;
					case ALLEGRO_KEY_D:
						canhao.dir = 0;
						break;
					default:
						break;
					}
				}
				break;


			case '2'://CASO PLAYING, O JOGO ESTA RODANDO NIVEL 2
				//se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
				if(ev.type == ALLEGRO_EVENT_TIMER) {
				    pontos_atuais = pontuacao2(aliens2); // Atualiza a pontuação da rodada
			        if (pontos_atuais > recorde) {
                        recorde = pontos_atuais;
                    }

					//atualiza a tela (quando houver algo para mostrar)
					al_flip_display();

					amanhece(timer,&skycolor);
					//função para desenhar o cenário do game
					draw_scenario(starsX,starsY,skycolor, pontuacao2(aliens2), fonte_botoes, canhao, recorde);

					//atualiza a posição do canhao
					anda(&canhao);

					andaA2(aliens2);
					exibealien2(aliens2);
					//desenha o canhão
					exibecanhao(canhao);

					andaT(&tiro1);
					andaT(&tiro2);
				
					exibetiro(tiro1);
					exibetiro(tiro2);

					verificacolisao2(&tiro1,aliens2,&super,&canhao);
					verificacolisao2(&tiro2,aliens2,&super,&canhao);

					exibesuper(super);
					andaS(&super);
					colidesuper(&super,&canhao,cooldown1,cooldown2,cooldown3);
					verificacooldown(&canhao,cooldown1,cooldown2,cooldown3);
					

					if (perdeu2(aliens2, canhao)){
						al_flip_display();
						draw_scenario(starsX,starsY,skycolor, pontuacao2(aliens2),fonte_botoes, canhao, recorde);
						exibecanhao(canhao);
						exibealien2(aliens2);
						al_rest(3.0);
						estadodejogo = 'D';
					}
					if (pontuacao2(aliens2)==C_ALIENS2*L_ALIENS2){
						estadodejogo = 'V';
					}

					if(al_get_timer_count(timer)%(int)FPS == 0)
						printf("\n%d segundos se passaram...", (int)(al_get_timer_count(timer)/FPS));
				}
				//se o tipo de evento for o fechamento da tela (clique no x da janela)
				else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
					estadodejogo = 'E';
				}
				//se o tipo de evento for um clique de mouse
				else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);
					

				}
				//se o tipo de evento for um pressionar de uma tecla
				else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
					//imprime qual tecla foi
					printf("\ncodigo tecla: %d", ev.keyboard.keycode);

					switch (ev.keyboard.keycode){
					case ALLEGRO_KEY_A:
						canhao.esq = 1;
						break;
					case ALLEGRO_KEY_D:
						canhao.dir = 1;
						break;
					case ALLEGRO_KEY_SPACE:
						if (tiro1.ativo && canhao.super2){
							dartiro(&tiro2, canhao);
						}
						else{
							dartiro(&tiro1, canhao);
						}
						break;
					case ALLEGRO_KEY_C:
						if (tiro1.ativo && canhao.super2){
							supertiro(&tiro2, canhao);
						}
						else{
							supertiro(&tiro1, canhao);
						}
						break;
					default:
						break;
					}
				}
				
				else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
					//imprime qual tecla foi
					printf("\ncodigo tecla: %d", ev.keyboard.keycode);

					switch (ev.keyboard.keycode){
					case ALLEGRO_KEY_A:
						canhao.esq = 0;
						break;
					case ALLEGRO_KEY_D:
						canhao.dir = 0;
						break;
					default:
						break;
					}
				}
				break;


			case '3'://CASO PLAYING, O JOGO ESTA RODANDO
				//se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
				if(ev.type == ALLEGRO_EVENT_TIMER) {
		            pontos_atuais = pontuacao3(aliens3); // Atualiza a pontuação da rodada
			        if (pontos_atuais > recorde) {
                        recorde = pontos_atuais;
                    }
					//atualiza a tela (quando houver algo para mostrar)
					al_flip_display();

					amanhece(timer,&skycolor);
					//função para desenhar o cenário do game
					draw_scenario(starsX,starsY,skycolor, pontuacao3(aliens3), fonte_botoes, canhao, recorde);

					//atualiza a posição do canhao
					anda(&canhao);

					andaA3(aliens3);
					exibealien3(aliens3);
					//desenha o canhão
					exibecanhao(canhao);

					andaT(&tiro1);
					andaT(&tiro2);
				
					exibetiro(tiro1);
					exibetiro(tiro2);

					verificacolisao3(&tiro1,aliens3,&super,&canhao);
					verificacolisao3(&tiro2,aliens3,&super,&canhao);

					exibesuper(super);
					andaS(&super);
					colidesuper(&super,&canhao,cooldown1,cooldown2,cooldown3);
					verificacooldown(&canhao,cooldown1,cooldown2,cooldown3);
					

					if (perdeu3(aliens3, canhao)){
						al_flip_display();
						draw_scenario(starsX,starsY,skycolor, pontuacao3(aliens3),fonte_botoes, canhao, recorde);
						exibecanhao(canhao);
						exibealien3(aliens3);
						al_rest(3.0);
						estadodejogo = 'D';
					}
					if (pontuacao3(aliens3)==C_ALIENS3*L_ALIENS3){
						estadodejogo = 'V';
					}

					if(al_get_timer_count(timer)%(int)FPS == 0)
						printf("\n%d segundos se passaram...", (int)(al_get_timer_count(timer)/FPS));
				}
				//se o tipo de evento for o fechamento da tela (clique no x da janela)
				else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
					estadodejogo = 'E';
				}
				//se o tipo de evento for um clique de mouse
				else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);
					

				}
				//se o tipo de evento for um pressionar de uma tecla
				else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
					//imprime qual tecla foi
					printf("\ncodigo tecla: %d", ev.keyboard.keycode);

					switch (ev.keyboard.keycode){
					case ALLEGRO_KEY_A:
						canhao.esq = 1;
						break;
					case ALLEGRO_KEY_D:
						canhao.dir = 1;
						break;
					case ALLEGRO_KEY_SPACE:
						if (tiro1.ativo && canhao.super2){
							dartiro(&tiro2, canhao);
						}
						else{
							dartiro(&tiro1, canhao);
						}
						break;
					case ALLEGRO_KEY_C:
						if (tiro1.ativo && canhao.super2){
							supertiro(&tiro2, canhao);
						}
						else{
							supertiro(&tiro1, canhao);
						}
						break;
					default:
						break;
					}
				}
				
				else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
					//imprime qual tecla foi
					printf("\ncodigo tecla: %d", ev.keyboard.keycode);

					switch (ev.keyboard.keycode){
					case ALLEGRO_KEY_A:
						canhao.esq = 0;
						break;
					case ALLEGRO_KEY_D:
						canhao.dir = 0;
						break;
					default:
						break;
					}
				}
				break;
			


			default:
				break;
		}		
		al_flip_display();
	} 

    
     
	//procedimentos de fim de jogo (fecha a tela, limpa a memoria, etc)
	
    salvar_recorde(recorde);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

    al_destroy_audio_stream(musica_fundo);
    al_uninstall_audio();

	al_destroy_timer(cooldown1);
	al_destroy_timer(cooldown2);
	al_destroy_timer(cooldown3);
   
 
	return 0;
}